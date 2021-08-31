#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
  int I;
  float F;
  double D;
  I = INT_MAX;
  F = FLT_MAX;
  D = DBL_MAX;
  printf("The size of an integer is: %lu\n The largest value an integer can hold is: %d\n", sizeof(I), I );
  printf("The size of a float is: %lu\n The largest value a float can hold is: %f\n", sizeof(F), F );
  printf("The size of a float is: %lu\n The largest value a float can hold is: %f\n", sizeof(D), D );
  return 0;
}
