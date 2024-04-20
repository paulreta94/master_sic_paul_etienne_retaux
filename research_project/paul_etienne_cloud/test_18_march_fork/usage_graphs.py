# import matplotlib.pyplot as plt
# import numpy as np

xpoints1 = [1,2,3,4,5]
ypoints1 = []

xpoints2 = [1,2,3,4,5]
ypoints2 = []

file1 = open('cpu_statistics_master.txt', 'r')
file2 = open('/home/pi/paul_etienne_cloud/results/cpu_192.168.1.15.txt','r')

while True:

	# Get next line from file
	line1 = file1.readline()
	if (len(line1)>1):
		print("First line : {}".format(line1))
		index1 = line1.find("ni,")
		percent1 = line1[index1+3:index1+8]
		percent1.strip()
		ypoints1.append(100-float(percent1))
	# if two consecutive lines are empty
	# end of file is reached
	if not line1:
		if not line1:
			break
	
	
    # Get next line from file
	# line2 = file2.readline()
	# # line2 = file2.readline() 
	# # line.strip()
	# # if two consecutive lines are empty
	# # end of file is reached
	# # if not line2:
	# 	# if not line2:
	# 		# break
	# index2 = line2.find("ni,")
	# percent2 = line2[index2+3:index2+8]
	# # percent1.replace(" ","")
	# percent2.strip()
	# # print("Index : {}".format(index))
	# # print("Line : {}".format(line))
	# # print("CPU Usage: {}".format(percent))
	# # ypoints2.append(float(percent2))
file1.close()
file2.close()
print("CPU Usage list : {}".format(ypoints1))
# print("CPU Usage list : {}".format(ypoints2))
# plt.plot(xpoints1, ypoints1)
# plt.plot(xpoints2,ypoints2)
# plt.show()