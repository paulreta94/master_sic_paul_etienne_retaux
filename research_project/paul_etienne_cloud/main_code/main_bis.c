#include "functions.h"

char path[BUFFER_SIZE];

int main(void)
{
    // int status, pipedes[2];
    // char buf[100];
    // // int len;
    // char msg[] = "Salut Fred !";
    // if (pipe(pipedes))
    //     exit(1);
    // if (fork())
    // { /* Code du pere */
    //     printf("père\n");
    //     write(pipedes[1], msg, strlen(msg));
    //     printf("ok, envoyé\n");
    //     wait(&status);
    //     return 0;
    // }
    // else
    // { /* Code du fils */
    //     printf("fils\n");
    //     read(pipedes[0], buf, 100);
    //     printf("Mon pere adore l'art de decaler les sons : %s\n", buf);
    //     return 0;

        // while (1)
        // {
            // int position_test = 0;
            // int no_lines_test = 3;
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
                // sleep(1);
                for (int i = 0; i < num_childPids - 1; i++)
                {
                    childPids[i] = fork(); // table of size 3
                    // pid_t pid;
                    // pid = fork();
                    if (childPids[i] == 0)
                    { // child processes
                    fprintf(stdout, "Child process %d\n", i + 1);
                        ssh_handler(i + 1);
                    }
                    // else
                    // { // parent process
                    //     int status;
                    //     wait(&status);
                    // }
                }
                // int status;
                // wait(&status);
                // we are in the child process
                // clock_t start_time = clock();
                
                struct timeval tv;
                struct timezone tz;
                struct tm *today;
                FILE *fid = fopen("/home/pi/paul_etienne_cloud/test_18_march_fork/critical_task.txt", "w+");
                char buffer[100];
            while (1){
                gettimeofday(&tv, &tz);

                /* get time details */
                // usleep(10000);
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
                // fprintf(xxx, "Today is : %d:%0d:%0d.%ld\n",
                //        today->tm_hour,
                //        today->tm_min,
                //        today->tm_sec,
                //        tv.tv_usec);
                sprintf(buffer, "Today is : %d:%0d:%0d.%ld\n",
                       today->tm_hour,
                       today->tm_min,
                       today->tm_sec,
                       tv.tv_usec);
                fwrite(buffer, sizeof(char), strlen(buffer), fid);
                fflush(fid);
            }
                fclose(fid);
                // sched_yield();
            }

            // clock_t end_time = clock();
            // time_difference = (float)(end_time - start_time) / 1000;
            // printf("Time taken by the child process : %.2f s\n", time_difference);
        // }
        // sleep(1);
        // wait(NULL);
        // if detected ctrl+c signal, we should kill the child process
        // for (int i = 0; i < num_childPids - 1; i++)
        // {
        //     printf("Killing child process %d\n", i + 1);
        //     kill(childPids[i], SIGKILL);
        // }
    
        return EXIT_SUCCESS;
    }
}