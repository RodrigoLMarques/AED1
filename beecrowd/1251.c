/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1251 - Diga-me a Frequência
  Observações: Experimentando o uso de uma struct mais personalizada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TList {
  int ascii;
  int frequency;
  struct TList* next;
} List;

typedef struct {
  List* head;
  List* tail;
} HeadList;

HeadList* create_head_list();
void insert(HeadList* headList, int ascii, int frequency);
void free_list(List* head);
void count_frequencies(const char* text, int frequencies[]);
void build_frequency_list(HeadList* headList, int frequencies[]);
void sort_frequency_list(HeadList* headList);
void print_list(List* head);

int main() {
  char text[1001];
  int first_case = 1;

  while (fgets(text, sizeof(text), stdin)) {
    if (!first_case) {
      printf("\n");
    }
    first_case = 0;

    int frequencies[256] = {0};
    count_frequencies(text, frequencies);

    HeadList* frequencyList = create_head_list();
    build_frequency_list(frequencyList, frequencies);
    sort_frequency_list(frequencyList);
    print_list(frequencyList->head);

    free_list(frequencyList->head);
    free(frequencyList);
  }

  return 0;
}

HeadList* create_head_list() {
  HeadList* newHeadList = (HeadList*)malloc(sizeof(HeadList));
  newHeadList->head = NULL;
  newHeadList->tail = NULL;
  return newHeadList;
}

void insert(HeadList* headList, int ascii, int frequency) {
  List* newList = (List*)malloc(sizeof(List));
  newList->ascii = ascii;
  newList->frequency = frequency;
  newList->next = NULL;

  if (headList->head == NULL) {
    headList->head = newList;
    headList->tail = newList;
  } else {
    headList->tail->next = newList;
    headList->tail = newList;
  }
}

void free_list(List* head) {
  List* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void count_frequencies(const char* text, int frequencies[]) {
  for (int i = 0; text[i] != '\0'; i++) {
    frequencies[(int)text[i]]++;
  }
}

void build_frequency_list(HeadList* headList, int frequencies[]) {
  for (int i = 0; i < 256; i++) {
    if (frequencies[i] > 0) {
      insert(headList, i, frequencies[i]);
    }
  }
}

void sort_frequency_list(HeadList* headList) {
  if (headList->head == NULL || headList->head->next == NULL) return;

  int swapped;
  List* ptr1;
  List* lptr = NULL;

  do {
    swapped = 0;
    ptr1 = headList->head;

    while (ptr1->next != lptr) {
      if (ptr1->frequency > ptr1->next->frequency || 
          (ptr1->frequency == ptr1->next->frequency && ptr1->ascii < ptr1->next->ascii)) {
        int tempAscii = ptr1->ascii;
        int tempFrequency = ptr1->frequency;
        ptr1->ascii = ptr1->next->ascii;
        ptr1->frequency = ptr1->next->frequency;
        ptr1->next->ascii = tempAscii;
        ptr1->next->frequency = tempFrequency;
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

void print_list(List* head) {
  List* temp = head;
  while (temp != NULL) {
    printf("%d %d\n", temp->ascii, temp->frequency);
    temp = temp->next;
  }
}
