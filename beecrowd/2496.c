#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAX 30

typedef struct TList {
  char str[MAX];
  int changes;
  struct TList *next;
} List;

void sort_string(char *str);
int count_changes(char* str, char* sorted_str, int size);
List* insert(char* str, int changes, List *last);
void print_list(List *list);
void free_list(List* list);

int main() {
  List* head = (List*) malloc(sizeof(List));
  head->next = NULL;
  List* last = head;

  int n, m;
  char str[MAX], message[MAX];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    getchar();
    scanf("%s", str);

    char sorted_str[MAX];
    strcpy(sorted_str, str);
    sort_string(sorted_str);


    int changes = count_changes(str, sorted_str, m);

    last = insert(str, changes, last);
  }

  print_list(head);
  free_list(head);

  return 0;
}

List* insert(char* str, int changes, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  strcpy(new_cell->str, str);
  new_cell->changes = changes;
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}


void sort_string(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (str[j] > str[j + 1]) {
        char temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
      }
    }
  }
}

int count_changes(char* str, char* sorted_str, int size) {
  int changes = 0;
  for (int i = 0; i < size; i++) {
    if (str[i] != sorted_str[i])
      changes++;
  }

  return changes;
}

void print_list(List *list) {
  for (List *p = list->next; p != NULL; p = p->next) {
    if (p->changes <= 2) {
      printf("There are the chance.\n");
    } else {
      printf("There aren't the chance.\n");
    }
  }
}

void free_list(List* list) {
  List* current = list;
  while (current != NULL) {
    List* temp = current;
    current = current->next;
    free(temp);
  }
}