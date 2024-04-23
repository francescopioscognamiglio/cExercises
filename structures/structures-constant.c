#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

int main() {
  const employee_t emp = {3.5, 111};

  // this will fail because you cannot change struct's members
  // since it's constant (constants are unmodifiable)
  emp.salary = 10.5;
  emp.identifier = 333;
}
