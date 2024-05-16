#include <unistd.h>
#include <stdio.h>

void main() {
  int myPid = getpid();
  printf("The PID of this process is: %d\n", myPid);
}
