#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int p, int q, int r, int v[]);
void mergeSort(int p, int r, int v[]);
int randomInteger(int low, int high);

int main() {
  srand((unsigned)time(NULL));
  int v[10];
  
  for (int i = 0; i < 10; i++) v[i] = randomInteger(1, 10);
  for (int i = 0; i < 10; i++) printf("%d ", v[i]);
  printf("\n");

  mergeSort(0, 10, v);

  for (int i = 0; i < 10; i++) printf("%d ", v[i]);
  printf("\n");
  

  return 0;
}

void merge(int p, int q, int r, int v[]) {
  int i, j, k, *w;
  w = malloc((r - p) * sizeof(int));

  i = p; j = q; k = 0;
  while (i < q && j < r) {
    if (v[i] <= v[j]) w[k++] = v[i++];
    else w[k++] = v[j++];
  }

  while (i < q)  w[k++] = v[i++];
  while (j < r) w[k++] = v[j++];

  for (i = p; i < r; i++) v[i] = w[i - p];

  free(w);
}

void mergeSort(int p, int r, int v[]) {
  if (p >= r - 1) return;

  int q = (p + r) / 2;
  mergeSort(p, q, v);
  mergeSort(q, r, v);
  merge(p, q, r, v);
  
}

int randomInteger(int low, int high) {
  return (rand() % (high - low + 1)) + low;
}
