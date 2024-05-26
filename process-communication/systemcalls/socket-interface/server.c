#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> // useful to use htonl and htons

#define ADDRESS "127.0.0.1"
#define PORT_NO 5000
#define BUFFER_SIZE 1025

int main(int argc, char **argv) {
  // create a socket
  int listenFd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET is the TCP/IP protocol
                                                  // SOCK_STREAM is the TCP transfer service
  if (listenFd == -1) {
    perror("Error while opening the socket");
    exit(1);
  }
  printf("Socket has been created ...\n");

  // set the address
  struct sockaddr_in serverAddress;
  memset(&serverAddress, 0, sizeof(serverAddress)); // be sure that the area is cleaned
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr(ADDRESS);
  serverAddress.sin_port = htons(PORT_NO);
  if (bind(listenFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) {
    perror("Error while setting the address to the socket");
    exit(2);
  }
  printf("Address has been set ...\n");

  // set passive mode (server listens) and the maximum pending requests
  if (listen(listenFd, 10)) {
    perror("Error while listening the socket");
    exit(3);
  }
  printf("Listen mode has been set ...\n");

  char sendBuffer[BUFFER_SIZE];
  memset(sendBuffer, 0, sizeof(sendBuffer)); // be sure that the area is cleaned
  for (int i = 0;; i++) {
    // accept a connection from the pending requests
    int connectedFd = accept(listenFd, (struct sockaddr*)NULL, NULL);
    if (connectedFd == -1) {
      perror("Error while accepting a connection from the socket");
      exit(4);
    }
    printf("Connection has been accepted ...\n");

    pid_t pid = fork();
    if (pid == -1) {
      perror("Error while creating the child process");
      exit(5);
    }
    if (pid == 0) {
      // child process
      // useful to perform calculations without blocking other pending requests
      snprintf(sendBuffer, sizeof(sendBuffer), "This is the message to the client %d\n", i);

      // send the message to the socket
      // since I have the file descriptor, I can use the write system call instead of the send one
      if (write(connectedFd, sendBuffer, strlen(sendBuffer)) == -1) {
        perror("Error while writing to the socket");
        exit(6);
      }
      printf("Message \"%s\" has been sent ...\n", sendBuffer);

      // close the socket
      if (close(connectedFd)) {
        perror("Error while closing the socket");
        exit(7);
      }
      printf("Connection has been closed ...\n");

      return EXIT_SUCCESS;
    } else {
      // parent process
      if (close(connectedFd)) {
        perror("Error while closing the socket");
        exit(8);
      }
      printf("Connection has been closed ...\n");
    }
  }

  return EXIT_SUCCESS;
}
