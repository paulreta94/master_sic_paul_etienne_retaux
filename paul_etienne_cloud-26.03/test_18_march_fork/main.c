#include "functions.h"

char path[BUFFER_SIZE];

int main(void)
{
    printf("Main function is running ...\n");
    while (1)
    {
        int position_test = 0;
        int no_lines_test = 3;
        int top_priority = 0;
        // int milli_seconds = 2000;
        // int delta_t_microseconds = 400;
        float time_difference;
        pid_t pid;

        pid = fork();
        int num_pids = 3;
        if (pid != 0)
        { // we are in the super parent process and the pid is the one of the child

            if (setpriority(PRIO_PROCESS, pid, top_priority) != 0)
            {
                printf("Error setting priority of critical process\n");
                return EXIT_FAILURE;
                sleep(1);
            }
            // printf("==== Beginning ====\n");
            // while(1){
            int pids[num_pids];
            for (int i = 0; i < num_pids-1; i++)
            {
                pids[i] = fork();
                if (pids[i] == 0)
                { // child processes
                    ssh_handler(i + 1);
                    usleep(1000);
                }
                if (pids[0] != 0)
                { // parent process
                    save_cpu_stats(no_lines_test, position_test);
                    usleep(1000);
                    save_memory_stats(no_lines_test, position_test);
                    usleep(1000);
                    for (int i = 0; i < num_pids-1; i++)
                    {
                        wait(&pids[i]);
                    }
                }
            }
            // }
            // printf("==== Ending ====\n");
            // int status;
            wait(&pid);
        }

        else
        { // we are in the child process
            clock_t start_time = clock();
            printf("Child process no. %d - Reading temperature\n", getpid());
            sched_yield();
            // pid_t child_pid = getpid();
            //  looping till required time is not achieved
            sleep(2);
            // while (clock() < start_time + milli_seconds)
            // {
            // 	usleep(delta_t_microseconds);
            // }
            clock_t end_time = clock();
            time_difference = (float)(end_time - start_time) / 1000;
            printf("Time taken by the child process : %.2f s\n", time_difference);
        }
        sleep(1);
    }

    return EXIT_SUCCESS;
}