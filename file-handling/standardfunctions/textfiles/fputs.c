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
  char* s1 = "My first line\n";
  char* s2 = "The second one\n";
  char* s3 = "Last row\n";
  int r = fputs(s1, myFile);
  if (r <= 0) {
    perror("Error while writing");
    return errno;
  }
  r = fputs(s2, myFile);
  if (r <= 0) {
    perror("Error while writing");
    return errno;
  }
  r = fputs(s3, myFile);
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
