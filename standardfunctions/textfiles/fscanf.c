#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  FILE* myFile = NULL;

  // open a file in read mode (if it does not exist, an error is given)
  char read = 'r';
  myFile = fopen("file.test", &read);
  if (myFile == NULL) {
    perror("Error while opening in read mode");
    return errno;
  }

  // read each line
  char* s1 = malloc(sizeof(s1)*100);
  while (fscanf(myFile, "%s", s1) >= 0) {
    printf("The row is: %s\n", s1);
  }

  // close an opened file
  int r = fclose(myFile);
  if (r != 0) {
    perror("Error while closing");
    return errno;
  }

  return 0;
}
