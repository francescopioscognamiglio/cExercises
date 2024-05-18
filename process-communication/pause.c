#include <stdio.h>
#include <unistd.h>

void main() {
  // send a signal in 5 seconds
  alarm(5);

  printf("Start waiting ...\n");
  fflush(stdout);
  pause();
}
