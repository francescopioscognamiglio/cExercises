#include <stdio.h>
#include <unistd.h>

void main() {
  printf("Start waiting for 10 seconds ...\n");
  fflush(stdout);
  sleep(10);
  printf("The time passed so far.\n");
}
