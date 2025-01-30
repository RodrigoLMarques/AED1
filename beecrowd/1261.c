#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct TList {
  char key[MAX];
  int value;
  struct TList* next;
} List;

List* insert(char* key, int value, List* last);
int search(char* key, List* head);

int main() {
  List* head = (List*) malloc(sizeof(List));
  head->next = NULL;
  List* last = head;

  int m, n;
  char key[MAX], word[MAX];
  int value, salary;

  while (scanf("%d %d", &m, &n) != EOF) {
    for (int i = 0; i < m; i++) {
      scanf("%s %d", key, &value);
      last = insert(key, value, last);
    }

    for (int i = 0; i < n; i++) {
      salary = 0;

      while (1) {
        scanf("%s", word);
        if (strcmp(word, ".") == 0) break; 
        salary += search(word, head);
      }

      printf("%d\n", salary);
    }
  }

  return 0;
}

List* insert(char* key, int value, List* last) {
  List* new_cell = (List*)malloc(sizeof(List));
  strcpy(new_cell->key, key);
  new_cell->value = value;
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

int search(char* key, List* head) {
  for (List* item = head->next; item != NULL; item = item->next) {
    if (strcmp(item->key, key) == 0) return item->value;
  }
  return 0;
}
