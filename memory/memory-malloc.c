#include <stdio.h>
#include <stdlib.h>

#define INTEGERS_SIZE 10

int main() {
  // create a dynamic array of integers
  int *integers = NULL;

  // allocate 10 elements in the heap space
  integers = (int *) malloc(INTEGERS_SIZE*sizeof(int));
  if (integers == NULL) {
    printf("Unable to allocate\n");
    return 1;
  }
  int *integersStart = NULL;
  integersStart = integers;

  for (int i = 0; i < INTEGERS_SIZE; i++) {
    *integers = i;
    integers++;
  }

  integers = integersStart;
  printf("The dynamic array is:");
  for (int i = 0; i < INTEGERS_SIZE; i++) {
    printf(" %d", *integers);
    integers++;
  }
  printf("\n");

  return 0;
}
