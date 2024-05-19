#include <stdio.h>
#include <stdlib.h>

void main() {
  // send the signal ABRT to this process (so the process will be killed)
  abort();

  // since abort will kill our process, this instruction won't be executed
  printf("This print won't happen.");
}
