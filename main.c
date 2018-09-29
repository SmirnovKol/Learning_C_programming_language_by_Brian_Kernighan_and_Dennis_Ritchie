#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "syscall.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"

void fsize(char *);

// print filenames
int main(int argc, char **argv)
{
    if (argc == 1)  // default: current directory
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}
