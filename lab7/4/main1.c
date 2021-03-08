#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]) {

  char buffer[255];

  fscanf(stdin, "%s", buffer);

  puts(strcat("echo ", buffer));

  return 0;
}
