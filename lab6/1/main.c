#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int a = 0, b = 0;

static void signHandler(int signo) {
  if (signo == SIGUSR2) {
    fprintf(stdout, "%s: %d\n", "somma", a+b);
    return;
  }
  if (signo == SIGUSR1) {
    fprintf(stdout, "%s: %d\n", "differenza", a-b);
    return;
  }
  if (signo == SIGINT) {
    fprintf(stdout, "%s\n", "Spegnimento...");
    exit(0);
  }
}

int main (int argc, char **argv) {
  (void) signal (SIGUSR1, signHandler);
  (void) signal (SIGUSR2, signHandler);
  (void) signal (SIGINT, signHandler);


  if (argc != 3) {
    fprintf(stderr, "%s\n", "ERRORE PARAMS");
    return -1;
  } else {
    a = atoi(argv[1]);
    b = atoi(argv[2]);
  }

  while(1) {
    fprintf(stdout, "%s\n", "IN ATTESA DI SEGNALE...");
    fprintf(stdout, "%s %d\n","eseguire kill -USR1 ", getpid());
    pause();
    fprintf(stdout, "%s\n", "SEGNALE RICEVUTO");
  }

}
