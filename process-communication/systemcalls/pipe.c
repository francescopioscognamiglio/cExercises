#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int fd[2]; // fd[0] is the read file descriptor, fd[1] is the write file descriptor
  int pipeCreated = pipe(fd);
  if (pipeCreated == -1) {
    perror("Error while opening a pipe");
    return EXIT_FAILURE;
  }

  // write the message into the pipe
  char *data = "This is the first message";
  write(fd[1], data, strlen(data)); // this write operation finishes on the pipe, so anyone that reads can receive this string

  // read the message from the pipe
  char message[1025];
  int numberOfBytesRead = read(fd[0], message, 1024);
  if (numberOfBytesRead <= 0) {
    perror("Error while reading from pipe");
    return EXIT_FAILURE;
  }
  message[numberOfBytesRead] = '\0'; // important to terminate the string
  printf("Read %d bytes from the pipe: \"%s\"\n", numberOfBytesRead, message);

  return EXIT_SUCCESS;
}
