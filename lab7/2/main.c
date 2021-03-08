#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int pidSon;

static void signHandler(int signo) {
  if (signo == SIGCHLD)
    exit(0);
  if (signo == SIGINT)
    kill(pidSon, SIGINT);

  return;
}

static void signHandlerSon(int signo) {
  if (signo == SIGINT)
    return;
}

int main (int argc, char **argv) {
  pid_t pid;
  int nsons, i = 0;
  int sig;

  pid = fork();
  if (pid > 0) {
    pidSon = pid;
    printf("eseguire kill -INT %d\n", getpid());

    (void) signal (SIGINT, signHandler);

    wait(NULL); //attendo
  } else {

    (void) signal (SIGINT, signHandlerSon);
    pause();

    fprintf(stdout, "son PID: %d\n", getpid());
    exit(0);
  }

  return 0;
}
