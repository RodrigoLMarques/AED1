/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1548 - Fila do Recreio
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

typedef struct TList {
  int number;
  struct TList* next;
} List;

List* insert(int number, List* last);
void sort(List* head);
int count_not_changes(List* list, List* sorted_list);
void free_list(List* list);
List* copy_list(List* head);

int main() {
  int M, P, number;

  scanf("%d", &M);

  for (int i = 0; i < M; i++) {
    List* head = (List*)malloc(sizeof(List));
    List* last = head;

    scanf("%d", &P);

    for (int j = 0; j < P; j++) {
      scanf("%d", &number);
      last = insert(number, last);
    }

    List* sorted_list = copy_list(head);
    sort(sorted_list);

    int count = count_not_changes(head->next, sorted_list->next);
    printf("%d\n", count);

    free_list(head);  
    free_list(sorted_list);  
  }

  return 0;
}

List* insert(int number, List* last) {
  List* new_cell = (List*)malloc(sizeof(List));
  new_cell->number = number;
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

void sort(List* head) {
  int temp_number;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (p->number < q->number) {
        temp_number = p->number;
        p->number = q->number;
        q->number = temp_number;
      }
    }
  }
}

int count_not_changes(List* list, List* sorted_list) {
    List* p = list;
    List* q = sorted_list;
    int not_changes = 0;

    while (p != NULL && q != NULL) {
        if (p->number == q->number)
            not_changes++;
        p = p->next;
        q = q->next;
    }

    return not_changes;
}

void free_list(List* list) {
  List* current = list;
  while (current != NULL) {
    List* temp = current;
    current = current->next;
    free(temp);
  }
}

List* copy_list(List* head) {
  List* new_head = (List*)malloc(sizeof(List));
  new_head->next = NULL;
  List* last = new_head;

  for (List* p = head->next; p != NULL; p = p->next) {
    last = insert(p->number, last);
  }

  return new_head;
}
