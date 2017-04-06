// 2.64

#include <stdio.h>

int any_odd_one(unsigned x) {
  return !!(x & 0xAAAAAAAA);                    // 0xA = 1010
}

/* Test Cases */

/*
int main(void) {
  unsigned i = 0x00040040;
  printf("%u", any_odd_one(i));
  i = 0x00202000;
  printf("%u", any_odd_one(i));
}
*/
