#include <stdio.h>
#include <stdlib.h>

void main() {
  // setting environment variable via setenv
  int status = setenv("my_custom_var", "my_custom_val", 0);
  if (status != 0) {
    perror("Error while setting the environment variable");
  }

  // unsetting environment variable via unsetenv
  status = unsetenv("my_custom_var");
  if (status != 0) {
    perror("Error while unsetting the environment variable");
  }

  char *myCustomVar = getenv("my_custom_var");
  if (myCustomVar == NULL) {
    printf("The environment variable has been unset succesfully\n");
  }
}
