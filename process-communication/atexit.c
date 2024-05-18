#include <stdio.h>
#include <stdlib.h>

void myFuncBeforeClosing() {
  printf("Why are you closing me? :\(\n");
}

void main() {
  atexit(myFuncBeforeClosing);

  int n;
  scanf("%d", &n);
  if (n > 10) {
    return; // the exit status 0 is returned
  } else {
    exit(EXIT_FAILURE); // the exit status 127 is returted
  }
}
