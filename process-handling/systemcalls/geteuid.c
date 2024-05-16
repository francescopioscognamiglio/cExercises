#include <unistd.h>
#include <stdio.h>

void main() {
  int userId = geteuid();
  printf("The ID of the effective user that executed this process is: %d\n", userId);
}
