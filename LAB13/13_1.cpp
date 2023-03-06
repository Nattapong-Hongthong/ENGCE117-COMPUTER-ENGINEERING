#include <stdio.h>
#include <stdlib.h>

int* knapsackDP(int* w, int* v, int n, int wx) {
  int* dp = (int*)calloc(wx + 1, sizeof(int));
  int* x = (int*)calloc(n, sizeof(int));
  for (int i = 1; i <= n; i++) {
    for (int j = wx; j >= w[i - 1]; j--) {
      dp[j] = (dp[j - w[i - 1]] + v[i - 1] > dp[j]) ? dp[j - w[i - 1]] + v[i - 1] : dp[j];
    }
  }
  int j = wx;
  for (int i = n; i >= 1; i--) {
    if (dp[j] == dp[j - w[i - 1]] + v[i - 1]) {
      x[i - 1] = 1;
      j -= w[i - 1];
    }
  }
  free(dp);
  return x;
}

int main() {
  int n = 5, wx = 11;
  int w[5] = {1, 2, 5, 6, 7};
  int v[5] = {1, 6, 18, 22, 28};
  int* x = knapsackDP(w, v, n, wx);
  printf("Solution: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", x[i]);
  }
  printf("\n"); 
  free(x);
  return 0;
} 