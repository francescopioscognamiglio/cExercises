#include <stdio.h>

void myFunc() {
  static int n = 100;
  n++;
  printf("The value of the static variable is: %d\n", n);
}

void main() {
  myFunc();
  myFunc();
}
