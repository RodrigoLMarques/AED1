/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1003 - Soma Simples
  Observações: Experimentando o uso de uma struct mais personalizada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TList {
  int number;
  struct TList* next;
} List;

typedef struct {
  List* head;
  List* tail;
} HeadList;

HeadList* create_head_list();
void insert(HeadList* headList, int number);
void print_list(List* head);
void free_list(List* head);
int sum(List* head);

int main() {
  int A, B;
  HeadList* headList = create_head_list();

  scanf("%d %d", &A, &B);

  insert(headList, A);
  insert(headList, B);

  int SOMA = sum(headList->head);

  printf("SOMA = %d\n", SOMA);

  free_list(headList->head);
  free(headList);

  return 0;
}

HeadList* create_head_list() {
  HeadList* newHeadList = (HeadList*)malloc(sizeof(HeadList));
  newHeadList->head = NULL;
  newHeadList->tail = NULL;
  return newHeadList;
}

void insert(HeadList* headList, int number) {
  List* newList = (List*)malloc(sizeof(List));
  newList->number = number;
  newList->next = NULL;

  if (headList->head == NULL) {
    headList->head = newList;
    headList->tail = newList;
  } else {
    headList->tail->next = newList;
    headList->tail = newList;
  }
}

void print_list(List* head) {
  List* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->number);
    temp = temp->next;
  }
  printf("\n");
}

void free_list(List* head) {
  List* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int sum(List* head) {
  int sum = 0;
  List* temp = head;
  while (temp != NULL) {
    sum += temp->number;
    temp = temp->next;
  }
  return sum;
}

