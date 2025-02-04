/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2136 - Amigos do Habay
  Observações: Experimentando o uso de uma struct mais personalizada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct TList {
  char name[100];
  int order;
  struct TList *next;
} List;

List* insert(char* name, int order, List *last);
int is_repeated(List *head, char *name);
void sort(List* head);
char* find_winner_name(List* head);
void print_list(List *list);

int main() {
  char name[100], is_friend[4]; 
  int order = 0;

  List *friend_list = (List*) malloc(sizeof(List));
  List *last_friend = friend_list;

  List *not_friend_list = (List*) malloc(sizeof(List));
  List *last_not_friend = not_friend_list;

  scanf("%s", name);
  while (strcmp(name, "FIM") != 0) {
    scanf("%s", is_friend);

    if (strcmp(is_friend, "YES") == 0) {
      if (!is_repeated(friend_list, name))
        last_friend = insert(name, order++, last_friend);
    } else {
      last_not_friend = insert(name, 0, last_not_friend);
    }

    scanf("%s", name);
  }

  sort(friend_list);
  sort(not_friend_list);
  print_list(friend_list);
  print_list(not_friend_list);

  char* winner_name = find_winner_name(friend_list);

  printf("\nAmigo do Habay:\n%s\n", winner_name);

  return 0;
}

List* insert(char* name, int order, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  strcpy(new_cell->name, name);
  new_cell->order = order;
  last->next = new_cell;
  return new_cell;
}

int is_repeated(List *head, char *name) {
  for (List *p = head->next; p != NULL; p = p->next) {
    if (strcmp(p->name, name) == 0) {
      return 1;
    }
  }
  return 0;
}

int should_swap(List *p, List *q) {
    return strlen(p->name) < strlen(q->name) || 
           (strlen(p->name) == strlen(q->name) && p->order > q->order);
}

char* find_winner_name(List* head) {
  char temp_name[MAX];
  int temp_order;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (should_swap(p, q)) {
        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);
        temp_order = p->order;
        p->order = q->order;
        q->order = temp_order;
      }
    }
  }

  return head->next->name;
}

void sort(List* head) {
  char temp_name[MAX];
  int temp_order;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (strcmp(p->name, q->name) > 0) {
        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);
        temp_order = p->order;
        p->order = q->order;
        q->order = temp_order;
      }
    }
  }
}

void print_list(List *list) {
  for (List *p = list->next; p != NULL; p = p->next) {
    printf("%s\n", p->name);
  }
}
