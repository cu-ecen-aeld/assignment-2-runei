#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER);
    if (argc != 3)
    {
        syslog(LOG_ERR, "Wrong number of arguments");
        exit(1);
    }
    char *writefile = argv[1];
    char *writestr = argv[2];
    
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL)
    {
        syslog(LOG_ERR, "Failed to create file");
        exit(1);
    }
    fprintf(fp, "%s\n", writestr);
    fclose(fp);
    
    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, writefile);
    
    syslog(LOG_INFO, "File created\n");
    closelog();
    
    printf("File created: %s\n", writefile);
    return 0;
}
