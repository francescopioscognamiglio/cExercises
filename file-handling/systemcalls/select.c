#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 20

int main() {
  fd_set rfds;
  struct timeval tv;

  // init file descriptors set
  FD_ZERO(&rfds);
  // add the standard input (0) into the file descriptors set
  FD_SET(0, &rfds);

  // wait up to 5 seconds
  tv.tv_sec = 5;
  tv.tv_usec = 0;

  printf("Reading data...\n");

  // using select system call:
  // - check the given file descriptors up to 5 seconds
  // - return the number of unblocked file descriptors
  // (setting NULL as timeval, this select becomes a blocking request)
  int numberOfFds = select(1, &rfds, NULL, NULL, &tv);
  if (numberOfFds == -1) {
    printf("Error while calling.\n");
    return 1;
  } else if (numberOfFds == 0) {
    printf("No data has been read.\n");
    return 1;
  }

  char buffer[BUFF_SIZE] = {};
  int numberOfBytesRead = read(0, buffer, BUFF_SIZE);
  printf("Number of bytes read: %d\n", numberOfBytesRead);

  return 0;
}
