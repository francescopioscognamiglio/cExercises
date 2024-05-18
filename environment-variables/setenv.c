#include <stdio.h>
#include <stdlib.h>

void main() {
  // setting environment variable via setenv
  int status = setenv("my_custom_var", "my_custom_val", 0);
  if (status != 0) {
    perror("Error while setting the environment variable");
  }

  char *myCustomVar = getenv("my_custom_var");
  printf("The environment variable is my_custom_var=%s\n", myCustomVar);
}
