#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char* argv) {
    DIR *dir;
    dir = opendir(argv[1]);
    struct dirent *dp;

    if ((dir = opendir (argv[1]) == NULL))
        printf("opendir() Error");

    else {
        printf (“Content of the root:\n”
        int closedir (DIR *dir);

    }
}