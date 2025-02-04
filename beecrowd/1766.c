/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1766 - O Elfo das Trevas
  Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_NAME_LENGTH = 101;

typedef struct TList {
  char *name;
  int weight;
  int age;
  double height;
  struct TList *next;
} List;

void insert(char *name, int weight, int age, double height, List **head, List **tail);
void sort(List *lst);
void print_list(List *first, int M, int scenario);

int main() {
  List *head, *tail;
  head = tail = NULL;

  int T, weight, age, N, M;
  char name[MAX_NAME_LENGTH];
  double height;

  scanf("%d", &T);
  for (int scenario = 1; scenario <= T; scenario++) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
      scanf("%s %d %d %lf", name, &weight, &age, &height);
      insert(name, weight, age, height, &head, &tail);
    }

    sort(head);

    print_list(head, M, scenario);
    head = tail = NULL;
  }

  return 0;
}

void insert(char *name, int weight, int age, double height, List **head, List **tail) {
  List *newCell = (List *)malloc(sizeof(List));
  newCell->name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
  strcpy(newCell->name, name);
  newCell->weight = weight;
  newCell->age = age;
  newCell->height = height;
  newCell->next = NULL;

  if (*tail == NULL) {
    *head = *tail = newCell;
  } else {
    (*tail)->next = newCell;
    *tail = newCell;
  }
}

void sort(List *lst) {
  List *p, *q;
  char tempName[MAX_NAME_LENGTH];
  int tempWeight, tempAge;
  double tempHeight;

  for (p = lst; p != NULL; p = p->next) {
    for (q = p->next; q != NULL; q = q->next) {
      if (
        (p->weight < q->weight) || 
        (p->weight == q->weight && p->age > q->age) ||
        (p->weight == q->weight && p->age == q->age && p->height > q->height) ||
        (p->weight == q->weight && p->age == q->age && p->height == q->height && strcmp(p->name, q->name) > 0)
      ) {
        strcpy(tempName, p->name);
        tempWeight = p->weight;
        tempAge = p->age;
        tempHeight = p->height;

        strcpy(p->name, q->name);
        p->weight = q->weight;
        p->age = q->age;
        p->height = q->height;

        strcpy(q->name, tempName);
        q->weight = tempWeight;
        q->age = tempAge;
        q->height = tempHeight;
      }
    }
  }
}

void print_list(List *first, int M, int scenario) {
  List *p = first;
  printf("CENARIO {%d}\n", scenario);
  for (int i = 1; i <= M && p != NULL; i++) {
    printf("%d - %s\n", i, p->name);
    p = p->next;
  }
}