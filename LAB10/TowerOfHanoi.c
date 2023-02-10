#include <stdio.h>

void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod) {
  if (n == 1) {
    printf("\nDisc 1 from %d to %d", from_rod, to_rod);
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  printf("\nDisc %d from %d to %d", n, from_rod, to_rod);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

void TowerHanoi(int n, int from_rod, int to_rod) {
  int aux_rod = 6 - from_rod - to_rod;
  towerOfHanoi(n, from_rod, to_rod, aux_rod);
}

int main() {
  TowerHanoi(3, 1, 3);
  return 0;
}
