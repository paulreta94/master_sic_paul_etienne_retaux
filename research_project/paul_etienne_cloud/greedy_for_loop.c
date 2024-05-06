#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*This file is a "greedy task", which loads CPUs of every RPi with a load evolving during the time*/
int main(void)
{
    int rest_time = 1000000;
    int flag = 0;
    printf("Critical task is running\n");
    while (1)
    {
        int count = 0;
        for (int i = 0; i <= 1000; i++)
        {
            count++;
        }
        // printf("Greedy loop is going to sleep for %d s.\n",rest_time);
        usleep(rest_time);
        // printf("Greedy loop just woke up\n");
        flag++;
        /*if(flag==1){
            flag = 0;
            system("clear");
        }*/
    }
    return EXIT_SUCCESS;
}
