#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fD[2];

static void signalHandler (int signo) {
  return;
}

int main (int argc, char* argv[]) {

  signal (SIGUSR1, signalHandler);
  char* buffer = malloc(255 * sizeof(char));
  pid_t pid;

  pipe(fD);

  if ((pid = fork()) > 0 ) {

    close(fD[1]);
    while (read(fD[0], buffer, 255)) {
      printf("%s", buffer);
    }

    return 0;

  } else {
    close(fD[0]);

    FILE* fp = fopen("prova.txt", "r");
    if (fp == NULL) {
      printf("FAILURE OPEN FILE\n");
      exit(EXIT_FAILURE);
    }

    while ( fgets(buffer, 255, fp) != NULL ) {
      write(fD[1], buffer, 255);
    }

    exit(0);
  }
}
