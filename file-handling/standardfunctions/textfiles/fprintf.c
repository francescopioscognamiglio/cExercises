#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  FILE* myFile = NULL;

  // open a file in write mode (if it does not exist, create it)
  char write = 'w';
  myFile = fopen("file.test", &write);
  if (myFile == NULL) {
    perror("Error while opening in write mode");
    return errno;
  }

  // write each line
  char* s1 = "My first line";
  char* s2 = "The second one";
  char* s3 = "Last row";
  int r = fprintf(myFile, "%s\n%s\n%s", s1, s2, s3);
  if (r <= 0) {
    perror("Error while writing");
    return errno;
  }

  // close an opened file
  r = fclose(myFile);
  if (r != 0) {
    perror("Error while closing");
    return errno;
  }

  return 0;
}
