#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main (int argc, char *argv[])
{
     FILE * fp;

   fp = fopen (argv[1], "r");
    struct stat attrib;
    stat(argv[1], &attrib);
    char time[50];
    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&attrib.st_mtime));
     printf ("FILE: %s TIME: %s\n", argv[1], time);
fclose(fp);
}
