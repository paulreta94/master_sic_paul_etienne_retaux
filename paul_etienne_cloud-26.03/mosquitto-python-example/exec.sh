#!/bin/bash
cd mosquitto-python-example
source bin/activate
while true 
do 
	./publisher.py
	sleep 1
done
