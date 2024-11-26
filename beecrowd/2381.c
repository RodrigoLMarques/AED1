/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 2381 - Lista de Chamada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TList {
  char name[21];
  struct TList *next;
};

typedef struct TList List;

void insert(char *name, List **last);
char* sort_and_pick(List **list, int n, int pick);

int main() {
  int n, x;
  scanf("%d %d", &n, &x);

  List *students = (List*) malloc(n * sizeof(List));
  List *last = students;

  for (int i = 0; i < n; i++) {
    char name[21];
    scanf("%s", name);
    insert(name, &last);
  }

  char *name = sort_and_pick(&students, n, x);

  printf("%s\n", name);
}

void insert(char *name, List **last) {
  List *newCell = (List*) malloc(sizeof(List));
  strcpy(newCell->name, name);
  (*last)->next = newCell;
  (*last) = newCell;
}

char* sort_and_pick(List **list, int n, int pick) {
  char aux[21];
  List *A = *(list); // head
  List *B;

  for (int i = n-1; i > 0; i--) {
    A = A->next;
    B = A;
    for (int j = 0; j < i; j++) {
      B = B->next;
      if (strcmp(A->name, B->name) > 0) {
        strcpy(aux, A->name);
        strcpy(A->name, B->name);
        strcpy(B->name, aux);
      }
    }
  }

  A = *(list);
  for (int i = 0; i < pick; i++) {
    A = A->next;
  }

  return A->name;
}
