#include <stdio.h>
#include <stdlib.h>

union point_t {
  double x;
  double y;
};

typedef union {
  double x;
  double y;
} point2_t;

void main() {
  union {double x; double y;} pointn1 = {5.8}, pointn2 = {3.3};

  union point_t point1 = {3.7}, point2 = {2.1};

  point2_t point21 = {1.6}, point22 = {6.2};

  printf("Values from the 1st union: %lf  and %lf\n", pointn1.x, pointn1.y);
  printf("Values from the 2nd union: %lf and %lf\n", point1.x, point1.y);
  printf("Values from the 3th union: %lf and %lf\n", point21.x, point21.y);
}
