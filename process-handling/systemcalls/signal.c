#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int count = 0;

void myHandler(int signal) {
  count++;
}

void main() {
  // set a custom handler for the signal USR1
  signal(SIGUSR1, myHandler);

  // set the default behavior for the signal ABRT
  signal(SIGABRT, SIG_DFL);

  // ignore the signal FPE
  signal(SIGFPE, SIG_IGN);

  // try to ignore the SIGKILL, it will fail
  if (signal(SIGKILL, SIG_IGN) == SIG_ERR) {
    printf("You cannot customize nor ignore the SIGKILL signal!\n");
  }
  // try to customize the SIGSTOP, it will fail
  if (signal(SIGSTOP, myHandler) == SIG_ERR) {
    printf("You cannot customize nor ignore the SIGSTOP signal!\n");
  }

  printf("I have the PID %d\n", getpid());

  // wait for an input
  int dummy;
  scanf("%d", &dummy);

  printf("Number of handled signals %d\n", count);
}
