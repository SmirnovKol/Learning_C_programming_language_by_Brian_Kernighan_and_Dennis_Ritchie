#include <sys/dir.h>  // local directory structure

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct {
    ino_t d_ino;
    char d_name[DIRSIZ];
};

// read directory entries in sequence
dirent *readdir(DIR *dp)
{
    struct direct dirbuf;
    static dirent d;

    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
                == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0)  // slot not in use
            continue;
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';
        return &d;
    }
    return NULL;
}
