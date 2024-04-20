#!/bin/bash
cd mosquitto-python-example
source bin/activate
while true 
do 
	./publisher.py
	sleep 0.5
done
