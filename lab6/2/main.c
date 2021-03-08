#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

pid_t pid = 0;

static void signHandler(int signo) {
  if (signo == SIGUSR2) {
    fprintf(stdout, "%s: ", "sending somma sig\n");
    kill(pid, SIGUSR2);
    return;
  }
  if (signo == SIGUSR1) {
    fprintf(stdout, "%s: ", "sending differenza sig\n");
    kill(pid, SIGUSR1);
    return;
  }
  if (signo == SIGINT) {
    fprintf(stdout, "%s\n", "Spegnimento SIG...\n");
    kill(pid, SIGINT);
    exit(-1);
  }
}

int main (int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "%s\n", "ERROR\n");
    exit(-1);
  }


  (void) signal (SIGUSR1, signHandler);
  (void) signal (SIGUSR2, signHandler);
  (void) signal (SIGINT, signHandler);

  int comando;
  pid = atoi(argv[1]);

  fprintf(stdout, "%s\n", "scegliere un comando: \n1 : differenza\n2 : somma\n3: fine");
  while(1) {
    fscanf(stdin, "%d", &comando);
    switch (comando) {
      case 1:
        raise(SIGUSR1);
        break;
      case 2:
        raise(SIGUSR2);
        break;
      default:
        raise(SIGINT);
        break;
    }
  }


}
