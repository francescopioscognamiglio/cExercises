#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void myCustomHandler(int signal) {
  printf("handler of %d - start\n", signal);

  static int first = 1;
  if (first) {
    first = 0;
    printf("handler of %d - send %d\n", signal, SIGUSR1);
    kill(getpid(), SIGUSR1);

    printf("handler of %d - send %d\n", signal, SIGUSR2);
    kill(getpid(), SIGUSR2);
  }

  printf("handler of %d - end\n", signal);
}

void main() {
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGUSR1); // add the signal USR1
  sigaddset(&set, SIGUSR2); // add the signal USR2

  struct sigaction action;
  action.sa_flags = 0;
  // the sa_mask contains all the signals to be blocked if triggered while I'm executing the handler
  action.sa_mask = set;
  action.sa_handler = &myCustomHandler;
  sigaction(SIGUSR1, &action, NULL); // configure the handler for the signal USR1

  printf("main - send %d\n", SIGUSR1);
  kill(getpid(), SIGUSR1); // send a signal USR1 to itself
}
