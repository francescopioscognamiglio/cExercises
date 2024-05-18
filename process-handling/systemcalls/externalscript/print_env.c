#include <stdio.h>

void main(int argc, char **argv, char **envp) {
  // printing arguments
  while (*argv != NULL) {
    printf("The argument is %s\n", *argv);
    argv++;
  }

  // printing environment variables
  while (*envp != NULL) {
    printf("The environment variable is %s\n", *envp);
    envp++;
  }
}
