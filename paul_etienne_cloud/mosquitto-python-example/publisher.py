#!/usr/bin/env python
# -*- coding: utf-8 -*-
""" 
Publish some messages to queue
"""
import paho.mqtt.publish as publish
import socket

cpu_sum = 0
mem_sum = 0

# Get the local host name

myHostName = socket.gethostname()

# # Get the IP address of the local host

myIP = socket.gethostbyname(myHostName)


if (myIP == "192.168.1.1"):
	file1 = open('/home/pi/paul_etienne_cloud/test_18_march_fork/cpu_statistics_master.txt', 'r')
	file2 = open('/home/pi/paul_etienne_cloud/test_18_march_fork/memory_statistics_master.txt', 'r')
elif (myIP == "192.168.1.11"): # pi1 : computation node
	file1 = open('/home/pi/paul_etienne_cloud/results/cpu_192.168.1.11.txt', 'r')
	file2 = open('/home/pi/paul_etienne_cloud/results/memory_192.168.1.11.txt', 'r')
elif (myIP == "192.168.1.13"): # pi2 : computation node
	file1 = open('/home/pi/paul_etienne_cloud/results/cpu_192.168.1.13.txt', 'r')
	file2 = open('/home/pi/paul_etienne_cloud/results/memory_192.168.1.13.txt', 'r')

# while True:
for _ in range(3):
	# Get next line from file
	line1 = file1.readline()
	if (len(line1)>1):
		# print("First line : {}".format(line1))
		# counter_cpu += 1
		index1 = line1.find("ni,")
		percent_cpu = line1[index1+3:index1+8]
		percent_cpu.strip()
		#if float(percent_cpu) > 1.0:
		cpu_sum = cpu_sum + (100.0-float(percent_cpu))
	# if two consecutive lines are empty
	# end of file is reached
	if not line1:
		if not line1:
			file1.close()
			break

# while True:
for _ in range(3):
	line2 = file2.readline()
	if (len(line2)>1):
		# print("First line : {}".format(line1))
		index2 = len("MiB Mem :")
		size_total = line2[index2+1:index2+9]
		size_total.strip()
		# ypoints1.append(float(size1))
		size_free = line2[index2 + 17:index2 + 26]
		size_free.strip()
		# ypoints2.append(float(size2))
		percent_mem = float(size_free) / float(size_total) * 100
		#if float(percent_mem) > 1.0:
		mem_sum = mem_sum + percent_mem
		# counter_mem += 1
	# if two consecutive lines are empty
	# end of file is reached
	if not line2:
		if not line2:
			file2.close()
			break

cpu_score = str(cpu_sum/3) + " "
mem_score = str(mem_sum/3)
score = cpu_score + mem_score
print("Score : {}".format(score))
if myIP == "192.168.1.11":
	# stats1 = open('/home/pi/paul_etienne_cloud/mosquitto-python-example/stats1.txt','r+')
	msgs = [{'topic': "performances/pi1", 'payload': score}]
	# stats1.write(score)

elif myIP == "192.168.1.13":
	# stats2 = open('/home/pi/paul_etienne_cloud/mosquitto-python-example/stats2.txt','r+')
	msgs = [{'topic': "performances/pi2", 'payload': score}]
	# stats2.write(score)


# host = "localhost"
master = "192.168.1.1"


if __name__ == '__main__':
    publish.multiple(msgs, hostname=master)
	
# vi: set fileencoding=utf-8 :
