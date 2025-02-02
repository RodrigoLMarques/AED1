#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int priority;
  char type;
} Problem;

int compare_problems(Problem *a, Problem *b);
void bubble_sort(Problem *array, int size);
void read_problems(Problem *problems, int rows, int cols);
void print_problems(Problem *problems, int size);

int main() {
  int rows, cols;
  scanf("%d %d", &rows, &cols);

  int total = rows * cols;
  Problem *problems = malloc(total * sizeof(Problem));

  read_problems(problems, rows, cols);
  bubble_sort(problems, total);
  print_problems(problems, total);

  free(problems);
  return 0;
}

void read_problems(Problem *problems, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      char input[3];
      scanf("%s", input);
      problems[i * cols + j].priority = input[0] - '0';
      problems[i * cols + j].type = input[1];
    }
  }
}

void print_problems(Problem *problems, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d%c\n", problems[i].priority, problems[i].type);
  }
}

int compare_problems(Problem *a, Problem *b) {
  if (a->type == 'V' && b->type == 'D') {
    return -1;
  }
  if (a->type == 'D' && b->type == 'V') {
    return 1;
  }
  return b->priority - a->priority;
}

void bubble_sort(Problem *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (compare_problems(&array[j], &array[j + 1]) > 0) {
        Problem temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}