/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1340 - Eu Posso Adivinhar a Estrutura de Dados!
  Observações:
*/

// TODO

#include <stdlib.h>
#include <stdio.h>

typedef struct TList {
  int value;
  struct TList *next;
} List;

void queuePush(List** list, int number);
void stackPush(List **stack, int number);
void heapPush(int v[], int m);

int main() {
  int n;

  while (scanf("%d", &n) != EOF) {
    List* queue;
    List* stack;
    int heap[n];

    for (int i = 0; i < n; i++) {
      int action, value;
      scanf("%d %d", &action, &value);

      // Push
      if (action == 1) {
        queuePush(queue, value);
        stackPush(stack, value);
        heapPush(heap, value);

      // Pop
      } else if (action == 2) {

      }
    }
  }
}

void queuePush(List** list, int number) {
  List* newItem = (List*) malloc(sizeof(List));
  newItem->next = NULL;
  newItem->value = number;
  (*list)->next = newItem;
}

void queuePop(List *p) {
  List *temp  = p->next;
  p->next = temp->next;
  free(temp);
}

void stackPush(List **stack, int number) {
  List *newItem = (List*) malloc(sizeof(List));
  newItem->value = number;
  newItem->next = *stack;
  *stack = newItem;
}

int stackPop(List **stack) {
  if (*stack == NULL) return -1;
  List *temp = *stack;
  char value = temp->value;
  *stack = temp->next;
  free(temp);
  return value;
}

void heapPush(int v[], int m) {
  int f = m + 1;
  while (f > 1 && v[f /2] < v[f ]) {
    int t = v[f /2]; 
    v[f /2] = v[f ]; 
    v[f] = t;
    f = f /2;
  }
}

int heapPop(int v[]) {
  int t, f = 2, m = v[0];
  while (f <= m) {
    if (f < m && v[f] < v[f + 1]) ++f;
    if (v[f/2] >= v[f]) break;
    t = v[f /2]; 
    v[f /2] = v[f ]; 
    v[f ] = t;
    f *= 2;
  }
  return m;
}