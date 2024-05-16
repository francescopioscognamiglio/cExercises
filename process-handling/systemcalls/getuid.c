#include <unistd.h>
#include <stdio.h>

void main() {
  int userId = getuid();
  printf("The ID of the user that executed this process is: %d\n", userId);
}
