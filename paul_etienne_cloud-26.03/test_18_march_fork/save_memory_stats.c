#include "functions.h"

void save_memory_stats(int number_of_lines, int state)
{
    char path[BUFFER_SIZE];
    if (!state)
    { // master's code
        if (getcwd(path, BUFFER_SIZE) == NULL)
        {
            fprintf(stderr, "Cannot get current working directory\n");
            if (errno == ERANGE)
            {
                fprintf(stderr, "Buffer size is too small.\n");
            }
            exit(EXIT_FAILURE);
        }
        strcat(path, "/memory_statistics_master.txt");
        // printf("Path to master's memory file : %s\n\n", path);
        FILE *fid = fopen(path, "w+");
        if (fid == NULL)
        {
            printf("Error opening Master's CPU statistics' file : %d\n", errno);
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < number_of_lines + 1; i++)
        {
            if (fprintf(fid, "%s\n", getMemoryLoadString()) < 0)
            {
                printf("Error saving CPU statistics of master\n");
                exit(EXIT_FAILURE);
            };
            sleep(1);
        }
        fclose(fid);
        printf("\nMaster's CPU statistics successfully saved\n");
    }
    else
    {
        char hostbuffer[MIN_SIZE];
        struct hostent *host_entry;
        int hostname;
        char *IPbuffer;
        hostname = gethostname(hostbuffer, sizeof(hostbuffer));
        if (hostname == -1)
        {
            perror("gethostname");
            exit(EXIT_FAILURE);
        }
        host_entry = gethostbyname(hostbuffer);
        if (host_entry == NULL)
        {
            perror("gethostbyname");
            exit(EXIT_FAILURE);
        }
        IPbuffer = inet_ntoa(*((struct in_addr *)host_entry->h_addr_list[0]));
        if (getcwd(path, BUFFER_SIZE) == NULL)
        {
            fprintf(stderr, "Cannot get current working directory\n");
            if (errno == ERANGE)
            {
                fprintf(stderr, "Buffer size is too small.\n");
            }
            exit(EXIT_FAILURE);
        }
        char file_name[BUFFER_SIZE];
        sprintf(file_name, "/paul_etienne_cloud/results/memory_%s.txt", IPbuffer);
        // sprintf(file_name, "/memory_%s.txt", IPbuffer);
        strcat(path, file_name);
        // printf("Path to slave's memory file : %s\n\n", path);
        FILE *fid = fopen(path, "w+");
        if (fid == NULL)
        {
            printf("Error opening slave's memory statistics' file : %d\n", errno);
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < number_of_lines + 1; i++)
        {
            if (fprintf(fid, "%s\n", getMemoryLoadString()) < 0)
            {
                printf("Error saving memory statistics of slave\n");
                exit(EXIT_FAILURE);
            };
            sleep(1);
        }
        fclose(fid);
        printf("\nSlave's memory statistics successfully saved\n");
    }
    // exit(EXIT_SUCCESS);
}