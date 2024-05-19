#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main() {
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGINT); // add the signal triggered by CTRL+C
  sigaddset(&set, SIGUSR1); // add the signal USR2

  // block some signals
  // start critical section
  sigprocmask(SIG_BLOCK, &set, NULL);

  // check if SIGINT is pending
  sigset_t pset;
  sigpending(&pset);
  printf("SIGINT pending: %d\n", sigismember(&pset, SIGINT));

  printf("critical section - start\n");
  fflush(stdout);
  kill(getpid(), SIGINT); // SIGINT should kill, but it has been set as blocked signal
  kill(getpid(), SIGUSR1);
  printf("critical section - still inside\n");
  fflush(stdout);

  // check if SIGINT is pending
  sigpending(&pset);
  printf("SIGINT pending: %d\n", sigismember(&pset, SIGINT));

  // end critical section
  // unblock the blocked signals
  sigprocmask(SIG_UNBLOCK, &set, NULL);
}
