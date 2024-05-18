#include <unistd.h>
#include <stdio.h>

void main() {
  char *argv[4];
  argv[0] = "print_env"; // the first argument is always the file name
  argv[1] = "first arg";
  argv[2] = "second arg";
  argv[3] = NULL; // the last argument is always NULL

  char *envp[3];
  envp[0] = "key1=val1";
  envp[1] = "key2=val2";
  envp[2] = NULL; // the last argument is always NULL

  // call the external script
  execve("print_env", argv, envp);

  // if the execve system call succeded,
  //   then this program is no more executed
  // otherwise continue with the following instructions
  perror("execve failed");
}
