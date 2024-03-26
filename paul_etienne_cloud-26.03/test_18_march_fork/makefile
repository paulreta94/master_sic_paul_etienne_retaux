CC = gcc
FLAGS = -Wall -Werror -g

all : main nodes_file

main : get_cpu_load_string.o get_memory_load_string.o save_cpu_stats.o save_memory_stats.o ssh_handler.o main.o
	$(CC) get_cpu_load_string.o get_memory_load_string.o save_cpu_stats.o save_memory_stats.o ssh_handler.o main.o -o main

nodes_file : get_cpu_load_string.o get_memory_load_string.o save_cpu_stats.o save_memory_stats.o nodes_file.o
	$(CC) get_cpu_load_string.o get_memory_load_string.o save_cpu_stats.o save_memory_stats.o nodes_file.o -o nodes_file

get_cpu_load_string.o : get_cpu_load_string.c functions.h
	$(CC) -c get_cpu_load_string.c $(FLAGS) -o get_cpu_load_string.o

get_memory_load_string.o : get_memory_load_string.c functions.h
	$(CC) -c get_memory_load_string.c $(FLAGS) -o get_memory_load_string.o

save_cpu_stats.o : save_cpu_stats.c functions.h
	$(CC) -c save_cpu_stats.c $(FLAGS) -o save_cpu_stats.o

save_memory_stats.o : save_memory_stats.c functions.h
	$(CC) -c save_memory_stats.c $(FLAGS) -o save_memory_stats.o

ssh_handler.o : ssh_handler.c functions.h 
	$(CC) -c ssh_handler.c $(FLAGS) -o ssh_handler.o

main.o : main.c functions.h
	$(CC) -c main.c $(FLAGS) -o main.o

nodes_file.o : nodes_file.c functions.h
	$(CC) -c nodes_file.c $(FLAGS) -o nodes_file.o

clean : 
	rm -f *.o
	rm -f main
	rm -f nodes_file
	rm -f *.txt