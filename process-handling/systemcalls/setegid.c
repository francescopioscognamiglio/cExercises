#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int oldGroupId = getegid();
  bool isGroupChanged = setegid(55) == 0;
  int newGroupId = getegid();
  if (!isGroupChanged) {
    perror("Failure while changing the group");
    return EXIT_FAILURE;
  }

  printf("The ID of the group of the effective user that executed this process was: %d, now is: %d\n", oldGroupId, newGroupId);
  return EXIT_SUCCESS;
}
