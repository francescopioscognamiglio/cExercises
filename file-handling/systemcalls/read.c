#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 32

void main() {
  // open a file
  int fileDescriptor = open("filenevercreated.test", O_RDWR);

  // read the opened file
  char buffer[BUFFER_SIZE] = {0};
  int numberOfBytesRead = read(fileDescriptor, buffer, BUFFER_SIZE-1);
  if (numberOfBytesRead == -1) {
    printf("The specified file cannot be read\n");
  } else {
    printf("The specified file can be read\n");
  }
}
