/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1068 - Balanço de Parênteses I
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

  while (scanf("%s", str) != EOF) {
    List *stack = NULL;
    int is_correct = 1;

    for (int i = 0; i < strlen(str); i++) {
      if (str[i] == '(') {
        push(str[i], &stack);
      } else if (str[i] == ')') {
        if (stack == NULL) {
          is_correct = 0;
          break;
        } else {
          pop(&stack);
        }
      }
    }

    if (stack != NULL) {
      is_correct = 0;
    }

    printf(is_correct ? "correct\n" : "incorrect\n");

    clear_stack(&stack);
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
