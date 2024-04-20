#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void main() {
  int fd = open("notexistingfile", O_RDONLY);
  char *s = strerror(errno);
  printf("%s\n", s);
}
