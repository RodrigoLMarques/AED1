/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2633 - Churras no Yuri
  Observações: Usando listas e bubble sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

typedef struct TList {
  char meat[MAX];
  int validity;
  struct TList* next; 
} List;

List* insert(char* meat, int validity, List *last);
void sort(List *head);
void print_list(List *head);
void remove_list(List* head);

int main() {
  int n, validity;
  char meat[MAX];
  
  while (scanf("%d", &n) != EOF) {
    List* head = (List*) malloc(sizeof(List));
    List* last = head;

    for (int i = 0; i < n; i++) {
      scanf("%s %d", meat, &validity);
      last = insert(meat, validity, last);
    }
    sort(head);
    print_list(head);
    remove_list(head);
  }

  return 0;
}

List* insert(char* meat, int validity, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  strcpy(new_cell->meat, meat);
  new_cell->validity = validity;
  new_cell->next = last->next;
  last->next = new_cell;
  return new_cell;
}

void sort(List *head) {
  char temp_meat[MAX];
  int temp_validaty;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (p->validity > q->validity) {
        strcpy(temp_meat, p->meat);
        strcpy(p->meat, q->meat);
        strcpy(q->meat, temp_meat);

        temp_validaty = p->validity;
        p->validity = q->validity;
        q->validity = temp_validaty;
      }
    }
  }
}

void print_list(List *head) {
  for (List *p = head->next; p != NULL; p = p->next) {
    printf("%s", p->meat);

    if (p->next == NULL) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
}

void remove_list(List* head) {
  List* p = head;

  while(p != NULL){
    List* temp = p->next;
    free(p); 
    p = temp;
  }
}