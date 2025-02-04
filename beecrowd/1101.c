/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1101 - Sequência de Números e Soma
  Observações: Experimentando o uso de uma struct mais personalizada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TList {
  int value;
  struct TList* next;
} List;

typedef struct {
  List* head;
  List* tail;
} HeadList;

HeadList* create_head_list();
void insert(HeadList* headList, int value);
void print_list(List* head);
void free_list(List* head);
void calculate_sequence(int start, int end);

int main() {
  int M, N;

  while (1) {
    scanf("%d %d", &M, &N);
    if (M <= 0 || N <= 0) {
      break;
    }
    calculate_sequence(M, N);
  }

  return 0;
}

HeadList* create_head_list() {
  HeadList* newHeadList = (HeadList*)malloc(sizeof(HeadList));
  newHeadList->head = NULL;
  newHeadList->tail = NULL;
  return newHeadList;
}

void insert(HeadList* headList, int value) {
  List* newList = (List*)malloc(sizeof(List));
  newList->value = value;
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
  int sum = 0;
  while (temp != NULL) {
    printf("%d ", temp->value);
    sum += temp->value;
    temp = temp->next;
  }
  printf("Sum=%d\n", sum);
}

void free_list(List* head) {
  List* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void calculate_sequence(int start, int end) {
  HeadList* sequence = create_head_list();
  int min = (start < end) ? start : end;
  int max = (start > end) ? start : end;

  for (int i = min; i <= max; i++) {
    insert(sequence, i);
  }
  print_list(sequence->head);
  free_list(sequence->head);
  free(sequence);
}
