#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

int main() {
  employee_t emp = {3.5, 111};

  emp.salary = 10.5;
  emp.identifier = 333;
  printf("The employee has:\n\t-salary: %f\n\t-identifier: %d\n", emp.salary, emp.identifier);
}
