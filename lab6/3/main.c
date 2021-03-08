#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void signHandler(int signo) {
  if (signo == SIGCHLD) {
    return;
  }
}

int main (int argc, char **argv) {
  (void) signal (SIGCHLD, signHandler);

  pid_t pidFirstSon, pidSecondSon;

  size_t buffersize = 50;

  char* buffer1 = calloc(buffersize, sizeof(char));
  char* buffer2 = calloc(buffersize, sizeof(char));

  int son1PTR = open("son1.txt", O_RDONLY);
  int son2PTR = open("son2.txt", O_RDONLY);

  fprintf(stderr, "PID ROOT: %d\n", getpid());

  pidFirstSon = fork();
  if (pidFirstSon > 0) {
    //sono nel padre riforco

    pidSecondSon = fork();
    if (pidSecondSon > 0) {
      //sono SEMPRE nel padre
      pause();

    } else {
      // sono nel secondo FIGLIO
      fprintf(stderr, "PID SECONDO FIGLIO: %d ; FIGLIO DI: %d\n", getpid(), getppid());
      read(son2PTR, buffer2, buffersize);
      fprintf(stderr, "SON2[50] -> %s\n", buffer2);

      sleep(5);

      printf("TERMINATO FIGLIO 2\n\n\n" );
      exit(0);
    }


  } else {
    // sono qua nel primo figlio

    read(son1PTR, buffer1, buffersize);
    fprintf(stderr, "SON1[50] -> %s\n", buffer1);

    printf("TERMINATO FIGLIO 1\n\n\n" );
    exit(0);
  }

  return 0;
}
