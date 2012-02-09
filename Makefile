# Makefile for temperature reader
CC=gcc
CFLAGS=-Wall

all: temper

temper: temper.c pcsensor.c pcsensor.h
	$(CC) $(CFLAGS) temper.c pcsensor.c -o temper -lusb

clean:
	rm temper

install:
	echo TODO!
