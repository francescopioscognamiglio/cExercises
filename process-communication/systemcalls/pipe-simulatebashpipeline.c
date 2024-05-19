#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *cmd1[] = { "/bin/ls", "-al", "/", 0 }; // 0 is the termination character of a string
char *cmd2[] = { "/usr/bin/tr", "a-z", "A-Z", 0 }; // 0 is the termination character of a string

/**
* This program simulates the execution of this pipe:
* /bin/ls -al / | /usr/bin/tr a-z A-Z
*/

int main() {
  // create pipe
  int fd[2];
  int isPipeCreated = pipe(fd);
  if (isPipeCreated == -1) {
    perror("Error while creating pipe");
  }

  // create child process
  int child = fork();
  if (child == -1) {
    perror("Error while creating child");
  }

  if (child == 0) {
    // child process
    dup2(fd[0], 0); // copy the read file descriptor of the pipe to the standard input
                    // in this way, a read operation from the tr command will read from the pipe (it's a blocking request waiting for data to read)
                    // while a write operation from the tr command remains on the standard output
    execvp(cmd2[0], cmd2); // this will execute the program replacing ours
                           // so the next lines will be executed only in case of errors
    perror("The command tr failed");
    return EXIT_FAILURE;
  }

  // parent process
  dup2(fd[1], 1); // copy the write file descriptor of the pipe to the standard output
                  // in this way, a write operation from the ls command will write into the pipe
  execvp(cmd1[0], cmd1); // this will execute the program replacing ours
                         // so the next lines will be executed only in case of errors
  perror("The command ls failed");
  return EXIT_FAILURE;
}
