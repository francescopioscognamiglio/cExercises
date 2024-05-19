#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Parent: Hi, I'm the parent process with PID %d\n", getpid());

  int childPid = fork();
  if (childPid == -1) {
    perror("Error while creating child");
    return EXIT_FAILURE;
  }

  if (childPid == 0) {
    // child process
    printf("Child: Hello, I'm the child process with PID %d\n", getpid());
    return EXIT_SUCCESS; // important otherwise the child process executes the parent code
  }

  // parent process
  printf("Parent: My child has this PID %d\n", childPid);
  printf("Parent: End program\n");

  return EXIT_SUCCESS;
}
