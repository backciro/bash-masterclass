#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char* argv[]) {
  int i = 0;
  char str[255];

  fgets(str, 255, stdin);

  while(str[i]) {
     putchar(toupper(str[i]));
     i++;
  }
  
  return 0;
}
