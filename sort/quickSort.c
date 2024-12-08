#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pivot(int p, int r, int arr[]);
void quickSort(int p, int r, int arr[]);
int randomInteger(int low, int high);
void printNumbers(int n, int *arr);

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int n = atoi(argv[1]);
  int arr[n];
  
  for (int i = 0; i < n; i++) arr[i] = randomInteger(1, n);

  printNumbers(n, arr);
  quickSort(0, n - 1, arr);
  printNumbers(n, arr);
  
  return 0;
}

int pivot(int p, int r, int v[]) {
  int c, j, k, t;
  c = v[r]; j = p;
  for (k = p; k < r; k++) {
    if (v[k] <= c) {
     t = v[j], v[j] = v[k], v[k] = t;
      j++;
    }
  }
  v[r] = v[j], v[j] = c;
  return j;
}

void quickSort(int p, int r, int v[]) {
  int j;
  if (p < r) {
    j = pivot(p, r, v);
    quickSort(p, j - 1, v);
    quickSort(j + 1, r, v);
  }
}

int randomInteger(int low, int high) {
  return (rand() % (high - low + 1)) + low;
}

void printNumbers(int n, int *arr) {
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
}
