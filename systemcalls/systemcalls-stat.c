#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
  struct stat fileStat;
  if (stat(argv[1], &fileStat) < 0) {
    printf("The system information cannot be read for the specified file.");
    return 1;
  }

  printf("Information for %s:\n", argv[1]);
  printf("File size: %ld bytes\n", fileStat.st_size);
  printf("Number of links: %ld\n", fileStat.st_nlink);
  printf("File inode: %ld\n", fileStat.st_ino);

  printf("File permissions: ");
  /* S_IRWXU     00700   owner has read, write, and execute permission
   * S_IRUSR     00400   owner has read permission
   * S_IWUSR     00200   owner has write permission
   * S_IXUSR     00100   owner has execute permission
   * S_IRWXG     00070   group has read, write, and execute permission
   * S_IRGRP     00040   group has read permission
   * S_IWGRP     00020   group has write permission
   * S_IXGRP     00010   group has execute permission
   * S_IRWXO     00007   others  (not  in group) have read, write, and execute permission
   * S_IROTH     00004   others have read permission
   * S_IWOTH     00002   others have write permission
   * S_IXOTH     00001   others have execute permission*/
  printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
  printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
  printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");

  printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
  printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
  printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");

  printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
  printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
  printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

  printf("\n");

  return 0;
}
