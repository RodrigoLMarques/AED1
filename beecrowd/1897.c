/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1897 - Jogo Esperto
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

typedef struct TList {
  int number;
  int operations;
  struct TList *next;
} List;

List* insert(int number, int operations, List *last);
int pop(List* queue, int* operations);
int bfs(int n, int m);

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  int operations = bfs(n, m);

  printf("%d\n", operations);

  return 0;
}

void print_list(List *queue) {
  for (List *p = queue->next; p != NULL; p = p->next) {
    printf("-> %d\n", p->number);
  }
}

int bfs(int n, int m) {
  int operations = 0, visited[MAX] = { 0 };

  List* queue = (List*) malloc(sizeof(List));
  queue->next = NULL;
  List* last = queue;

  last = insert(n, 0, last);
  visited[n] = 1;

  while (queue->next != NULL) {
    int current = pop(queue, &operations);

    if (queue->next == NULL) {
      last = queue;
    }

    int next_numbers[6];
    next_numbers[0] = current * 2;
    next_numbers[1] = current * 3;
    next_numbers[2] = (current % 2 == 0) ? current / 2 : -1;
    next_numbers[3] = (current % 3 == 0) ? current / 3 : -1;
    next_numbers[4] = current + 7;
    next_numbers[5] = current - 7;

    for (int i = 0; i < 6; i++) {
      if (next_numbers[i] == m) {
        return operations + 1;
      }
      if (next_numbers[i] > 0 && next_numbers[i] < MAX && !visited[next_numbers[i]]) {
        last = insert(next_numbers[i], operations + 1, last);
        visited[next_numbers[i]] = 1;
      }
    }    
  }

  return -1;
}


List* insert(int number, int operations, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  new_cell->number = number;
  new_cell->operations = operations;
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

int pop(List* queue, int* operations) {
  List* temp = queue->next;
  int number = temp->number;
  *(operations) = temp->operations;
  queue->next = temp->next;
  free(temp);
  return number;
}