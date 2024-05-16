#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

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

  // change the current working directory
  int r = chdir("..");
  if (r != 0) {
    printf("Cannot change the current working directory.\n");
    return 1;
  }
  printf("Changed the current working directory.\n");

  // re-open the directory
  dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Cannot open the directory %s\n", argv[1]);
    return 1;
  }

  return 0;
}
