#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

void recursiveReader(DIR* dir);

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

    closedir(dir);
}

void recursiveReader(DIR* dp) {
    while ((dp = readdir(dir)) != NULL)
            printf ("%s\n", dp->d_name);
}