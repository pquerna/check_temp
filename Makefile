# Makefile for temperature reader
CC=gcc
CFLAGS=-Wall

all: temper

temper: 
	$(CC) $(CFLAGS) temper.c pcsensor.c -o temper -lusb

clean:
	rm *.o temper

install:
	echo TODO!
