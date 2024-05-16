#include <stdio.h>
#include <fcntl.h>

void main() {
  // try to open a file that does not exist
  int fileDescriptor = open("filenevercreated.test", O_RDWR);
  if (fileDescriptor == -1) {
    printf("The specified file does not exist\n");
  } else {
    printf("The specified file exists\n");
  }
}
