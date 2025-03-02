#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int n, int arr[]);
int randomInteger(int low, int high);
void printNumbers(int n, int *arr);

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int n = atoi(argv[1]);
  int arr[n];
  
  for (int i = 0; i < n; i++) arr[i] = randomInteger(1, n);

  printNumbers(n, arr);
  insertionSort(n, arr);
  printNumbers(n, arr);
  
  return 0;
}

void insertionSort(int n, int arr[]) {
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

void printNumbers(int n, int *arr) {
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
}
