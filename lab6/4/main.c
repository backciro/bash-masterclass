#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void signHandler(int signo) {
  if (signo == SIGUSR1) {
    fprintf(stdout, "%s\n", "Ricevuto segnale -USR1 (PARENT)");
    return;
  }

  if (signo == SIGUSR2) {
    fprintf(stdout, "%s\n", "Ricevuto segnale -USR2 (PARENT)");
    return;
  }
}
static void signHandlerSon(int signo) {
  if (signo == SIGUSR1) {
    kill(getppid(), SIGUSR2);
    return;
  }
  else if (signo == SIGUSR2) {
    kill(getppid(), SIGUSR1);
    return;
  }
  else if (signo == SIGINT) {
    kill(getppid(), SIGINT);
    exit(0);
    return;
  }
  else { return; } // IGNORO TUTTI GLI ALTRI SEGNALI
}

int main (int argc, char **argv) {
  pid_t pid;
  int sig;

  pid = fork();
  if (pid > 0) {
    //sono nel padre riforco
    fprintf(stderr, "PID padre: %d\n", getpid());

    (void) signal (SIGUSR1, signHandler);
    (void) signal (SIGUSR2, signHandler);

    fprintf(stdout, "Inserire SIGNAL INT\n");
    fscanf(stdin, "%d", &sig);

    while (1) {
      kill(pid, sig);
      fprintf(stdout, "PID sul quale faccio kill: %d\n", pid);

      sleep(5);
    }

  } else {
    // sono qua nel primo figlio
    (void) signal (SIGUSR1, signHandlerSon);
    (void) signal (SIGUSR2, signHandlerSon);
    (void) signal (SIGINT, signHandlerSon);

    fprintf(stdout, "PID figlio: %d\n", getpid());

    while(1) {
      pause();
    }

    exit(0);
  }

  return 0;
}
