#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n);
int randomInteger(int low, int high);

int main() {
  srand((unsigned)time(NULL));
  int v[10];

  for (int i = 0; i < 10; i++) v[i] = randomInteger(1, 10);
  for (int i = 0; i < 10; i++) printf("%d ", v[i]);
  printf("\n");

  insertionSort(v, 10);

  for (int i = 0; i < 10; i++) printf("%d ", v[i]);
  printf("\n");
  
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

int randomInteger(int low, int high) {
  return (rand() % (high - low + 1)) + low;
}
