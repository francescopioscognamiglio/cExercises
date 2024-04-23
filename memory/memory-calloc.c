#include <stdio.h>
#include <stdlib.h>

#define CHARS_SIZE 10

int main() {
  // create a dynamic array of characters
  char *chars = NULL;

  // allocate 10 elements in the heap space
  chars = (char *) calloc(CHARS_SIZE, sizeof(char));
  if (chars == NULL) {
    printf("Unable to allocate\n");
    return 1;
  }
  char *charsStart = NULL;
  charsStart = chars;

  for (int i = 0; i < CHARS_SIZE; i++) {
    *chars = 'a'+i;
    chars++;
  }

  chars = charsStart;
  printf("The dynamic array is:");
  for (int i = 0; i < CHARS_SIZE; i++) {
    printf(" %c", *chars);
    chars++;
  }
  printf("\n");

  return 0;
}
