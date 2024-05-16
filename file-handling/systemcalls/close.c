#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 32

void main() {
  // close a file
  int status = close(3);

  if (status != 0) {
    if (errno == EBADF) {
      printf("The specified file descriptor does not exist\n");
    } else {
      printf("The specified file descriptor cannot be closed. The generated error is has this code: %d\n", errno);
    }
  } else {
    printf("The specified file descriptor was closed successfully\n");
  }
}
