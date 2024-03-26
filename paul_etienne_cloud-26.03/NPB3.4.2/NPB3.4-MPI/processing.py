import matplotlib.pyplot as plt
# fig, ax = plt.subplots()

cpu_time_list_1 = []
cpu_time_list_2 = []
cpu_time_list_3 = []
cpu_time_list_4 = []
iterations_list = [j+1 for j in range(10)]

for i in range(1,11):
    file_name = '/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/results/result' + str(i) + '.txt'
    file = open(file_name)
    lines_list = file.readlines()
    cpu_line = lines_list[8]
    cpu_time = float(cpu_line[15:])
    cpu_time_list_1.append(cpu_time)
    file.close()
for i in range(11,21):
    file_name = '/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/results/result' + str(i) + '.txt'
    file = open(file_name)
    lines_list = file.readlines()
    cpu_line = lines_list[8]
    cpu_time = float(cpu_line[15:])
    cpu_time_list_2.append(cpu_time)
    file.close()
for i in range(21,31):
    file_name = '/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/results/result' + str(i) + '.txt'
    file = open(file_name)
    lines_list = file.readlines()
    cpu_line = lines_list[8]
    cpu_time = float(cpu_line[15:])
    cpu_time_list_3.append(cpu_time)
    file.close()
for i in range(31,41):
    file_name = '/home/pi/paul_etienne_cloud/NPB3.4.2/NPB3.4-MPI/results/result' + str(i) + '.txt'
    file = open(file_name)
    lines_list = file.readlines()
    cpu_line = lines_list[8]
    cpu_time = float(cpu_line[15:])
    cpu_time_list_4.append(cpu_time)
    file.close()

plt.ylim(0,1.5)
plt.plot(iterations_list, cpu_time_list_1, 'r--', label='NO Broker, NO Critical Task')
plt.plot(iterations_list, cpu_time_list_2, 'r', label='NO Broker, Critical Task')
plt.plot(iterations_list, cpu_time_list_3, 'b--', label = 'Broker, NO Critical Task')
plt.plot(iterations_list, cpu_time_list_4, 'b', label='Broker, Critical Task')
# --------------------------------------------- #
plt.xlabel("Number of the iteration", fontsize = 'x-large')
plt.ylabel("CPU time (seconds)", fontsize = 'x-large')

# legend = ax.legend(loc='upper center', shadow=True, fontsize='x-large')
legend = plt.legend(loc = 'upper left', shadow=True, fontsize = 'x-large')

# Put a nicer background color on the legend.
legend.get_frame().set_facecolor('C0')

plt.show()