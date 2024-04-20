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

  // read the content
  struct dirent* entry;
  entry = readdir(directory);
  if (entry == NULL) {
    printf("The entry for %s cannot be opened.\n", argv[1]);
    return 1;
  }
  printf("Information of the first file in the directory %s:\n", argv[1]);
  printf("\tInode number: %ld\n", entry->d_ino);
  printf("\tType of file: %c\n", entry->d_type);
  printf("\tFilename: %s\n", entry->d_name);

  entry = readdir(directory);
  if (entry == NULL) {
    printf("The entry for %s cannot be opened.\n", argv[1]);
    return 1;
  }
  printf("Information of the second file in the directory %s:\n", argv[1]);
  printf("\tInode number: %ld\n", entry->d_ino);
  printf("\tType of file: %c\n", entry->d_type);
  printf("\tFilename: %s\n", entry->d_name);

  return 0;
}
