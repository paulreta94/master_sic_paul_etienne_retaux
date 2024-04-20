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
    # print("No. of lines : %d" % len(host.readlines()))
    # host_lines = host.readlines()
    # num_lines = len(host_lines)
    # if (num_lines > 2):
    #     print("Hurrah")
    #     host.close()
    #     os.remove("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt")
    #     host = open("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt",'w') # overwriting the content of the file
    #     # host.write(" ")
    #     # host.close()
    #     # host = open("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt",'a') # opening it in append mode
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
            # host.write("pi1 : slots = 3\n")
        elif score <= 50.0:
            token_pi1 = "pi1 : slots = 2\n"
            # host.write("pi1 : slots = 2\n")
        elif score <= 75.0:
            token_pi1 = "pi1 : slots = 1\n"
            # host.write("pi1 : slots = 1\n")
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
            # host.write("pi2 : slots = 3\n")
        elif score <= 50.0:
            token_pi2 = "pi2 : slots = 2\n"
            # host.write("pi2 : slots = 2\n")
        elif score <= 75.0:
            token_pi2 = "pi2 : slots = 1\n"
            # host.write("pi2 : slots = 1\n")
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
    # client = paho.Client(paho.CallbackAPIVersion.VERSION2)
    client.on_message = on_message
    client.on_publish = on_publish

    #client.tls_set('root.ca', certfile='c1.crt', keyfile='c1.key')
    master = "192.168.1.1"
    # pi1 = "192.168.1.11"
    # pi2 = "192.168.1.13"
    # client.connect("127.0.0.1", 1883, 60)
    # client.connect("mqtt.eclipseprojects.io", 1883, 60)
    client.connect(master, 1883, 60)
    # client.connect("10.10.4.160", 22)

    client.subscribe("performances/pi1", 0)
    client.subscribe("performances/pi2", 0)
    # client.subscribe("performances/cpu/pi1", 0)
    # client.subscribe("performances/mem/pi1", 0)
    # client.subscribe("performances/cpu/pi2", 0)
    # client.subscribe("performances/mem/pi2", 0)

    while client.loop() == 0:
        pass

# def on_message(mosq, obj, msg):
#     host = open("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt",'r+')
#     # print("No. of lines : %d" % len(host.readlines()))
#     host_lines = host.readlines()
#     num_lines = len(host_lines)
#     if (num_lines > 2):
#         print("Hurrah")
#         host.close()
#         os.remove("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt")
#         host = open("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt",'w') # overwriting the content of the file
#         # host.write(" ")
#         # host.close()
#         # host = open("/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/hostfile.txt",'a') # opening it in append mode
#     print("%-20s %d %s" % (msg.topic, msg.qos, msg.payload))
#     if msg.topic == "performances/pi1": 
#         perf_list = msg.payload.split()
#         cpu_load = float(perf_list[0])
#         mem_load = float(perf_list[1])
#         score = (cpu_load + mem_load)/2
#         print("Score : {}".format(score))
#         if score <= 25.0:
#             host.write("pi1 : slots = 3\n")
#         elif score <= 50.0:
#             host.write("pi1 : slots = 2\n")
#         elif score <= 75.0:
#             host.write("pi1 : slots = 1\n")
#         else:
#             host.write("pi1 : slots = 0\n")
#     elif msg.topic == "performances/pi2": 
#         perf_list = msg.payload.split()
#         cpu_load = float(perf_list[0])
#         mem_load = float(perf_list[1])
#         score = (cpu_load + mem_load)/2
#         print("Score : {}".format(score))
#         if score <= 25.0:
#             host.write("pi2 : slots = 3\n")
#         elif score <= 50.0:
#             host.write("pi2 : slots = 2\n")
#         elif score <= 75.0:
#             host.write("pi2 : slots = 1\n")
#         else:
#             host.write("pi2 : slots = 0\n")
#     host.close()
#     mosq.publish('pong', 'ack', 0)


# def on_publish(mosq, obj, mid):
#     pass

# if __name__ == '__main__':
#     client = paho.Client()
#     # client = paho.Client(paho.CallbackAPIVersion.VERSION2)
#     client.on_message = on_message
#     client.on_publish = on_publish

#     #client.tls_set('root.ca', certfile='c1.crt', keyfile='c1.key')
#     master = "192.168.1.1"
#     # pi1 = "192.168.1.11"
#     # pi2 = "192.168.1.13"
#     # client.connect("127.0.0.1", 1883, 60)
#     # client.connect("mqtt.eclipseprojects.io", 1883, 60)
#     client.connect(master, 1883, 60)
#     # client.connect("10.10.4.160", 22)

#     client.subscribe("performances/pi1", 0)
#     client.subscribe("performances/pi2", 0)
#     # client.subscribe("performances/cpu/pi1", 0)
#     # client.subscribe("performances/mem/pi1", 0)
#     # client.subscribe("performances/cpu/pi2", 0)
#     # client.subscribe("performances/mem/pi2", 0)

#     while client.loop() == 0:
#         pass

# vi: set fileencoding=utf-8 :
