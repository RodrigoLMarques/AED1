#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int p, int q, int r, int arr[]);
void mergeSort(int p, int r, int arr[]);
int randomInteger(int low, int high);
void printNumbers(int n, int *arr);

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int n = atoi(argv[1]);
  int arr[n];
  
  for (int i = 0; i < n; i++) arr[i] = randomInteger(1, n);

  printNumbers(n, arr);
  mergeSort(0, n, arr);
  printNumbers(n, arr);
  
  return 0;
}

void merge(int p, int q, int r, int arr[]) {
  int i, j, k, *w;
  w = malloc((r - p) * sizeof(int));

  i = p; j = q; k = 0;
  while (i < q && j < r) {
    if (arr[i] <= arr[j]) w[k++] = arr[i++];
    else w[k++] = arr[j++];
  }

  while (i < q)  w[k++] = arr[i++];
  while (j < r) w[k++] = arr[j++];

  for (i = p; i < r; i++) arr[i] = w[i - p];

  free(w);
}

void mergeSort(int p, int r, int arr[]) {
  if (p >= r - 1) return;

  int q = (p + r) / 2;
  mergeSort(p, q, arr);
  mergeSort(q, r, arr);
  merge(p, q, r, arr);
  
}

int randomInteger(int low, int high) {
  return (rand() % (high - low + 1)) + low;
}

void printNumbers(int n, int *arr) {
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
}
