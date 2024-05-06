#!/usr/bin/env python
# -*- coding: utf-8 -*-
# """
# A small example subscriber
# """
# import paho.mqtt.client as paho
# import os

"""
A small example subscriber
"""
import paho.mqtt.client as paho
import os

host_lines = ["",""]

def on_message(mosq, obj, msg):
    host = open("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt",'w')
    global host_lines
    print("%-20s %d %s" % (msg.topic, msg.qos, msg.payload))
    if msg.topic == "performances/pi1": 
        perf_list = msg.payload.split()
        cpu_load = float(perf_list[0])
        mem_load = float(perf_list[1])
        score = (cpu_load + mem_load)/2
        stats1 = open('/home/pi/paul_etienne_cloud/mosquitto-python-example/stats1.txt','r+')
        stats1.write(str(score))
        stats1.close()
        print("Score : {}".format(score))
        if score <= 25.0:
            token_pi1 = "pi1 : slots = 3\n"
        elif score <= 50.0:
            token_pi1 = "pi1 : slots = 2\n"
        elif score <= 75.0:
            token_pi1 = "pi1 : slots = 1\n"
        else:
            token_pi1 = "pi1 : slots = 0\n"
        host_lines[0] = token_pi1
    elif msg.topic == "performances/pi2": 
        perf_list = msg.payload.split()
        cpu_load = float(perf_list[0])
        mem_load = float(perf_list[1])
        score = (cpu_load + mem_load)/2
        stats2 = open('/home/pi/paul_etienne_cloud/mosquitto-python-example/stats1.txt','r+')
        stats2.write(str(score))
        stats2.close()
        print("Score : {}".format(score))
        if score <= 25.0:
            token_pi2 = "pi2 : slots = 3\n"
        elif score <= 50.0:
            token_pi2 = "pi2 : slots = 2\n"
        elif score <= 75.0:
            token_pi2 = "pi2 : slots = 1\n"
        else:
            token_pi2 = "pi2 : slots = 0\n"
        host_lines[1] = token_pi2
    if (len(host_lines[0]) > 0) and (len(host_lines[1]) > 0):
        host.writelines(host_lines)
    host.close()
    mosq.publish('pong', 'ack', 0)


def on_publish(mosq, obj, mid):
    pass

if __name__ == '__main__':
    client = paho.Client()
    client.on_message = on_message
    client.on_publish = on_publish
    master = "192.168.1.1"
    client.connect(master, 1883, 60)

    client.subscribe("performances/pi1", 0)
    client.subscribe("performances/pi2", 0)

    while client.loop() == 0:
        pass

# vi: set fileencoding=utf-8 :
