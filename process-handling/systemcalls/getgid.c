#include <unistd.h>
#include <stdio.h>

void main() {
  int groupId = getgid();
  printf("The group ID of the user that executed this process is: %d\n", groupId);
}
