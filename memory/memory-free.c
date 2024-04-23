#include <stdio.h>
#include <stdlib.h>

#define INTEGERS_SIZE 10
#define CHARS_SIZE 10

int main() {
  int *integers = NULL;
  integers = (int *) malloc(INTEGERS_SIZE*sizeof(int));
  if (integers == NULL) {
    printf("Unable to allocate\n");
    return 1;
  }

  char *chars = NULL;
  chars = (char *) calloc(CHARS_SIZE, sizeof(char));
  if (chars == NULL) {
    printf("Unable to allocate\n");
    return 1;
  }

  free(integers);
  free(chars);

  return 0;
}
