/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1244 - Ordenação por Tamanho
  Observações: Listas e Bubble Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

typedef struct TList {
  char word[MAX];
  struct TList* next;
} List;

List* insert(char* word, List* last);
void print_list(List* list);
void free_list(List* list);
void sort_words(List* head);

int main() {
  int n;

  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++) {
    List* head = (List*)malloc(sizeof(List));
    head->next = NULL;

    char line[MAX];
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';

    List* last = head;
    char* word = strtok(line, " ");
    while (word != NULL) {
      last = insert(word, last);
      word = strtok(NULL, " ");
    }

    sort_words(head);
    print_list(head); 
    free_list(head);  
  }

  return 0;
}

List* insert(char* word, List* last) {
  List* new_cell = (List*)malloc(sizeof(List));
  strcpy(new_cell->word, word);
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

void print_list(List* list) {
  for (List* item = list->next; item != NULL; item = item->next) {
    printf("%s", item->word);
    if (item->next != NULL) {
      printf(" ");
    }
  }
  printf("\n");
}

void sort_words(List* head) {
  char temp_word[MAX];

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (strlen(p->word) < strlen(q->word)) {
        strcpy(temp_word, p->word);
        strcpy(p->word, q->word);
        strcpy(q->word, temp_word);
      }
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
