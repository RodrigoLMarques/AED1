/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1077 - Infixa para Posfixa
  Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TList {
  char value;
  struct TList *next;
};

typedef struct TList List;

void insert(List **list, char c);
int precedence(char op);
void infixToPostfix(char *infix, char *postfix);

int main() {
  int n;
  char infix[301], postfix[301];

  scanf("%d", &n);
  while (n--) {
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
  }

  return 0;
}

void insert(List **list, char c) {
  List *newItem = (List *)malloc(sizeof(List));
  newItem->value = c;
  newItem->next = *list;
  *list = newItem;
}

int precedence(char op) {
  switch (op) {
    case '^': return 4;
    case '*': case '/': return 3;
    case '+': case '-': return 2;
    default: return 1;
  }
}

void infixToPostfix(char *infix, char *postfix) {
  List *stack = NULL;
  int i, j = 0;

  for (i = 0; infix[i]; i++) {
    if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')) {
      postfix[j++] = infix[i];
    } else if (infix[i] == '(') {
      insert(&stack, infix[i]);
    } else if (infix[i] == ')') {
      while (stack != NULL && stack->value != '(') {
        postfix[j++] = stack->value;
        stack = stack->next;
      }
      if (stack != NULL) stack = stack->next;
    } else {
      while (stack != NULL && precedence(stack->value) >= precedence(infix[i])) {
        postfix[j++] = stack->value;
        stack = stack->next;
      }
      insert(&stack, infix[i]);
    }
  }

  while (stack != NULL) {
    postfix[j++] = stack->value;
    stack = stack->next;
  }

  postfix[j] = '\0';
}