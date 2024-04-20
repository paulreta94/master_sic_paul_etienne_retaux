#include "functions.h"

void ssh_handler(int node_ID)
{
    char path[BUFFER_SIZE];
    if (getcwd(path, BUFFER_SIZE) == NULL)
    {
        fprintf(stderr, "Cannot get current working directory path\n");
        if (errno == ERANGE)
        {
            fprintf(stderr, "Buffer size is too small.\n");
        }
        exit(EXIT_FAILURE);
    }
    strcat(path, "/nodes_file");

    return 0;
    // printf("Path to slave's executable : %s\n", path);
    if (node_ID == 1)
    {
        if (execlp("ssh", "ssh", "pi1", path, (char *)NULL) != 0)
        {
            printf("Failed to execute SSH opening session command for pi1\n");
            exit(EXIT_FAILURE);
        }
    }
    if (node_ID == 2)
    {
        if (execlp("ssh", "ssh", "pi2", path, (char *)NULL) != 0)
        {
            printf("Failed to execute SSH opening session command for pi2\n");
            exit(EXIT_FAILURE);
        }
    }
    if (node_ID == 3)
    {
        if (execlp("ssh", "ssh", "pi3", path, (char *)NULL) != 0)
        {
            printf("Failed to execute SSH opening session command for pi3\n");
            exit(EXIT_FAILURE);
        }
    }
    if (node_ID == 4)
    {
        if (execlp("ssh", "ssh", "pi4", path, (char *)NULL) != 0)
        {
            printf("Failed to execute SSH opening session command for pi4\n");
            exit(EXIT_FAILURE);
        }
    }
}