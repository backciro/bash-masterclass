#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void recursiveReader(DIR* dir, struct dirent* dp, const char* path);

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
        recursiveReader(dir, dp, path);
    } 

    closedir(dir);
}

void recursiveReader(DIR* dir, struct dirent* dp, const char* path) {
    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_type == DT_DIR && (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) ) {
            printf ("\n\nDIRETTORIO: %s\n", dp->d_name);
            recursiveReader(opendir(strcat(path, dp->d_name)), dp, path);
        } else {
            printf ("FILE: %s\n", dp->d_name);
            recursiveReader(dir, dp, path);
        }
    }
}