#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Parent: Hello, I'm the parent with PID %d\n", getpid());

  int fd[2]; // fd[0] is the read file descriptor, fd[1] is the write file descriptor
  int pipeCreated = pipe(fd);
  if (pipeCreated == -1) {
    perror("Error while opening a pipe");
    return EXIT_FAILURE;
  }

  // create child process
  int child = fork();
  if (child == -1) {
    perror("Error while creating a child");
    return EXIT_FAILURE;
  }

  if (child == 0) {
    // child process
    printf("Child: Hi all, I'm the child with PID %d\n", getpid());

    // read the message from the pipe
    char message[1025];
    printf("Child: About to receive a message from my dad\n");
    int numberOfBytesRead = read(fd[0], message, 1024); // this is a blocking request until the pipe has data
    if (numberOfBytesRead <= 0) {
      perror("Error while reading from pipe");
      return EXIT_FAILURE;
    }
    message[numberOfBytesRead] = '\0'; // important to terminate the string
    printf("Child: Read %d bytes from the pipe: \"%s\"\n", numberOfBytesRead, message);

    return EXIT_SUCCESS;
  }

  // parent process
  printf("Parent: This is my son with PID %d\n", child);

  // write the message into the pipe
  char *data = "Hello son, how are you?";
  printf("Parent: About to send this message to my son: \"%s\"\n", data);
  write(fd[1], data, strlen(data)); // this write operation finishes on the pipe, so anyone can read this string

  return EXIT_SUCCESS;
}
