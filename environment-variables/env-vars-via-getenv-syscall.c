#include <stdio.h>
#include <stdlib.h>

void main(int argc, char **argv) {
  printf("PATH : %s\n", getenv("PATH"));
  if (argc > 1) {
    printf("%s : %s\n", argv[1], getenv(argv[1]));
  }
}
