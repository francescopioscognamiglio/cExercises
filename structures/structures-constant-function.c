#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

void cannotModify(const employee_t emp) {
  emp.salary = 30;
  emp.identifier = 23;
}

int main() {
  const employee_t emp = {3.5, 111};

  // this will fail because you cannot change struct's members
  // since it's constant (unmodifiable)
  cannotModify(emp);
}
