#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
  srand(time(NULL));

  int x;
  int y;
  int z;

  double dx;
  double dy;
  double dz;
  
  for (int i = 0; i < 20; i++) {
    x = rand();
    y = 234;
    z = rand();;

    dx = (double)x;
    dy = (double)y;
    dz = (double)z;

    if (dx/dx != dz/dz) {
      printf("%f\n", dx);
      printf("%f\n", dy);
      printf("%f\n", dz);
      return 1;
    }
  }

  printf("No Issues!\n");
  return 0;
}

