#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 51

typedef struct TList {
  char str[MAX];
  int number;
  struct TList *next;
} List;

List* insert(char *str, int number, List *last);
void print_list(List *head);
void identify_numbers(List *head);

int main() {
  int n;
  char str[MAX];

  List* head = (List*) malloc(sizeof(List));
  List* last = head;

  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++) {
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;
    last = insert(str, 0, last);
  }

  identify_numbers(head);
  print_list(head);

  return 0;
}

List* insert(char *str, int number, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  new_cell->number = number;
  strcpy(new_cell->str, str);
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

void print_list(List *head) {
  for (List* item = head->next; item != NULL; item = item->next)
    printf("%d\n", item->number);
}

void identify_numbers(List *head) {
  char *str = (char*) malloc(MAX * sizeof(char));
  for (List* item = head; item != NULL; item = item->next) {
    strcpy(str, item->str);
    
    if (strlen(str) > 3) {
      item->number = 3;
    } else if ((str[0] == 'o' && str[1] == 'n') || (str[0] == 'o' && str[2] == 'e') || (str[1] == 'n' && str[2] == 'e')) {
      item->number = 1;
    } else if ((str[0] == 't' && str[1] == 'w') || (str[0] == 't' && str[2] == 'o') || (str[1] == 'w' && str[2] == 'o')) {
      item->number = 2;
    }
  }
}
