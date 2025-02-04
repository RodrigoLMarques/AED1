/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1874 - Empurrando Blocos
  Observações: User o conceito de pilhas, mas não usei struct nesse
*/

#include <stdio.h>
#include <stdlib.h>

void read_stacks(int **stacks, int height, int piles);
void read_queue(int *queue, int size);
void insert_blocks(int **stacks, int height, int piles, int *queue, int queue_size);
void print_stacks(int **stacks, int height, int piles);

int main() {
  int height, piles, queue_size;

  while (1) {
    scanf("%d %d %d", &height, &piles, &queue_size);
    if (height == 0 && piles == 0 && queue_size == 0) break;

    int **stacks = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
      stacks[i] = malloc(piles * sizeof(int));
    }

    int *queue = malloc(queue_size * sizeof(int));

    read_stacks(stacks, height, piles);
    read_queue(queue, queue_size);
    insert_blocks(stacks, height, piles, queue, queue_size);
    print_stacks(stacks, height, piles);

    for (int i = 0; i < height; i++) {
      free(stacks[i]);
    }
    free(stacks);
    free(queue);
  }

  return 0;
}

void read_stacks(int **stacks, int height, int piles) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < piles; j++) {
      scanf("%d", &stacks[i][j]);
    }
  }
}

void read_queue(int *queue, int size) {
  for (int i = 0; i < size; i++) {
    scanf("%d", &queue[i]);
  }
}

void insert_blocks(int **stacks, int height, int piles, int *queue, int queue_size) {
  int queue_index = 0;

  for (int j = piles - 1; j >= 0 && queue_index < queue_size; j--) {
    for (int i = height - 1; i >= 0 && queue_index < queue_size; i--) {
      if (stacks[i][j] == 0) {
        stacks[i][j] = queue[queue_index];
        queue_index++;
      }
    }
  }
}

void print_stacks(int **stacks, int height, int piles) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < piles; j++) {
      printf("%d", stacks[i][j]);
      if (j < piles - 1) printf(" ");
    }
    printf("\n");
  }
}