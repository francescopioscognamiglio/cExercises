#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> // useful to use htonl and htons
#include <netdb.h> // useful to use gethostbyname

#define ADDRESS "127.0.0.1"
#define PORT_NO 5000
#define BUFFER_SIZE 1025

int main(int argc, char **argv) {
  // create a socket
  int readFd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET is the TCP/IP protocol
                                                // SOCK_STREAM is the TCP transfer service
  if (readFd == -1) {
    perror("Error while opening the socket");
    exit(1);
  }
  printf("Socket has been created ...\n");

  // set the address
  struct sockaddr_in serverAddress;
  bzero((char*)&serverAddress, sizeof(serverAddress)); // be sure that the area is cleaned
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr(ADDRESS);
  serverAddress.sin_port = htons(PORT_NO);
  // connect to the socket (opened by the server)
  if (connect(readFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) {
    perror("Error while connecting to the socket");
    exit(3);
  }
  printf("Connection has been established ...\n");

  char readBuffer[BUFFER_SIZE];
  memset(readBuffer, 0, sizeof(readBuffer)); // be sure that the area is cleaned

  // read the message from the socket
  // since I have the file descriptor, I can use the read system call instead of the recv one
  int readBytes = read(readFd, readBuffer, BUFFER_SIZE);
  if (readBytes == -1) {
    perror("Error while reading from the socket");
    exit(4);
  }
  printf("Read %d bytes from the server ...\n", readBytes);
  printf("Message received from the server: %s\n", readBuffer);

  // close the socket
  if (close(readFd)) {
    perror("Error while closing the socket");
    exit(5);
  }

  return EXIT_SUCCESS;
}
