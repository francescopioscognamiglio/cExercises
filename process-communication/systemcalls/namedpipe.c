#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NAMED_PIPE "namedpipetest"

void runpipe(int fd, int mode);

int main(int argc, char **argv) {

  struct stat pipeStat;
  // check if the file exists
  if (stat(NAMED_PIPE, &pipeStat)) {
    // create a named pipe
    if (mkfifo(NAMED_PIPE, S_IRUSR | S_IWUSR)) {
      perror("Unable to create the named pipe");
      printf("The error is %d\n", errno);
      exit(1);
    }
  }
  // check if the file has the correct file type
  else if (!S_ISFIFO(pipeStat.st_mode)) {
    fprintf(stderr, "File already exists but it's not a named pipe\n");
    exit(2);
  }

  // the named pipe is ok, let's open it
  int fd = open(NAMED_PIPE, (argc == 2 ? O_RDONLY : O_WRONLY)); // since we are opening a named pipe
                                                                // this is a blocking request:
                                                                // waiting for a process that will perform the opposite operation
                                                                // (the opening in read mode will wait for an opening in write mode and viceversa)
  if (fd == -1) {
    perror("Unable to open the named pipe");
    exit(3);
  }
  printf("The named pipe in %s mode is ready\n", (argc == 2 ? "READ" : "WRITE"));
  fflush(stdout);
  runpipe(fd, argc == 2);
  if (close(fd)) {
    perror("Unable to close the named pipe");
    exit(4);
  }

  return EXIT_SUCCESS;
}

void runpipe(int fd, int mode) {
  char *cmd1[] = { "/bin/ls", "-al", "/", 0 }; // manually set the termination character of the string
  char *cmd2[] = { "/usr/bin/tr", "a-z", "A-Z", 0 }; // manually set the termination character of the string

  switch(mode) {
    case 1: // 1 is true so it's the READ mode
      dup2(fd, 0); // overwrite the named pipe to the standard input (this read from the named pipes, so the output of the other command)
      execvp(cmd2[0], cmd2); // run tr command
      // our process is replaced by the new process, so it's not needed the break statement
    case 0: // 0 is false so it's the WRITE mode
      dup2(fd, 1); // overwrite the named pipe to the standard output (this writes into the named pipe)
      execvp(cmd1[0], cmd1); // run ls command
      // our process is replaced by the new process, so it's not needed the break statement
  }
}
