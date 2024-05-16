#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int oldGroupId = getgid();
  bool isGroupChanged = setgid(55) == 0;
  int newGroupId = getgid();
  if (!isGroupChanged) {
    perror("Failure while changing the group");
    return EXIT_FAILURE;
  }

  printf("The ID of the group of the user that executed this process was: %d, now is: %d\n", oldGroupId, newGroupId);
  return EXIT_SUCCESS;
}
