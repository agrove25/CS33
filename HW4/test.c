#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
  srand(time(NULL));
  
  int x = rand();
  int y = rand();
  int z = rand();

  double dx = (double)x;
  double dy = (double)y;
  double dz = (double)z;
  
  for (int i = 0; i < 50000; i++) {
    x = INT_MAX - 32428972;
    y = rand();
    z = rand();

    dx = (double)x;
    dy = (double)y;
    dz = (double)z;
  
    if ((float)x != (float)dx) {
      printf("%i", x);
      return 1;
    }
  }
  
  printf("No Issues!\n");
  return 0;
}

