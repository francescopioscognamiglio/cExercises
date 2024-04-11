#include <stdio.h>

void main() {
  int n = 2;
  int result1 = 2 * n++;
  printf("%d\n", result1);
  printf("%d\n", n);
  n = 2;
  int result2 = 2 * ++n;
  printf("%d\n", result2);
  printf("%d\n", n);
}
