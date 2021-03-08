#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char* argv) {

    DIR *dir;
    dir = opendir(argv[1]);
    struct dirent *dp;

    if (argc != 2) {
        printf("Arguments error");
        exit(-1);
    }

    if ((dir = opendir(&argv[1])) == NULL)
        printf("opendir() Error");
    else {
        printf ("Content of the root:\n");
        while ((dp = readdir (dir))!= NULL)
            printf ("%s\n", dp->d_name);
    } 

    closedir(dir);
}