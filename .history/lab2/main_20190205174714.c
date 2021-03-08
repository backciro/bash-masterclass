#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {

    DIR *dir;
    struct dirent *dp;

    if (argc != 2) {
        printf("Arguments error\n");
        exit(-1);
    }

    size_t n = sizeof(argv)/sizeof(argv[0]);
    const char* path = malloc(n * sizeof(char));
    
    printf("%s\n", n);

    // if ((dir = opendir(argv[1])) == NULL)
    //     printf("opendir() Error");
    // else {
    //     printf ("Content of the root:\n");
    //     while ((dp = readdir(dir)) != NULL)
    //         printf ("%s\n", dp->d_name);
    // } 

    // closedir(dir);
}