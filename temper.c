/*
 * Standalone temperature logger
 *
 */

#include "pcsensor.h"

int main(){
	usb_dev_handle* lvr_winusb = pcsensor_open();
	if (!lvr_winusb) 
		return -1;

	float tempc = pcsensor_get_temperature(lvr_winusb);
	pcsensor_close(lvr_winusb);
	printf("%f\n", tempc);

	return 0;
}
