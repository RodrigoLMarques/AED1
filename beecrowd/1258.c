/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1258 - Camisetas
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_COLOR 15

typedef struct TList {
  char name[MAX_NAME];
  char color[MAX_COLOR];
  char size;      
  struct TList* next;
} List;

List* insert(char* name, char* color, char size, List* last);
void sort(List* head);
int compare(List* p, List* q);
void print_list(List* head);
void free_list(List* head);

int main() {
  int n, first_case = 1;
  char name[MAX_NAME], color[MAX_COLOR], size;
    
  while (scanf("%d", &n) && n != 0) {
    getchar();

    List* head = (List*) malloc(sizeof(List));
    head->next = NULL;
    List* last = head;

    for (int i = 0; i < n; i++) {
      fgets(name, MAX_NAME, stdin);
      name[strcspn(name, "\n")] = '\0';

      scanf("%s %c", color, &size);
      getchar();

      last = insert(name, color, size, last);
    }

    if (!first_case) printf("\n");
    first_case = 0;

    sort(head);
    print_list(head);
    free_list(head);
  }

  return 0;
}

List* insert(char* name, char* color, char size, List* last) {
  List* new_cell = (List*)malloc(sizeof(List));
  strcpy(new_cell->name, name);
  strcpy(new_cell->color, color);
  new_cell->size = size;
  new_cell->next = NULL;
  last->next = new_cell;
  return new_cell;
}

void sort(List* head) {
  char temp_name[MAX_NAME], temp_color[MAX_COLOR];
  char temp_size;

  for (List* p = head->next; p != NULL; p = p->next) {
    for (List* q = p->next; q != NULL; q = q->next) {
      if (compare(p, q) > 0) {
        strcpy(temp_name, p->name);
        strcpy(temp_color, p->color);
        temp_size = p->size;

        strcpy(p->name, q->name);
        strcpy(p->color, q->color);
        p->size = q->size;

        strcpy(q->name, temp_name);
        strcpy(q->color, temp_color);
        q->size = temp_size;
      }
    }
  }
}

int compare(List* p, List* q) {
  int color_cmp = strcmp(p->color, q->color);
  if (color_cmp != 0) return color_cmp;
  if (p->size != q->size) return q->size - p->size;

  return strcmp(p->name, q->name);
}

void print_list(List* head) {
  for (List* item = head->next; item != NULL; item = item->next) {
    printf("%s %c %s\n", item->color, item->size, item->name);
  }
}

void free_list(List* head) {
  List* current = head;
  while (current != NULL) {
    List* next = current->next;
    free(current);
    current = next;
  }
}
