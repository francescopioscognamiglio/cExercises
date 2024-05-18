#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main() {
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGINT); // add the signal triggered by CTRL+C
  sigaddset(&set, SIGUSR1); // add the signal USR2

  printf("start waiting for 10 seconds ...\n");
  fflush(stdout);
  // activate this process after 10 seconds
  alarm(10);

  // suspend the current process
  sigsuspend(&set);

  // SIGALARM will kill the process, so this print won't happen
  printf("10 seconds passed so far.\n");
}
