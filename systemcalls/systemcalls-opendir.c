#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Missing directory as parameter.\n");
    return 1;
  }

  // open the given directory
  DIR *directory = opendir(argv[1]);
  if (directory == NULL) {
    printf("The directory %s does not exist.\n", argv[1]);
    return 1;
  }

  return 0;
}
