#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int oldUserId = getuid();
  bool isUserChanged = setuid(55) == 0;
  int newUserId = getuid();
  if (!isUserChanged) {
    perror("Failure while changing the user");
    return EXIT_FAILURE;
  }

  printf("The ID of the real user that executed this process was: %d, now is: %d\n", oldUserId, newUserId);
  return EXIT_SUCCESS;
}
