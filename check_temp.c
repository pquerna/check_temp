/*
 * Standalone temperature logger
 *
 */

#include <stdio.h>
#include <time.h>
#include "pcsensor.h"

/* Calibration adjustments */
/* See http://www.pitt-pladdy.com/blog/_20110824-191017_0100_TEMPer_under_Linux_perl_with_Cacti/ */
static float scale = 1.0287;
static float offset = -0.85;

float ctof(float c) {
  float out = ((c * 9) / 5) + 32;
  return out;
}

float ctok(float c) {
  float out = c + 273.15;
  return out;
}

int main(){
	int passes = 0;
	float tempc = 0.0000;
	do {
		usb_dev_handle* lvr_winusb = pcsensor_open();

		if (!lvr_winusb) {
			/* Open fails sometime, sleep and try again */
			sleep(1);
		}
		else {
			tempc = pcsensor_get_temperature(lvr_winusb);
			pcsensor_close(lvr_winusb);
		}
		passes++;
	}
	/* Read fails silently with a 0.0 return, so repeat until not zero
	   or until we have read the same zero value 3 times (just in case
	   temp is really dead on zero */
	while ((tempc > -0.0001 && tempc < 0.0001) || passes > 3);

	if (!((tempc > -0.0001 && tempc < 0.0001) || passes > 3)) {
		/* Apply calibrations */
		tempc = (tempc * scale) + offset;
    float tempf = ctof(tempc);
    float tempk = ctok(tempc);
    printf("status Current Temp is %f %c%cF\n", tempf, 0xC2, 0xB0);
    printf("metric temperature_in_f double %f farenheit\n", tempf);
    printf("metric temperature_in_c double %f celsius\n", tempc);
    printf("metric temperature_in_k double %f kelvin\n", tempk);
		fflush(stdout);

		return 0;
	}
	else {
    printf("status err Unable to open USB device.\n");
		return 1;
	}

}
