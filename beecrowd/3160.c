/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 3160 - Amigos
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
void remove_list(cell* list);
void print_list(cell *list);
cell* luiggy_friend_list(cell* list1, cell* list2, char name[MAX_VALUE_SIZE]);

int main() {
  char line[MAX_LINE_SIZE], name[MAX_VALUE_SIZE];

  fgets(line, MAX_LINE_SIZE, stdin);
  line[strcspn(line, "\n")] = '\0';
  cell *list1 = str_split(line, " ");

  fgets(line, MAX_LINE_SIZE, stdin);
  line[strcspn(line, "\n")] = '\0';
  cell *list2 = str_split(line, " ");

  scanf("%s", name);

  cell *luiggy_list = luiggy_friend_list(list1, list2, name);

  print_list(luiggy_list);

  remove_list(list1);
  remove_list(list2);
  remove_list(luiggy_list);
}

cell* luiggy_friend_list(cell* list1, cell* list2, char name[MAX_VALUE_SIZE]) {
  cell *merged_list = (cell*) malloc(sizeof(cell));
  cell *last = merged_list;

  int merged = 0;

  for (cell *i = list1->next; i != NULL; i = i->next) {
    if (strcmp(i->value, name) == 0 && merged == 0) {
      for (cell *j = list2->next; j != NULL; j = j->next) {
        insert(j->value, last);
        last = last->next;
      }

      merged = 1;
    }

    insert(i->value, last);
    last = last->next;
  }

  if (merged == 0) {
    for (cell *j = list2->next; j != NULL; j = j->next) {
      insert(j->value, last);
      last = last->next;
    }
  }

  return merged_list;
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

