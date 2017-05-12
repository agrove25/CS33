#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y) {
  int sum;
  int overflow = __builtin_add_overflow(x, y, &sum);
  
  (overflow && !(x & INT_MIN) && (sum = INT_MAX)); 
  (overflow && (x & INT_MIN) && (sum = INT_MIN)); 

  return sum;
}

/* Testing */

/*
void printTest(int x, int y) {
  printf("%i + %i = %i\n\n", x, y, saturating_add(x, y));
}

int main(void) {
  printTest(INT_MAX, 0);
  printTest(INT_MAX, -4);
  printTest(INT_MAX, 2);

  printTest(0, 0);
  printTest(0, 2);
  printTest(2, 2);
  printTest(0, -2);
  printTest(-2, -2);

  printTest(INT_MIN, 0);
  printTest(INT_MIN, -1);
  printTest(INT_MIN, 2);
}
*/
