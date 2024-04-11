#include <stdio.h>

void main() {
  int age;
  printf("Enter the person's age: ");
  int readNumber = scanf("%d", &age);
  if (readNumber == 1) {
    printf("The person's age is %d", age);
  } else {
    printf("Wrong age inserted.");
  }
}
