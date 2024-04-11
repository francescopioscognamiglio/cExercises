#include <stdio.h>

void main() {
  // init the 20 values to 0
  int myStaticArray[20] = {0};
  for (int i = 0; i < 20; i++) {
    printf("The value at %d is %d\n", i, myStaticArray[i]);
  }

  double mySecondStaticArray[5] = {};
  for (int i = 0; i < 5; i++) {
    printf("The value at %d is %f\n", i, mySecondStaticArray[i]);
  }
}
