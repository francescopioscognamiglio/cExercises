#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

int main() {
  FILE* myFile = NULL;

  // open a file in write mode (if it does not exist, create it)
  myFile = fopen("file.test", "w");
  if (myFile == NULL) {
    perror("Error while opening in write mode");
    return errno;
  }

  // write the object
  employee_t e1 = {3.5, 4};
  fwrite(&e1, sizeof(employee_t), 1, myFile);

  // close an opened file
  int r = fclose(myFile);
  if (r != 0) {
    perror("Error while closing");
    return errno;
  }

  return 0;
}
