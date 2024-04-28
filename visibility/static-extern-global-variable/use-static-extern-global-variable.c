#include <stdio.h>

extern int nOpen; // this refers to the global variabile defined in the other file
//extern int nPrivate; // this should refer to the global variable defined in the other file, but there is static, so it cannot be used without a manual import

void myFunc() {
  nOpen++;
  //nPrivate++;

  printf("The value of an open global variable is: %d\n", nOpen);
  //printf("The value of a private global variabile is: %d\n", nPrivate);
}

void main() {
  myFunc();
}
