#include <stdio.h>

void incrementByCopy(int n) {
  n += 10;
}

void incrementByRef(int *n) {
  *n += 10;
}

void main() {
  int n = 10;
  printf("The initial value of n is %d\n", n);
  incrementByCopy(n);
  printf("After calling a function by copy, the value of n is %d\n", n);
  incrementByRef(&n);
  printf("After calling a function by reference, the value of n is %d\n", n);

}
