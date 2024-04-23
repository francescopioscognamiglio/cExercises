#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float salary;
  int identifier;
} employee_t;

void increase(employee_t *emp, int length) {
  for (int i = 0; i < length; i++) {
    emp[i].salary += 10.5;
  }
}

void print(const employee_t *emp, int length) {
  for (int i = 0; i < length; i++) {
    printf("Employee %i:\n\t-salary: %f\n\t-identifier: %d\n", i, emp[i].salary, emp[i].identifier);
  }
}

int main() {
  employee_t emps[5] = {{3.5, 111}, {1.5, 121}, {4.8, 341}, {9.33, 221}, {5.5, 312}};

  printf("Before operations...\n");
  print(emps, 5);
  increase(emps, 5);
  printf("After operations...\n");
  print(emps, 5);

  employee_t *pEmps = malloc(sizeof(employee_t)*5);
  printf("Before operations...\n");
  print(pEmps, 5);
  increase(pEmps, 5);
  printf("After operations...\n");
  print(pEmps, 5);
}
