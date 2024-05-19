#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int createChild(int number) {
  int child = fork();
  if (child == -1) {
    perror("Error while creating child");
    return -1;
  }
  if (child == 0) {
    // child process
    printf("Child %d: Hello, I'm the child process with PID %d\n", number, getpid());
    // some iterations
    for (int i = 0; i < 200; i++) {
      printf("Child %d: This is the string #%d\n", number, i);
    }

    return child;
  }
}

int main() {
  printf("Parent: Hi, I'm the parent process with PID %d\n", getpid());
  printf("Parent: Creating child 1 ...\n");
  int childCreated1 = createChild(1);
  if (childCreated1 == -1) {
    perror("Error while creating child 1");
    return EXIT_FAILURE;
  }
  if (childCreated1 == 0) {
    // child 1 process
    printf("Child 1: End program\n");
    return EXIT_SUCCESS; // important otherwise the child process executes the parent code
  }

  // parent process
  printf("Parent: Child 1 has the PID %d\n", childCreated1);
  printf("Parent: Creating child 2 ...\n");
  int childCreated2 = createChild(2);
  if (childCreated2 == -1) {
    perror("Error while creating child 2");
    return EXIT_FAILURE;
  }
  if (childCreated2 == 0) {
    // child 2 process
    printf("Child 2: End program\n");
    return EXIT_SUCCESS; // important otherwise the child process executes the parent code
  }

  // parent process
  printf("Parent: Child 2 has the PID %d\n", childCreated2);
  printf("Parent: Start waiting for a child ...\n");
  int statusChild2, statusChild1;
  int child2 = waitpid(childCreated2, &statusChild2, WUNTRACED | WCONTINUED);
  printf("Parent: Child with PID %d has finished with status %d\n", child2, WEXITSTATUS(statusChild2)); // pay attention that status has extra information, so a macro WEXITSTATUS is needed to keep only the exit status
  int child1 = waitpid(childCreated1, &statusChild1, WUNTRACED | WCONTINUED);
  printf("Parent: Child with PID %d has finished with status %d\n", child1, WEXITSTATUS(statusChild1));// pay attention that status has extra information, so a macro WEXITSTATUS is needed to keep only the exit status
  printf("Parent: End program\n");

  return EXIT_SUCCESS;
}
