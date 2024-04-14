#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MESSAGE1 "Hey! Good morning!\n"
#define MESSAGE2 "How are you?\n"
#define MESSAGE3 "Have you ever been to Rome?\n"

int main() {
  int file = -1;
  if ((file = open("stdouttofile-withdup2.test", O_WRONLY | O_CREAT)) <= -1) {
    printf("The file cannot be opened.\n");
    return 1;
  }

  if (dup2(file, STDOUT_FILENO) != STDOUT_FILENO) {
    printf("The duplicated file is not the standard output.\n");
    return 1;
  }

  printf("This is a string redirect to the custom file.\n");
  printf("Have you ever seen a printf that write to a file?\n");

  return 0;
}
