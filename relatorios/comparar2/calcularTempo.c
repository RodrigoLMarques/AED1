#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInteger(int low, int high);
void insertionSort(int arr[], int n);
void mergeSort(int p, int r, int v[]);
void quickSort(int p, int r, int v[]);

int max = 400000;
int step = 50000;

int main() {
  srand((unsigned)time(NULL));

  clock_t time;
  double seconds;
  int numbers1[max], numbers2[max], numbers3[max];

  for (int i = step; i <= max; i += step) {
    for (int j = i - step; j < i; j++) {
      int n = randomInteger(1, i);
      numbers1[j] = n;
      numbers2[j] = n;
      numbers3[j] = n;
    }

    printf("\n%d Items\n", i);

    time = clock();
    insertionSort(numbers1, i);
    time = clock() - time;

    seconds = ((double)time) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f\n", seconds);

    time = clock();
    mergeSort(0, i - 1, numbers2);
    time = clock() - time;

    seconds = ((double)time) / CLOCKS_PER_SEC;
    printf("Merge Sort: %f\n", seconds);

    time = clock();
    quickSort(0, i - 1, numbers3);
    time = clock() - time;

    seconds = ((double)time) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f\n", seconds);
  }

  return 0;
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
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