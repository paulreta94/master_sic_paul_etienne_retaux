CC = gcc
FLAGS = -Wall -g

all : main_bis nodes_file

main_bis : get_cpu_load_string.o get_memory_load_string.o save_cpu_stats.o save_memory_stats.o ssh_handler_bis.o main_bis.o
	$(CC) get_cpu_load_string.o get_memory_load_string.o save_cpu_stats.o save_memory_stats.o ssh_handler_bis.o main_bis.o -o main_bis

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

ssh_handler_bis.o : ssh_handler_bis.c functions.h 
	$(CC) -c ssh_handler_bis.c $(FLAGS) -o ssh_handler_bis.o

main_bis.o : main_bis.c functions.h
	$(CC) -c main_bis.c $(FLAGS) -o main_bis.o

nodes_file.o : nodes_file.c functions.h
	$(CC) -c nodes_file.c $(FLAGS) -o nodes_file.o

clean : 
	rm -f *.o
	rm -f main_bis
	rm -f nodes_file
	rm -f *.txt