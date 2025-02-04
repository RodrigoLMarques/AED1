/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2482 - Etiquetas de Noel
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct TList {
  char language[MAX];
  char message[MAX];
  struct TList *next;
} List;

List* insert(char* language, char* message, List *last);
void print_list(List *list);
char* find_message(char* language, List* head);

int main() {
  int n, m;
  char language[MAX], message[MAX], name[MAX];

  scanf("%d", &n);
  getchar();

  List* head = (List*) malloc(sizeof(List));
  List* last = head;

  for (int i = 0; i < n; i++) {
    fgets(language, MAX, stdin);
    language[strcspn(language, "\n")] = 0;

    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = 0;

    last = insert(language, message, last);
  }

  scanf("%d", &m);
  getchar();

  for (int i = 0; i < m; i++) {
    fgets(name, MAX, stdin);
    name[strcspn(name, "\n")] = 0;

    fgets(language, MAX, stdin);
    language[strcspn(language, "\n")] = 0;

    strcpy(message, find_message(language, head));
    printf("%s\n%s\n\n", name, message);
  }

  return 0;
}

List* insert(char* language, char* message, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  strcpy(new_cell->language, language);
  strcpy(new_cell->message, message);
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

char* find_message(char* language, List* head) {
  for (List* item = head->next; item != NULL; item = item->next) {
    if (strcmp(item->language, language) == 0) {
      return item->message;
    }
  }

  return "ERROR";
}

