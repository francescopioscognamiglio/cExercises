#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Missing file descriptor.\n");
    return 1;
  }

  // open the file in write mode
  char* file = argv[1];
  int fd = open(file, O_WRONLY);
  if (fd < 0) {
    printf("Error opening the file %s\n", file);
    return 1;
  }

  printf("Locking the file %s.\n", file);

  struct flock lock;
  // clean all the data
  memset(&lock, 0, sizeof(lock));
  // define a write lock
  lock.l_type = F_WRLCK;
  // place a write lock
  fcntl(fd, F_SETLKW, &lock);

  printf("File %s locked.\n", file);
  printf("Write something to unlock...");
  char p;
  scanf("%c", &p);

  // release the lock
  lock.l_type = F_UNLCK;
  fcntl(fd, F_SETLKW, &lock);
  printf("File %s unlocked.\n", file);

  return 0;
}
