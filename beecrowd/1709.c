#include <stdio.h>
#include <stdlib.h>

typedef struct TList {
  int value;
  struct TList *next;
} List;

typedef struct {
  List *head;
  List *tail;
} HeadList;

HeadList *create_head_list();
void insert(HeadList *headList, int value);
void free_list(List *head);
int count_shuffles(int P);

int main() {
  int P;
  scanf("%d", &P);

  int result = count_shuffles(P);
  printf("%d\n", result);

  return 0;
}

HeadList *create_head_list() {
  HeadList *newHeadList = (HeadList *)malloc(sizeof(HeadList));
  newHeadList->head = NULL;
  newHeadList->tail = NULL;
  return newHeadList;
}

void insert(HeadList *headList, int value) {
  List *newList = (List *)malloc(sizeof(List));
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

void free_list(List *head) {
  List *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int count_shuffles(int P) {
  HeadList *deck = create_head_list();
  HeadList *temp = create_head_list();

  for (int i = 0; i < P; i++) {
    insert(deck, i);
  }

  int count = 0;
  while (1) {
    List *firstHalf = deck->head;
    List *secondHalf = deck->head;

    for (int i = 0; i < P / 2; i++) {
      secondHalf = secondHalf->next;
    }

    for (int i = 0; i < P / 2; i++) {
      insert(temp, secondHalf->value);
      insert(temp, firstHalf->value);
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    count++;
    int isOrdered = 1;
    List *current = temp->head;
    for (int i = 0; i < P; i++) {
      if (current->value != i) {
        isOrdered = 0;
        break;
      }
      current = current->next;
    }

    if (isOrdered) {
      break;
    }

    free_list(deck->head);
    deck->head = temp->head;
    deck->tail = temp->tail;
    temp->head = NULL;
    temp->tail = NULL;
  }

  free_list(deck->head);
  free_list(temp->head);
  free(deck);
  free(temp);

  return count;
}