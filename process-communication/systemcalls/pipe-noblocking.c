#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main() {
  int fd[2]; // fd[0] is the read file descriptor, fd[1] is the write file descriptor
  int pipeCreated = pipe(fd);
  if (pipeCreated == -1) {
    perror("Error while opening a pipe");
    return EXIT_FAILURE;
  }

  // set the read file descriptor to be no-blocking
  // otherwise the read could cause an infinite loop
  int isFdUpdated = fcntl(fd[0], F_SETFL, O_NONBLOCK);
  if (isFdUpdated == -1) {
    perror("Error while setting the read file descriptor");
    return EXIT_FAILURE;
  }

  // read the message from the pipe
  char message[1025];
  int numberOfBytesRead = read(fd[0], message, 1024);
  if (numberOfBytesRead <= 0) {
    perror("Error while reading from pipe");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
