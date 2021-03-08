#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

void recursiveReader(DIR* dir, struct dirent* dp);

int main(int argc, char* argv[]) {

    DIR *dir;
    struct dirent *dp;

    if (argc != 2) {
        printf("Arguments error\n");
        exit(-1);
    }

    const char* path = argv[1];
    
    if ((dir = opendir(path)) == NULL)
        printf("opendir() Error");
    else {
        printf ("Content of the root:\n");
        recursiveReader(dir);
    } 

    closedir(dir, dp);
}

void recursiveReader(DIR* dir, struct dirent* dp) {
    if ((DIR dp = readdir(dir)) != NULL) {
        if (dp->)
            printf ("%s\n", dp->d_name);

    }
}