#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

int main() {
  FILE* myFile = NULL;

  // open a file in read mode (if it does not exist, an error is shown)
  myFile = fopen("file.test", "r");
  if (myFile == NULL) {
    perror("Error while opening in read mode");
    return errno;
  }

  // read the object
  employee_t* e1 = malloc(sizeof(employee_t));
  fread(e1, sizeof(employee_t), 1, myFile);
  printf("The employee information is:\n\t- salary: %f\n\t- identifier: %d\n", e1->salary, e1->identifier);

  // close an opened file
  int r = fclose(myFile);
  if (r != 0) {
    perror("Error while closing");
    return errno;
  }

  return 0;
}
