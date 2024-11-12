/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2460 - Fila
  Observações: Usando a estrutura de dados Lista
*/

#include <stdio.h>
#include <stdlib.h>

struct TList {
  int id;
  struct TList *next;
};

typedef struct TList List;

void insert(int id, List *last);
void remove_id(int id, List *list);
void remove_list(List* list);
void print_list(List *list);

int main() {
  int m, n, id;

  List *queue = (List*) malloc(sizeof(List));
  List *last = queue;

  scanf("%d", &m);

  for (int i = 0; i < m; i++) {
    scanf("%d", &id);
    insert(id, last);
    last = last->next;
  }

  scanf("%d", &n);

  for (int j = 0; j < n; j++) {
    scanf("%d", &id);
    remove_id(id, queue);
  }

  print_list(queue);
}

void insert(int id, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  new_cell->id = id;
  new_cell->next = last->next;
  last->next = new_cell;
}

void remove_id(int id, List *list) {
  for (List *p = list; p->next != NULL; p = p->next) {
    if (p->next->id == id) {
      List *temp = p->next;
      p->next = temp->next;
      free(temp);
      break;
    }
  }
}

void remove_list(List* list) {
  List* p = list;

  while(p != NULL){
    List* temp = p->next;
    free(p); 
    p = temp;
  }
}

void print_list(List *list) {
  for (List *p = list->next; p != NULL; p = p->next) {
    printf("%d", p->id);

    if (p->next == NULL) {
      printf("\n");
    } else {
       printf(" ");
    }
  }
}
