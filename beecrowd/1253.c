#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

typedef struct TList {
  char str[MAX];
  struct TList* next;
} List;

List* insert(char* str, List* last);
void print_list(List* list);
void decode(char* str, int size, int k);

int main() {
  int n, k;
  char str[MAX];

  List* head = (List*) malloc(sizeof(List));
  head->next = NULL;
  List* last = head;

  scanf("%d", &n);

  for (int i = 0 ; i < n; i++) {
    scanf("%s", str);
    getchar();
    scanf("%d", &k);

    decode(str, strlen(str), k);
    last = insert(str, last);
  }

  print_list(head);
}

List* insert(char* str, List* last) {
  List* new_cell = (List*) malloc(sizeof(List));
  strcpy(new_cell->str, str);
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

void print_list(List* list) {
  for (List* item = list->next; item != NULL; item = item->next) {
    printf("%s", item->str);
    printf("\n");
  }
}

void decode(char* str, int size, int k) {
  k = k % 26;
  for (int i = 0; i < size; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = ((str[i] - 'A' - k + 26) % 26) + 'A';
    }
  }
}