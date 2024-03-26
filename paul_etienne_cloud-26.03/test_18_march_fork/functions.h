#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sched.h>		  // sched_yield()
#include <time.h>		  // clock()
#include <sys/resource.h> // setpriority

#define MAX_SIZE 512
#define MIN_SIZE 20
// extern int file_size;
#define BUFFER_SIZE 128

char *getCpuLoadString(void);
char *getMemoryLoadString(void);
void save_memory_stats(int , int);
void save_cpu_stats(int ,int );
void ssh_handler(int);
int find_IP_address(void);

// extern char path[BUFFER_SIZE];
// extern char* IPbuffer;
// extern int state;