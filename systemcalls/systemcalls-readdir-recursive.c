#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>

void printDir(struct dirent* entry) {
  printf("Filename: %s", entry->d_name);
  printf("\tInode number: %ld", entry->d_ino);

  if (entry->d_type & DT_DIR) printf("\tis a directory.");
  else if (entry->d_type & DT_REG) printf("\tis a regular file.");
  else if (entry->d_type & DT_LNK) printf("\tis a symbolic link.");
  else if (entry->d_type & DT_UNKNOWN) printf("\tis an unknown file.");

  printf("\n");
}

void explore(char* dirName) {
  // open the directory
  DIR *dir = opendir(dirName);
  if (dir == NULL) {
    return;
  }

  while (1) {
    // read directory content
    struct dirent* entry = readdir(dir);

    if (entry == NULL) {
      // there are no more entries
      break;
    }
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      // exclude current dir and parent dir
      continue;
    }

    printDir(entry);

    if (entry->d_type & DT_DIR) {
      char path[PATH_MAX];
      snprintf(path, PATH_MAX, "%s/%s", dirName, entry->d_name);
      explore(path);
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Missing directory as parameter.\n");
    return 1;
  }

  explore(argv[1]);

  return 0;
}
