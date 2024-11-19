#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAM = 100000;

int binarySearch(int x, int n, int* v);
int binarySearchRecursive(int x, int e, int d, int* v);
int linearSearch(int x, int n, int *v);

int RandomInteger(int low, int high){
  return (rand() % (high - low + 1)) + low;
}

void bubbleSort(int v[TAM]) {
  int a, b, aux;
  for (a=TAM-1; a>0; a--) {
    for (b=0; b<a; b++) {
      if (v[b]>v[b+1]) {
        aux = v[b];
        v[b] = v[b+1];
        v[b+1] = aux;
      }
    }
  }
}

int main() {
  srand((unsigned)time(NULL));
  int vetor[TAM];
  clock_t t;
  double time;

  for(int i = 0; i < TAM; i++)
    vetor[i] = RandomInteger(0, TAM);

  int target = RandomInteger(0, TAM);

  bubbleSort(vetor);

  t = clock();
  int n1 = binarySearch(target, TAM, vetor);
  t = clock() - t;

  time = ((double)t)/((CLOCKS_PER_SEC/1000));
  printf("binarySearch: %lf\n", time);

  t = clock();
  int n2 = binarySearchRecursive(target, -1, TAM, vetor);
  t = clock() - t;

  time = ((double)t)/((CLOCKS_PER_SEC/1000));
  printf("binarySearchRecursive: %lf\n", time);

  t = clock();
  int n3 = linearSearch(target, TAM, vetor);
  t = clock() - t;

  time = ((double)t)/((CLOCKS_PER_SEC/1000));
  printf("linearSearch: %lf\n", time);

  printf("%d\n", n1);
  printf("%d\n", n2);
  printf("%d\n", n3);

  return 0;
}

int binarySearch(int x, int n, int* v) {
  int e = -1, d = n, m;

  while (e < d - 1) {
    m = (e + d) / 2;
    if (v[m] < x) e = m;
    else d = m;
  }

  return d;
}

int binarySearchRecursive(int x, int e, int d, int* v) {
  if (e == (d - 1)) return d;
  int m = (e + d) / 2;
  if (v[m] < x) return binarySearchRecursive(x, m, d, v);
  return binarySearchRecursive(x, e, m, v);
}

int linearSearch(int x, int n, int *v) {
  int i = 0;
  while (i < n && v[i] < x) i++;
  return i;
}

