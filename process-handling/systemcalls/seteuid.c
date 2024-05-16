#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int oldUserId = geteuid();
  bool isUserChanged = seteuid(55) == 0;
  int newUserId = geteuid();
  if (!isUserChanged) {
    perror("Failure while changing the user");
    return EXIT_FAILURE;
  }

  printf("The ID of the effective user that executed this process was: %d, now is: %d\n", oldUserId, newUserId);
  return EXIT_SUCCESS;
}
