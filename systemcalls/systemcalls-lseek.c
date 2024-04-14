#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 32

int readFile(int);

int main() {
  // open a file in read-only mode
  int file = 0;
  if ((file = open("filewithstrings.test", O_RDONLY)) <= -1) {
    printf("The file does not exist.\n");
    return 1;
  }

  // read the opened file
  if (readFile(file) >= 1) {
    return 1;
  }

  // set the file offset
  if (lseek(file, 2, SEEK_SET) <= -1) {
    printf("The file offset cannot be set.\n");
  }
  if (readFile(file) >= 1) {
    return 1;
  }

  // increase the file offset
  if (lseek(file, 2, SEEK_CUR) <= -1) {
    printf("The file offset cannot be increased.\n");
  }
  if (readFile(file) >= 1) {
    return 1;
  }

  // decrease the file offset
  // attention to read more than the provided bytes
  if (lseek(file, -40, SEEK_END) <= -1) {
    printf("The file offset cannot be decreased.\n");
  }
  if (readFile(file) >= 1) {
    return 1;
  }

  return 0;
}

int readFile(int file) {
  // read the opened file
  char buffer[BUFFER_SIZE] = {0};
  // the read function returns the number of bytes read
  if (read(file, buffer, BUFFER_SIZE-1) != BUFFER_SIZE-1) {
    printf("The file cannot be read.\n");
    return 1;
  }
  printf("%s\n", buffer);
  printf("\n");

  return 0;
}
