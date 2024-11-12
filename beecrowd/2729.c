/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2729 - Lista de Compras
  Observações: Usando a estrutura de dados Lista
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_LINE_SIZE = 1000;
const int MAX_VALUE_SIZE = 100;

struct cell {
  char value[100];
  struct cell *next;
};

typedef struct cell cell;

cell* str_split(char *str, char* delim);
void insert(char *str, cell *p);
void remove_cell(cell *p);
void remove_list(cell* list);
void print_list(cell *list);
void remove_duplicates(cell* list);
void sort_alphabetic(cell *list);

int main() {
  int n;
  char line[MAX_LINE_SIZE];

  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++) {
    fgets(line, MAX_LINE_SIZE, stdin);
    line[strcspn(line, "\n")] = '\0';

    cell *list = str_split(line, " ");

    remove_duplicates(list);
    sort_alphabetic(list);
    print_list(list);
    remove_list(list);
  }
}

cell* str_split(char *str, char* delim) {
  char* token = strtok(str, delim);

  cell *head = (cell*) malloc(sizeof(cell));
  cell *last = head;

  while(token != NULL) {
    insert(token, last);
    token = strtok(NULL, delim);
    last = last->next;
  }

  return head;
}

void insert(char *str, cell *p) {
  cell *new_cell;
  new_cell = (cell*) malloc(sizeof(cell));
  strcpy(new_cell->value, str);
  new_cell->next = p->next;
  p->next = new_cell;
}

void remove_cell(cell *p) {
  cell *temp  = p->next;
  p->next = temp->next;
  free(temp);
}

void remove_list(cell* list) {
  cell* p = list;

  while(p != NULL){
    cell* temp = p->next;
    free(p); 
    p = temp;
  }
}

void print_list(cell *list) {
  for (cell *p = list->next; p != NULL; p = p->next) {
    printf("%s", p->value);

    if (p->next == NULL) {
      printf("\n");
    } else {
       printf(" ");
    }
  }
}

void remove_duplicates(cell *list) {
  for (cell *i = list->next; i != NULL; i = i->next) {
    cell *j = i;
    while (j->next != NULL) {
      if (strcmp(i->value, j->next->value) == 0) {
        remove_cell(j);
      } else {
        j = j->next;
      }
    }
  }
}

void sort_alphabetic(cell *list) {
  for (cell* i = list->next; i->next != NULL; i = i->next) {
    int swapped = 0;

    for (cell* j = list->next; j->next != NULL; j = j->next) {
      if (strcmp(j->value, j->next->value) > 0) {
        char aux[MAX_VALUE_SIZE];

        strcpy(aux, j->value);
        strcpy(j->value, j->next->value);
        strcpy(j->next->value, aux);
        
        swapped = 1;
      }
    }

    if (!swapped)
      break;
  }
}
