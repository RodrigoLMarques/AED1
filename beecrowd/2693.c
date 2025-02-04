/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2693 - Van
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct TList {
  char name[MAX];
  char region;
  int cost;
  struct TList *next;
} List;

List* insert(char* name, char region, int cost, List *last);
void sort(List* head);
void print_list(List *list);

int main() {
  int q, cost;
  char name[MAX], region;

  List *head = (List*) malloc(sizeof(List));
  List *last = head;
  
  scanf("%d", &q);

  for (int i = 0; i < q; i++) {
    scanf("%s %c %d", name, &region, &cost);
    last = insert(name, region, cost, last);
  }

  sort(head);
  print_list(head);

  return 0;
}

List* insert(char* name, char region, int cost, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  strcpy(new_cell->name, name);
  new_cell->region = region;
  new_cell->cost = cost;
  last->next = new_cell;
  return new_cell;
}

int should_swap(List *p, List *q) {
    return p->cost > q->cost || 
          (p->cost == q->cost && p->region > q->region) || 
          (p->cost == q->cost && p->region == q->region && strcmp(p->name, q->name) > 0);
}

void sort(List* head) {
  char temp_name[MAX];
  char temp_region;
  int temp_cost;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (should_swap(p, q)) {
        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);

        temp_region = p->region;
        p->region = q->region;
        q->region = temp_region;

        temp_cost = p->cost;
        p->cost = q->cost;
        q->cost = temp_cost;
      }
    }
  }
}

void print_list(List *head) {
  for (List *p = head->next; p != NULL; p = p->next) {
    printf("%s\n", p->name);
  }
}
