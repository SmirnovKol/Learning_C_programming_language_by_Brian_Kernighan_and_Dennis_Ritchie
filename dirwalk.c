#include <dirent.h>

#define MAX_PATH 1024
#define NAME_MAX 14

typedef struct {
    long ino;
    char name[NAME_MAX + 1];
} dirent;

typedef struct {
    int fd;
    dirent d;
} DIR;

DIR *opendir(const char *dirname);
dirent *readdir(DIR *dp);
void closedir0925(DIR *dp);

// apply fcn to all files in dir
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0
            || strcmp(dp->d_name, "..") == 0)
            continue;       // skip self and parent
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s %s too long\n",
                    dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir0925(dfd);
}
