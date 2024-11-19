/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1069 - Diamantes e Areia
  Observações: Usando a estrutura de dados Pilha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TList {
  char character;
  struct TList *next;
};

typedef struct TList List;

void push(char c, List **stack);
char pop(List **stack);
void clear_stack(List **stack);

int main() {
  char str[1001];
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", str);

    List *stack = NULL;
    int count = 0;

    for (size_t j = 0; j < strlen(str); j++) {
      if (str[j] == '<') {
        push(str[j], &stack);
      } else if (str[j] == '>' && stack != NULL) {
        pop(&stack);
        count++;
      }
    }

    clear_stack(&stack);
    printf("%d\n", count);
  }

  return 0;
}

void push(char c, List **stack) {
  List *new_cell = (List*) malloc(sizeof(List));
  new_cell->character = c;
  new_cell->next = *stack;
  *stack = new_cell;
}

char pop(List **stack) {
  if (*stack == NULL) return '\0';
  List *temp = *stack;
  char character = temp->character;
  *stack = temp->next;
  free(temp);
  return character;
}

void clear_stack(List **stack) {
  while (*stack != NULL) {
    pop(stack);
  }
}
