#include "functions.h"

char path[BUFFER_SIZE];
/*This file is divided into two parts : 
    1) The super parent process, which sets the priority of his child to be the user-highest one (0)
    2) The super child process has got itself two children which open SSH connections. Besides, it executes the critical task, i.e. periodically writing the date in the critical_task.txt file*/
int main(void)
{
    int top_priority = 0;
    pid_t superChildPid;
    int num_childPids = 3;
    pid_t childPids[num_childPids];

    superChildPid = fork();

    if (superChildPid != 0)
    { // we are in the super parent process and the pid is the one of the child

        if (setpriority(PRIO_PROCESS, superChildPid, top_priority) != 0)
        {
            switch (errno)
            {
            case EACCES:
                printf("Error : the current process does not have the appropriate privilege\n");
                break;
            case EINVAL:
                printf("Error : the value of the who argument is not a valid process ID\n");
                break;
            case ESRCH:
                printf("No such process could be located\n");
                break;
            }
            return EXIT_FAILURE;
            int super_status;
            wait(&super_status);
        }
        else
        {
            for (int i = 0; i < num_childPids - 1; i++)
            {
                childPids[i] = fork(); // table of size 3
                if (childPids[i] == 0)
                { // child processes
                    fprintf(stdout, "Child process %d\n", i + 1);
                    ssh_handler(i + 1);
                }
            }

            struct timeval tv;
            struct timezone tz;
            struct tm *today;
            FILE *fid = fopen("/home/pi/paul_etienne_cloud/main_code/critical_task.txt", "w+");
            char buffer[100];
            while (1)
            {
                gettimeofday(&tv, &tz);
                sleep(1);
                today = localtime(&tv.tv_sec);
                printf("Today is %d:%0d:%0d.%ld\n",
                       today->tm_hour,
                       today->tm_min,
                       today->tm_sec,
                       tv.tv_usec);

                if (fid == NULL)
                {
                    printf("Error opening critical task's file : %d\n", errno);
                    exit(EXIT_FAILURE);
                }
                sprintf(buffer, "Today is : %d:%0d:%0d.%ld\n",
                        today->tm_hour,
                        today->tm_min,
                        today->tm_sec,
                        tv.tv_usec);
                fwrite(buffer, sizeof(char), strlen(buffer), fid);
                fflush(fid);
            }
            fclose(fid);
        }
        return EXIT_SUCCESS;
    }
}