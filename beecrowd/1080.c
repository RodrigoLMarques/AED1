/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1080 - Maior e Posição
  Observações: Usando Heap Max
*/

#include <stdio.h>

#define MAX 100

typedef struct {
  int value;
  int index; // (1-based)
} Element;

void heapify(Element arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].value > arr[largest].value) {
      largest = left;
    }
    if (right < n && arr[right].value > arr[largest].value) {
      largest = right;
    }

    if (largest != i) {
      Element temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;

      heapify(arr, n, largest);
    }
}

void buildHeap(Element arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

int main() {
  Element arr[MAX];

  for (int i = 0; i < MAX; i++) {
    scanf("%d", &arr[i].value);
    arr[i].index = i + 1;
  }

  buildHeap(arr, MAX);

  printf("%d\n", arr[0].value);
  printf("%d\n", arr[0].index);

  return 0;
}
