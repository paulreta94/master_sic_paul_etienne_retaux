This folder is the one where three different tasks are handled :
	1) retrieving resources' statistics of the nodes thanks to get_xxx_load_string.c and save_xxx_stats.c
		Remark : these C files are executed both on the master and on the slaves. Executing them on the slaves is performed thanks to the "nodes_file.c" 
	2) opening Secure SHell (SSH) connections towards slaves thanks to the "ssh_handler.c" file
	3) simulating the execution of a critical task (here : writing the time but in reality : writing the temperature).
The "main.c" file schedules the execution of the tasks by using child and parent processes.
