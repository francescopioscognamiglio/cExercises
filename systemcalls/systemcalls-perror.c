#include <fcntl.h>
#include <stdio.h>

void main() {
  int fd = open("notexistingfile", O_RDONLY);
  perror("The given file does not exist");
}
