#include <unistd.h>
#include <stdio.h>

void main() {
  int parentPid = getppid();
  printf("The PID of the parent process is: %d\n", parentPid);
}
