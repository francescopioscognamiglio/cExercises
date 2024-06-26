#include <stdio.h>
#include <stdlib.h>

void main() {
  // setting environment variable via putenv
  int status = putenv("my_custom_var=my_custom_val");
  if (status != 0) {
    perror("Error while setting the environment variable");
  }

  char *myCustomVar = getenv("my_custom_var");
  printf("The environment variable is my_custom_var=%s\n", myCustomVar);
}
