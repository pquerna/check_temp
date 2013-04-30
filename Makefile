# Makefile for temperature reader
CC=gcc
CFLAGS=-Wall

all: temper check_temp

temper: temper.c pcsensor.c pcsensor.h
	$(CC) $(CFLAGS) temper.c pcsensor.c -o temper -lusb

check_temp: check_temp.c pcsensor.c pcsensor.h
	$(CC) $(CFLAGS) check_temp.c pcsensor.c -o check_temp -lusb

clean:
	rm temper check_temp

install:
	echo TODO!
