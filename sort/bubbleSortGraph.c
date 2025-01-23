#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int tam = 10000;

int RandomInteger(int low, int high){
  return (rand() % (high - low + 1)) + low;
}

void bubbleSort (int v[tam]) {
  for (int a = tam - 1; a > 0; a--) {
    for (int b = 0; b < a; b++) {
      if (v[b] > v[b + 1]) {
        int aux = v[b];
        v[b] = v[b + 1];
        v[b + 1] = aux;
      }
    }
  }
}

int main(){
  srand((unsigned)time(NULL));

  for (int i = 0; i < 100; i++) {
    clock_t t;
    int vetor[tam];

    for(int j = 0; j < tam; j++) {
      vetor[j] = RandomInteger(0, tam);
    }

    t = clock();
    bubbleSort(vetor);
    t = clock() - t;

    double time = ((double)t)/((CLOCKS_PER_SEC/1000));

    printf("%d: %lf\n", tam, time);

    tam += 10000;
  }
}
