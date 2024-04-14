#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MESSAGE1 "Hey! Good morning!\n"
#define MESSAGE2 "How are you?\n"
#define MESSAGE3 "Have you ever been to Rome?\n"

void main() {
  // duplicate the standard output
  int fd = -1;
  if ((fd = dup(STDOUT_FILENO)) <= -1) {
    printf("The file cannot be duplicated.");
  }
  printf("The duplicated file descriptor is %d\n", fd);

  // write to the standard output
  if (write(fd, MESSAGE1, sizeof(MESSAGE1)) <= -1) {
    printf("Error while writing into the file");
  }
  if (write(fd, MESSAGE2, sizeof(MESSAGE2)) <= -1) {
    printf("Error while writing into the file");
  }
  if (write(fd, MESSAGE3, sizeof(MESSAGE3)) <= -1) {
    printf("Error while writing into the file");
  }
}
