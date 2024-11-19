#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

#define TAM 10

// 1 8 13 17
// e = 1
// d = 2

int RandomInteger(int low, int high){
  return (rand() % (high - low + 1)) + low;
}

void bubbleSort (int v[TAM]) {
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

// 4 3 2| 1
// 3 2| 1 4
// 2| 1 3 4
// 1 2 3 4

int main(){
  srand((unsigned)time(NULL));

  clock_t t;
  int vetor[TAM];

  for(int i = 0; i < TAM; i++)
    vetor[i] = RandomInteger(0, TAM);

  for(int i = 0; i < TAM; i++)
    printf("%d ", vetor[i]);
  printf("\n");

  t = clock();

  bubbleSort(vetor);

  for(int i = 0; i < TAM; i++)
    printf("%d ", vetor[i]);
  printf("\n");

  t = clock() - t;

  printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
}
