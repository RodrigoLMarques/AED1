/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2929 - Menor da Pilha 
  Observações: Usando a estrutura de dados Pilha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct TStack {
  int value;
  struct TStack *next;
};

typedef struct TStack Stack;

void push(int value, Stack **stack);
int pop(Stack **stack);
int findMin(Stack *stack);
void clear_stack(Stack **stack);

int main() {
  Stack *stack = NULL;
  int n, value;
  char action[5];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", action);

    if (strcmp(action, "PUSH") == 0) {
      scanf("%d", &value);
      push(value, &stack);
    } else if (strcmp(action, "POP") == 0) {
      if (stack != NULL) {
        pop(&stack);
      } else {
        printf("EMPTY\n");
      }
    } else if (strcmp(action, "MIN") == 0) {
      if (stack != NULL) {
        value = findMin(stack);
        printf("%d\n", value);
      } else {
        printf("EMPTY\n");
      }
    }
  }

  clear_stack(&stack);

  return 0;
}

void push(int value, Stack **stack) {
  Stack *new_cell = (Stack*) malloc(sizeof(Stack));
  new_cell->value = value;
  new_cell->next = *stack;
  *stack = new_cell;
}

int pop(Stack **stack) {
  if (*stack == NULL) return -1;
  Stack *temp = *stack;
  int value = temp->value;
  *stack = temp->next;
  free(temp);
  return value;
}

int findMin(Stack *stack) {
  int min = stack->value;
  for (Stack* item = stack; item != NULL; item = item->next) {
    if (item->value < min) min = item->value;
  }

  return min;
}

void clear_stack(Stack **stack) {
  while (*stack != NULL) {
    pop(stack);
  }
}
