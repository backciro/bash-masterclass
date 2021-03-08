#include <stdio.h>
#include <string.h>

#define MAXR 255

void printHelp();


int main(int argc, char const *argv[]) {

  FILE* fSrc;
  FILE* fDst;

  char* buffer = malloc(MAXR * sizeof(char));

  if (argc != 3) {
    fprintf(stderr, "%s\n", "Errore nel numero di parametri!");
    printHelp();
    exit(-1);
  }

  if (strcmp(argv[1], argv[2]) == 0) {
    fprintf(stderr, "%s\n", "Non puoi copiare il file su se stesso!");
    printHelp();
    exit(-1);
  }

  if ((fSrc = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Impossibile aprire il file %s\n", argv[1]);
    exit(-1);
  }

  if ((fDst = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Impossibile scrivere sul file %s\n", argv[2]);
    exit(-1);
  }

  while (fgets(buffer, MAXR, fSrc) != NULL) {
      fputs(buffer, fDst);
  }

  fprintf(stdout, "Copia completata!\n");

  fclose(fSrc);
  fclose(fDst);

  return 0;
}

void printHelp() {
  fprintf(stdout, "--- MANUALE ----\n./a.out [SRC_PATH] [DST_PATH]\n");
}
