/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1034 - Festival de Estátuas de Gelo
  Observações: Experimentando o uso de uma struct mais personalizada
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
void free_list(List* head);
int min_blocks(int blocks[], int n, int m);

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int N, M;
    scanf("%d %d", &N, &M);

    int blocks[N];
    for (int i = 0; i < N; i++) {
      scanf("%d", &blocks[i]);
    }

    int result = min_blocks(blocks, N, M);
    printf("%d\n", result);
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

void free_list(List* head) {
  List* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int min_blocks(int blocks[], int n, int m) {
  int dp[m + 1];
  for (int i = 0; i <= m; i++) {
    dp[i] = INT_MAX;
  }
  dp[0] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      if (blocks[j] <= i && dp[i - blocks[j]] != INT_MAX) {
        if (dp[i - blocks[j]] + 1 < dp[i]) {
          dp[i] = dp[i - blocks[j]] + 1;
        }
      }
    }
  }

  return dp[m];
}

