#include <stdio.h>

void calculate_bills(int value);

int main() {
  int N;
  scanf("%d", &N);

  calculate_bills(N);

  return 0;
}

void calculate_bills(int value) {
  int bills[] = {100, 50, 20, 10, 5, 2, 1};
  int count[7] = {0};

  printf("%d\n", value);

  for (int i = 0; i < 7; i++) {
    count[i] = value / bills[i];
    value %= bills[i];
    printf("%d nota(s) de R$ %d,00\n", count[i], bills[i]);
  }
}

