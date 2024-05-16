#include <stdio.h>

void main(int argc, char **argv, char **envp) {
  // printing environment variables
  while (*envp) {
    printf("This is an environment variable: %s\n", *envp);
    envp++; // increase the pointer by its size (not a real +1)
  }
}
