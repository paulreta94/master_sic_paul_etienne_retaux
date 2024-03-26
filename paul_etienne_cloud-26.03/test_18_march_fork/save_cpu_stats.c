#include "functions.h"
// extern char path_slave[BUFFER_SIZE];

void save_cpu_stats(int no_lines, int position)
{
    char path[BUFFER_SIZE];
    if (position == 0)
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
        strcat(path, "/cpu_statistics_master.txt");
        // printf("Path to master's CPU file : %s\n\n", path);
        FILE *fid = fopen(path, "w+");
        if (fid == NULL)
        {
            printf("Error opening Master's CPU statistics' file : %d\n", errno);
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < no_lines + 1; i++)
        {
            if (fprintf(fid, "%s\n", getCpuLoadString()) < 0)
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
    { // state = 1 : slave's code
        // char path[BUFFER_SIZE];
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
        if ( getcwd( path, BUFFER_SIZE ) == NULL ) {
            fprintf( stderr, "Cannot get current working directory\n" );
            if ( errno == ERANGE ) {
                fprintf( stderr, "Buffer size is too small.\n" );
            }
        exit( EXIT_FAILURE );
        }
        char file_name[BUFFER_SIZE];
        sprintf(file_name, "/paul_etienne_cloud/results/cpu_%s.txt", IPbuffer);
        // sprintf(file_name, "/cpu_%s.txt", IPbuffer);
        strcat(path, file_name);
        // printf("Path to slave's CPU file : %s\n\n", path);
        FILE *fid = fopen(path, "w+");
        if (fid == NULL)
        {
            printf("Error opening Slave's CPU statistics' file : %d\n", errno);
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < no_lines + 1; i++)
        {
            if (fprintf(fid, "%s\n", getCpuLoadString()) < 0)
            {
                printf("Error saving CPU statistics of slave\n");
                exit(EXIT_FAILURE);
            };
            sleep(1);
        }
        fclose(fid);
        printf("\nCPU statistics of slave %s successfully saved\n",IPbuffer);
    }
    // exit(EXIT_SUCCESS);
}