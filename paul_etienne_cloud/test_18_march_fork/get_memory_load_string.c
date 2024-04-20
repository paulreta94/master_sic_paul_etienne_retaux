#include "functions.h"

char *getMemoryLoadString()
{
    /*
     * Easiest seems to be just to read out a line from top, rather than trying to calc it ourselves through /proc stuff
     */
    static int started = 0;
    static char buffer[1024];
    static char lastfullline[256];
    static int bufdx;
    static FILE *fp;

    if (!started)
    {
        /* Start the top command */
        /* Open the command for reading. */
        fp = popen("top -b -d 0.1 -n1", "r");
        if (fp == NULL)
        {
            printf("Failed to run top command for profiling\n");
            exit(1);
        }

        /* Make nonblocking */
        int flags;
        flags = fcntl(fileno(fp), F_GETFL, 0);
        flags |= O_NONBLOCK;
        fcntl(fileno(fp), F_SETFL, flags);

        started = 1;
    }

    /*
     * Read out the latest info, and remember the last full line
     */
    while (fgets(buffer + bufdx, sizeof(buffer) - bufdx, fp) != NULL)
    // while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        /* New data came in. Iteratively shift everything until a newline into the last full line */
        char *newlinep;
        while ((newlinep = strstr(buffer, "\n")))
        {
            int shiftsize = (newlinep - buffer + 1);
            *newlinep = 0; /* Nullterminate it for strcpy and strstr */
            /* Check if the line contained "cpu" */
            if (strstr(buffer, "buff/cache"))
            {
                strncpy(lastfullline, buffer, sizeof(lastfullline) - 1); /* Copy full line if it contained cpu info */
            }
            memmove(buffer, buffer + shiftsize, shiftsize); /* Shift left (and discard) the line we just consumed */
        }
    }
    /*
     * Return the last line we processed as valid output
     */
    return lastfullline;
    pclose(fp);
}