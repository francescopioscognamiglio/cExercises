#include <unistd.h>
#include <stdio.h>

void main() {
  int groupId = getegid();
  printf("The group ID of the effective user that executed this process is: %d\n", groupId);
}
