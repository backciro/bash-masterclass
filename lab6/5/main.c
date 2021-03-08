#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void signHandler(int signo) {
  fprintf(stdout, "PARENT PID: %d  |  MY PID: %d  |  SIGNAL: %d\n", getppid(), getpid(), signo);
  return;
}

int main (int argc, char **argv) {
  pid_t pid;
  int nsons, i = 0;
  int* pidSons;
  int sig;

  printf("PID PARENT : %d\n", getpid());

  fprintf(stdout, "Inserire numero figli:\t");
  fscanf(stdin, "%d", &nsons);

  pidSons = calloc(nsons, sizeof(int));

  for (i = 0; i < nsons; i++) {
    pid = fork();
    if (pid > 0) {
      pidSons[i] = pid;
      continue; // padre continua a forkare
    } else {
      // printf("sono un figlioletto\n");
      break; // il figlio mica forka
    }
  }

  if (pid > 0) {
    // padre setup
    while(1) {
      for (i = 0; i < nsons; i++) {
        printf("PID PADRE: %d  |  PID FIGLIO i: %d\n", getpid(), pidSons[i]);
        kill(pidSons[i], SIGUSR1);
        sleep(2);
      }
    }


  } else {
    // figli setup
    (void) signal (SIGUSR1, signHandler);

    while(1) {
      pause();
    }

    exit(0);
  }

  return 0;
}
