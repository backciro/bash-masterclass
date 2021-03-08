#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 524288

int fd[2];

static void signalHandler (int signo) {
  return;
}

int main (int argc, char* argv[]) {

  int i, n, nR, nW;
  char c = '1';
  setbuf(stdout, 0);

  signal (SIGUSR1, signalHandler);

  pipe(fd);

  n = 0;
  if (fork()) {
    fprintf (stdout, "\nFather PID=%d\n", getpid());
    sleep (1);

    for (i=0; i<SIZE; i++) {
      nW = write (fd[1], &c, 1);
      n = n + nW;
      fprintf (stdout, "W %d\r", n);
    }

  } else {
    fprintf (stdout, "Child PID=%d\n", getpid());
    sleep (10);

    for (i=0; i<SIZE; i++) {
      nR = read (fd[0], &c, 1);
      n = n + nR;
      fprintf (stdout, "\t\t\t\tR %d\r", n);
    }
  }

}
