#include <stdio.h>
#include <stdlib.h>

void main() {
  int rows = 10, cols = 15;
  // allocate dynamic array of rows
  int **a = calloc(10, sizeof(int *));
  for (int i = 0; i < rows; i++) {
    // for each row, allocate dynamic array of cols
    a[i] = calloc(cols, sizeof(int));
  }

  // insert values in matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a[i][j] = 3*(i+1)*(j+1);
    }
  }

  // print matrix
  printf("The matrix is:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("[%d][%d] = %d\n", i, j, a[i][j]);
    }       
  }

  free(a);
}
