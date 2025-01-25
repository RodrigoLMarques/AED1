/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1259 - Pares e Ímpares
  Observações: Listas e Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 51

typedef struct TList {
  int number;
  struct TList* next;
} List;

List* insert(int number, List* last);
void sort_asc(List* head);
void sort_desc(List* head);
void print_list(List* list);
void free_list(List* list);

int main() {
  int n;

  List* pairHead = (List*)malloc(sizeof(List));
  pairHead->next = NULL;
  List* pairLast = pairHead;

  List* oddHead = (List*)malloc(sizeof(List));
  oddHead->next = NULL;
  List* oddLast = oddHead;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int number;
    scanf("%d", &number);

    if (number % 2 == 0) {
      pairLast = insert(number, pairLast);
    } else {
      oddLast = insert(number, oddLast);
    }
  }

  sort_asc(pairHead);
  sort_desc(oddHead);
  print_list(pairHead);
  print_list(oddHead);
  free_list(pairHead);
  free_list(oddHead);

  return 0;
}

List* insert(int number, List* last) {
  List* new_cell = (List*)malloc(sizeof(List));
  new_cell->number = number;
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

void print_list(List* list) {
  for (List* item = list->next; item != NULL; item = item->next) {
    printf("%d", item->number);
    printf("\n");
  }
}

void free_list(List* list) {
  List* current = list;
  while (current != NULL) {
    List* temp = current;
    current = current->next;
    free(temp);
  }
}

void swap(List* a, List* b) {
  int temp = a->number;
  a->number = b->number;
  b->number = temp;
}

List* getTail(List* head) {
  while (head != NULL && head->next != NULL) {
    head = head->next;
  }
  return head;
}

List* partitionAsc(List* p, List* r) {
  int pivot_value = r->number;
  List* i = p;

  for (List* j = p; j != r; j = j->next) {
    if (j->number <= pivot_value) {
      i = (i == NULL) ? p : i->next;
      swap(i, j);
    }
  }
  swap(i, r);
  return i;
}

void quickSortAsc(List* p, List* r) {
  if (p != r && p != NULL && r != NULL) {
    List* q = partitionAsc(p, r);
    quickSortAsc(p, q);
    quickSortAsc(q->next, r);
  }
}

void sort_asc(List* head) {
  quickSortAsc(head, getTail(head));
}

List* partitionDesc(List* p, List* r) {
  int pivot_value = r->number;
  List* i = p;

  for (List* j = p; j != r; j = j->next) {
    if (j->number <= pivot_value) {
      i = (i == NULL) ? p : i->next;
      swap(i, j);
    }
  }
  swap(i, r);
  return i;
}

void quickSortDesc(List* p, List* r) {
  if (p != r && p != NULL && r != NULL) {
    List* q = partitionDesc(p, r);
    quickSortDesc(p, q);
    quickSortDesc(q->next, r);
  }
}

void sort_desc(List* head) {
  quickSortDesc(head, getTail(head));
}
