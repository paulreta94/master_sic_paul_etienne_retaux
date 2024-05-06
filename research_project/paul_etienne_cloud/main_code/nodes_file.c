#include "functions.h"

int main(void)
{   
    char path[BUFFER_SIZE];
    fprintf(stdout, "Current working directory: %s\n", getcwd(path, BUFFER_SIZE));
    if (getcwd(path, BUFFER_SIZE) == NULL)
        {
            fprintf(stderr, "Cannot get current working directory path\n");
            if (errno == ERANGE)
            {
                fprintf(stderr, "Buffer size is too small.\n");
            }
            exit(EXIT_FAILURE);
        }
        int position_test = 1; // position of slave
        int no_lines_test = 3;
    while (1)
    {      
        
        save_cpu_stats(no_lines_test, position_test);
        save_memory_stats(no_lines_test, position_test);
        sleep(1);
    }
    return EXIT_SUCCESS;
}