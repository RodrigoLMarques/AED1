/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1077 - 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TList {
  char value;
  struct TList *next;
};

typedef struct TList List;

void insert(List **list, char c);

int main() {
  int n;
  char str[1001];

  for (int i = 0; i < n; i++) {
    scanf("%d", &n);

    List* list = (List*)malloc(sizeof(List));

    for (size_t j = 0; j < strlen(str); i++) {
      insert(&list, str[j]);
    }
  }

  return 0;
}

void insert(List** list, char c) {
  List* newItem = (List*) malloc(sizeof(List));
  newItem->next = NULL;
  newItem->value = c;
  (*list)->next = newItem;
}



