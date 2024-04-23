#include <stdio.h>
#include <stdlib.h>

void main() {
  int A[] = {1, 5, 3, 2, 7};
  int *pA = NULL;

  printf("The array is:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");

  pA = A;
  printf("Point the first element of the array: %d\n", *pA);
  pA++;
  printf("Point the next element of the array: %d\n", *pA);
  pA--;
  printf("Go back to the first element of the array: %d\n", *pA);


  int *chars = calloc(10, sizeof(char));
  for (int i = 0; i < 10; i++) {
    chars[i] = 'd'+i;
  }
  printf("The dynamic array is:");
  for (int i = 0; i < 10; i++) {
    printf(" %c", chars[i]);
  }
  printf("\n");
}
