#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 13

typedef struct List {
  char name[MAX_NAME];
  struct List *next;
} List;

List* create_list();
void insert_node(List *head, char *name);
void free_list(List *head);
void find_richest_mate(List *head, float total_water, float cup_volume);

int main() {
  int n;
  float total_water, cup_volume;
  scanf("%d %f %f", &n, &total_water, &cup_volume);

  List *head = create_list();
  char name[MAX_NAME];

  for (int i = 0; i < n; i++) {
    scanf("%s", name);
    insert_node(head, name);
  }

  find_richest_mate(head, total_water, cup_volume);

  free_list(head);
  return 0;
}

List* create_list() {
  List *head = (List*) malloc(sizeof(List));
  head->next = NULL;
  return head;
}

void insert_node(List *head, char *name) {
  List *new_node = (List*) malloc(sizeof(List));
  strcpy(new_node->name, name);
  new_node->next = NULL;

  List *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void free_list(List *head) {
  List *current = head;
  while (current != NULL) {
    List *temp = current;
    current = current->next;
    free(temp);
  }
}

void find_richest_mate(List *head, float total_water, float cup_volume) {
  List *current = head->next;
  float remaining_water = total_water;

  while (remaining_water > cup_volume) {
    remaining_water -= cup_volume;
    current = current->next;
    if (current == NULL) {
      current = head->next;
    }
  }

  printf("%s %.1f\n", current->name, remaining_water);
}
