#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

void callByValue(employee_t emp) {
  emp.salary = 35.3;
  emp.identifier = 1111;
}

void callByReference(employee_t *emp) {
  emp->salary = 22.7;
  emp->identifier = 1232;
}

int main() {
  employee_t *emp = malloc(sizeof(employee_t));

  callByValue(*emp);
  printf("The employee has:\n\t-salary: %f\n\t-identifier: %d\n", emp->salary, emp->identifier);

  callByReference(emp);
  printf("The employee has:\n\t-salary: %f\n\t-identifier: %d\n", emp->salary, emp->identifier);
}
