/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2984 - Assuntos Pendentes
  Observações: Usando a estrutura de dados Pilha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TStack {
  char character;
  struct TStack *next;
};

typedef struct TStack Stack;

void push(char c, Stack **stack);
char pop(Stack **stack);
int count_stack(Stack *stack);
void clear_stack(Stack **stack);

int main() {
  char str[100001];

  scanf("%s", str);
  
  Stack *stack = NULL;

  for (size_t j = 0; j < strlen(str); j++) {
    if (str[j] == '(') {
      push(str[j], &stack);
    } else if (str[j] == ')') {
      pop(&stack);
    }
  }

  int count = count_stack(stack); 

  if (count > 0) {
    printf("Ainda temos %d assunto(s) pendente(s)!\n", count);
  } else {
    printf("Partiu RU!\n");
  }

  clear_stack(&stack);

  return 0;
}

void push(char c, Stack **stack) {
  Stack *new_cell = (Stack *)malloc(sizeof(Stack));
  new_cell->character = c;
  new_cell->next = *stack;
  *stack = new_cell;
}

char pop(Stack **stack) {
  if (*stack == NULL) return '\0';
  Stack *temp = *stack;
  char character = temp->character;
  *stack = temp->next;
  free(temp);
  return character;
}

int count_stack(Stack *stack) {
  int count = 0;
  for (Stack *item = stack; item != NULL; item = item->next) {
    count++;
  }
  return count;
}

void clear_stack(Stack **stack) {
  while (*stack != NULL) {
    pop(stack);
  }
}
