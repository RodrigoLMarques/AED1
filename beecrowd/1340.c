/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1340 - Eu Posso Adivinhar a Estrutura de Dados!
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int remove_stack(HeadList* headList);
int remove_queue(HeadList* headList);
int remove_priority_queue(HeadList* headList);
void free_list(List* head);

int main() {
  int n, command, x;
  while (scanf("%d", &n) != EOF) {
    HeadList* stack = create_head_list();
    HeadList* queue = create_head_list();
    HeadList* priorityQueue = create_head_list();

    bool isStack = true;
    bool isQueue = true;
    bool isPriorityQueue = true;

    for (int i = 0; i < n; i++) {
      scanf("%d", &command);
      if (command == 1) {
        scanf("%d", &x);
        insert(stack, x);
        insert(queue, x);
        insert(priorityQueue, x);
      } else if (command == 2) {
        scanf("%d", &x);
        int stackValue = remove_stack(stack);
        int queueValue = remove_queue(queue);
        int priorityQueueValue = remove_priority_queue(priorityQueue);

        if (stackValue != x) isStack = false;
        if (queueValue != x) isQueue = false;
        if (priorityQueueValue != x) isPriorityQueue = false;
      }
    }

    if ((isStack && isQueue) || (isStack && isPriorityQueue) || (isQueue && isPriorityQueue)) {
      printf("not sure\n");
    } else if (isStack) {
      printf("stack\n");
    } else if (isQueue) {
      printf("queue\n");
    } else if (isPriorityQueue) {
      printf("priority queue\n");
    } else {
      printf("impossible\n");
    }

    free_list(stack->head);
    free(stack);
    free_list(queue->head);
    free(queue);
    free_list(priorityQueue->head);
    free(priorityQueue);
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

int remove_stack(HeadList* headList) {
  if (headList->head == NULL) return -1;

  List* temp = headList->head;
  int value = temp->value;
  headList->head = headList->head->next;
  free(temp);

  if (headList->head == NULL) {
    headList->tail = NULL;
  }

  return value;
}

int remove_queue(HeadList* headList) {
  return remove_stack(headList);
}

int remove_priority_queue(HeadList* headList) {
  if (headList->head == NULL) return -1;

  List* prev = NULL;
  List* current = headList->head;
  List* maxPrev = NULL;
  List* maxNode = headList->head;
  int maxValue = current->value;

  while (current != NULL) {
    if (current->value > maxValue) {
      maxValue = current->value;
      maxNode = current;
      maxPrev = prev;
    }
    prev = current;
    current = current->next;
  }

  if (maxPrev == NULL) {
    headList->head = headList->head->next;
  } else {
    maxPrev->next = maxNode->next;
  }

  if (maxNode == headList->tail) {
    headList->tail = maxPrev;
  }

  int value = maxNode->value;
  free(maxNode);
  return value;
}

void free_list(List* head) {
  List* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
