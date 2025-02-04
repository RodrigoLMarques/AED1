/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 3176 - Time de Duendes
  Observações: Usando lista e bubble sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 21;

typedef struct TList {
  char *name;
  int age;
  struct TList *next;
} List;

List* insert(char* name, int age, List** last);
void sort(List *list);
void print_teams(List *head, int n);

int main() {
  List *head = (List*) malloc(sizeof(List));
  head->next = NULL;
  List *last = head; 
  
  int n, age;
  char name[MAX_LENGTH];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s %d", name, &age);
    last = insert(name, age, &last);
  }

  sort(head);
  print_teams(head, n);
  
  return 0;
}

List* insert(char* name, int age, List** last) {
  List *new_cell = (List*) malloc(sizeof(List));
  new_cell->name = (char*) malloc(MAX_LENGTH * sizeof(char));
  strcpy(new_cell->name, name);
  new_cell->age = age;
  new_cell->next = NULL;
  (*last)->next = new_cell;
  return new_cell;
}

int is_young(List* a, List*b) {
  if ((a->age > b->age)) return 1;
  if ((a->age == b->age && strcmp(a->name, b->name) < 0)) return 1;
  return 0;
}

void sort(List *head) {
  char temp_name[MAX_LENGTH];
  int temp_age;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (is_young(q, p)) {
        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);

        temp_age = p->age;
        p->age = q->age;
        q->age = temp_age;
      }
    }
  }
}

void print_teams(List *head, int n) {
  int teams_count = n / 3;

  List *leaders = head->next;
  List *deliverers = head->next;
  List *pilots = head->next;

  for (int i = 0; i < teams_count; i++) deliverers = deliverers->next;
  for (int i = 0; i < 2 * teams_count; i++) pilots = pilots->next;

  for (int i = 1; i <= teams_count; i++) {
    printf("Time %d\n", i);
    printf("%s %d\n", leaders->name, leaders->age);
    leaders = leaders->next;

    printf("%s %d\n", deliverers->name, deliverers->age);
    deliverers = deliverers->next;

    printf("%s %d\n", pilots->name, pilots->age);
    pilots = pilots->next;

    printf("\n");
  }
}

