//#include <sys/types.h>
//#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

// close directory opened by opendir
void closedir0925(DIR *dp)
{
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}

