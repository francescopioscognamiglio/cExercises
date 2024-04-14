#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MESSAGE1 "Hey! Good morning!\n"
#define MESSAGE2 "How are you?\n"
#define MESSAGE3 "Have you ever been to Rome?\n"

void main() {
  int file = -1;
  if ((file = open("stdouttofile.test", O_WRONLY | O_CREAT)) <= -1) {
    printf("The file cannot be opened.\n");
  }

  if (close(STDOUT_FILENO) <= -1) {
    printf("The standard output cannot be closed.\n");
  }

  if (dup(file) != STDOUT_FILENO) {
    printf("The duplicated file is not the standard output.\n");
  }

  if (close(file) <= -1) {
    printf("The file cannot be closed.\n");
  }

  printf("This is a string redirect to the custom file.\n");
  printf("Have you ever seen a printf that write to a file?\n");
}
