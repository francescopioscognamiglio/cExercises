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

  // open a file in read mode (error if it does not exist)
  char read = 'r';
  myFile = fopen("file.test", &read);
  if (myFile == NULL) {
    perror("Error while opening in read mode");
    return errno;
  }

  // open a file in append mode (if it does not exist, create it)
  char append = 'a';
  myFile = fopen("file.test", &append);
  if (myFile == NULL) {
    perror("Error while opening in append mode");
    return errno;
  }

  return 0;
}
