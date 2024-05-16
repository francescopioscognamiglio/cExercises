#include <stdio.h>
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

  // close an opened file
  int r = fclose(myFile);
  if (r != 0) {
    perror("Error while closing");
    return errno;
  }

  return 0;
}
