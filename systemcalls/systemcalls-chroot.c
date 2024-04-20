#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Missing parameters.\n");
    return 1;
  }

  // open the directory
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Cannot open the directory %s\n", argv[1]);
    return 1;
  }
  printf("Opened the directory %s\n", argv[1]);

  // change the root directory
  int r = chroot("/home/francescopio");
  if (r != 0) {
    if (errno & EACCES) {
      printf("Permission denied changing the root directory.\n");
    } else {
      printf("Cannot change the root directory.\n");
    }
    return 1;
  }
  printf("Changed the root directory.\n");

  // re-open the directory
  dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Cannot open the directory %s\n", argv[1]);
    return 1;
  }

  return 0;
}
