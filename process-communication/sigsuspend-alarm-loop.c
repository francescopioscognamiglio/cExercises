#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main() {
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGINT); // add the signal triggered by CTRL+C
  sigaddset(&set, SIGUSR1); // add the signal USR2
  sigaddset(&set, SIGALRM); // add the signal ALRM triggered by the alarm system call

  printf("start waiting for 10 seconds ...\n");
  fflush(stdout);
  // activate this process after 10 seconds
  alarm(10);

  // suspend the current process
  sigsuspend(&set);

  // this process enters in a loop:
  // the SIGALRM is currently blocked, so the signal SIGALRM triggered in 10 seconds by the system call alarm will be blocked
  printf("10 seconds passed so far.\n");
}
