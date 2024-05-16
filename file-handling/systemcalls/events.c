#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Missing parameters.\n");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("Cannot open the file %s", argv[1]);
    return 1;
  }

  struct input_event ie;
  while (read(fd, &ie, sizeof(struct input_event))) {
    // read data
    printf("Type %d", ie.type);
    printf("\tCode %d", ie.code);
    printf("\tValue %d", ie.value);
    printf("\tTime: seconds %ld microseconds %ld", ie.time.tv_sec, ie.time.tv_usec);
    printf("\n");

    fflush(stdout);
  }

  return 0;
}
