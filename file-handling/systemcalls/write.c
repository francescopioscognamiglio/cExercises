#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 32

void main() {
  // open a file
  int fileDescriptor = open("filenevercreated.test", O_RDWR | O_CREAT);

  // write to the opened file
  char buffer[BUFFER_SIZE] = {'a', 'b', 'c'};
  int numberOfBytesWritten = write(fileDescriptor, buffer, BUFFER_SIZE-1);
  if (numberOfBytesWritten == -1) {
    printf("Failure while writing to the specified file\n");
  } else {
    printf("The specified file was written successfully\n");
  }
}
