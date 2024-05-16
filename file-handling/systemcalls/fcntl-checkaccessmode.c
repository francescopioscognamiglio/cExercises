#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Missing file descriptor.\n");
    return 1;
  }

  // the atoi function convers a string to an integer
  int fd = atoi(argv[1]);
  if (fd < 0) {
    printf("The file descriptor is not valid.\n");
    return 1;
  }

  // retrieve file access mode
  int accessMode = fcntl(fd, F_GETFL);
  if (accessMode <= 0) {
    printf("Cannot read the access mode of the file descriptor.\n");
    return 1;
  }

  // mask file access mode
  int accessModeMask = accessMode & O_ACCMODE;

  // check the access mode
  if (accessModeMask == O_RDONLY) printf("read only");
  else if (accessModeMask == O_WRONLY) printf("write only");
  else if (accessModeMask == O_RDWR) printf("read and write");
  else printf("unknown access mode");

  if (accessMode & O_APPEND) printf(", append");
  if (accessMode & O_NONBLOCK) printf(", nonblocking");

  printf("\n");

  return 0;
}
