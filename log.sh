#!/bin/bash

while [ 1 ]
do
    echo `date +"%F %T"`,`./temper`
    sleep 5s
done
