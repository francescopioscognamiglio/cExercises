#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

int main() {
  employee_t *emp = malloc(sizeof(employee_t));

  // set values via dot operator
  (*emp).salary = 10.5;
  (*emp).identifier = 333;
  printf("The employee has:\n\t-salary: %f\n\t-identifier: %d\n", (*emp).salary, (*emp).identifier);

  // set values via arrow operator
  emp->salary = 3.7;
  emp->identifier = 567;
  printf("The employee has:\n\t-salary: %f\n\t-identifier: %d\n", emp->salary, emp->identifier);
}
