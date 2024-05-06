#!/bin/bash
#This file activates the Python virtual environment and executes the publisher every 0.5 second
cd mosquitto_code
source bin/activate
while true 
do 
	./publisher.py
	sleep 0.5
done
