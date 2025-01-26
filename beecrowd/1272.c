/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1244 - Ordenação por Tamanho
  Observações: Listas
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
void string_process(char* t, char* res);

int main() {
  int n;
  char str[MAX], result[MAX];

  List* head = (List*) malloc(sizeof(List));
  List* last = head;
  
  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++) {
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;

    string_process(str, result);
    last = insert(result, last);
  }

  print_list(head);
  free_list(head);
  return 0;
}

List* insert(char* word, List* last) {
  List* new_cell = (List*)malloc(sizeof(List));
  strcpy(new_cell->word, word);
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

void print_list(List* head) {
  for (List* item = head->next; item != NULL; item = item->next) {
    printf("%s\n", item->word);
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

void string_process(char* str, char* res) {
  int isNewWord = 1, index = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z' && isNewWord) {
      res[index++] = str[i];
      isNewWord = 0;
    } else if (str[i] == ' ') {
      isNewWord = 1;
    }
  }

  res[index] = '\0';
}
