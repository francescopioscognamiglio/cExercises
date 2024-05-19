#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int myGlobalVar = 10;

int main() {
  int myLocalVar = 15;
  printf("Parent: myGlobalVar=%d myLocalVar=%d\n", myGlobalVar, myLocalVar);

  printf("Parent: Hi, I'm the parent process with PID %d\n", getpid());

  int childPid = fork();
  if (childPid == -1) {
    perror("Error while creating child");
    return EXIT_FAILURE;
  }

  if (childPid == 0) {
    // child process
    printf("Child: Hello, I'm the child process with PID %d\n", getpid());
    myGlobalVar += 10;
    myLocalVar += 20;
    printf("Child: myGlobalVar=%d myLocalVar=%d\n", myGlobalVar, myLocalVar);
    return EXIT_SUCCESS; // important otherwise the child process executes the parent code
  }

  // parent process
  sleep(10);
  printf("Parent: My child has this PID %d\n", childPid);
  printf("Parent: myGlobalVar=%d myLocalVar=%d\n", myGlobalVar, myLocalVar);
  printf("Parent: End program\n");

  return EXIT_SUCCESS;
}
