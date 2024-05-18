#include <stdio.h>
#include <stdlib.h>

void main() {
  int n;
  scanf("%d", &n);
  if (n > 10) {
    exit(EXIT_SUCCESS); // the exit status 0 is returned
  } else {
    exit(EXIT_FAILURE); // the exit status 127 is returted
  }
}
