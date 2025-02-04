/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1861 - O Hall dos Assassinos
  Observações:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TList {
  char* name;
  int number;
  struct TList *next;
} List;

List* insert(char* name, int number, List *last);
List* find_by_name(char* name, List* head);
void remove_by_name(char* name, List* head);
void sort(List* head);
void print_list(List *head);

int main() {
  char murderer[11], victim[11];

  List* murderer_list = (List*) malloc(sizeof(List));
  List* last_murderer = murderer_list;

  List* victim_list = (List*) malloc(sizeof(List));
  List* last_victim = victim_list;

  while (scanf("%s %s", murderer, victim) != EOF) {
    if (strcmp(murderer, "0") == 0 && strcmp(victim, "0") == 0) break;

    List* has_murderer = find_by_name(murderer, murderer_list);

    if (has_murderer != NULL) {
      has_murderer->number++;
    } else {
      List* is_victim = find_by_name(murderer, victim_list);
      if (is_victim == NULL) {
        last_murderer = insert(murderer, 1, last_murderer);
      }
    }

    last_victim = insert(victim, 0, last_victim);
    remove_by_name(victim, murderer_list);
  }

  sort(murderer_list);
  print_list(murderer_list);

  return 0;
}

List* insert(char* name, int number, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  int str_size = strlen(name) + 1;
  new_cell->name = (char*) malloc(str_size * sizeof(char));
  strcpy(new_cell->name, name);
  new_cell->number = number;
  new_cell->next = last->next;
  last->next = new_cell;
  return new_cell;
}

List* find_by_name(char* name, List* head) {
  for (List* item = head->next; item != NULL; item = item->next) {
    if (strcmp(item->name, name) == 0) {
      return item;
    }
  }

  return NULL;
}

void remove_by_name(char* name, List* head) {
  List* prev = head;
  List* current = head->next;
  
  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      prev->next = current->next;
      free(current->name);
      free(current);
      break;
    }
    prev = current;
    current = current->next;
  }
}

void sort(List* head) {
  char temp_name[11];
  int temp_number;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (strcmp(p->name, q->name) > 0) {
        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);
        temp_number = p->number;
        p->number = q->number;
        q->number = temp_number;
      }
    }
  }
}

void print_list(List *head) {
  printf("HALL OF MURDERERS\n");
  for (List *p = head->next; p != NULL; p = p->next) {
    printf("%s %d\n", p->name, p->number);
  }
}