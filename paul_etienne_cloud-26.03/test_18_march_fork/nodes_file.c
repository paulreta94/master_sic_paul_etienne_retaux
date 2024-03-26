#include "functions.h"

int main(void)
{
    char path[BUFFER_SIZE];
    // char msg[MAX_SIZE];
    if (getcwd(path, BUFFER_SIZE) == NULL)
    {
        fprintf(stderr, "Cannot get current working directory path\n");
        if (errno == ERANGE)
        {
            fprintf(stderr, "Buffer size is too small.\n");
        }
        exit(EXIT_FAILURE);
    }
    int position_test = 1;
    int no_lines_test = 3;
    save_cpu_stats(no_lines_test, position_test);
    save_memory_stats(no_lines_test, position_test);
    // sprintf(msg, "Back to M: %s\n", path);
    // printf("Back to master : %s\n",path);
    // if (execlp("ssh", "ssh", "master", path, (char *)NULL) != 0)
    // {
    //     printf("Failed to return back to master's session\n");
    //     return EXIT_FAILURE;
    // }
    // execlp("exit", "exit", (char *)NULL);
    return EXIT_SUCCESS;
}