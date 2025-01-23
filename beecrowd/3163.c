/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 3163 - Controlador de Vôo
  Observações: Usando a estrutura de dados Lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

typedef struct TList {
  char identifier[MAX];
  struct TList* next;
} List;

List* insert(char* identifier, List *last);
void space(List* a, List* b, List* c, List* d);

int main() {
  char str[MAX], side;
  int count = 0;

  List* west = (List*) malloc(sizeof(List));
  List* north = (List*) malloc(sizeof(List));
  List* south = (List*) malloc(sizeof(List));
  List* east = (List*) malloc(sizeof(List));

  west->next = NULL;
  north->next = NULL;
  south->next = NULL;
  east->next = NULL;

  List* lastWest = west;
  List* lastNorth = north;
  List* lastSouth = south;
  List* lastEast = east;
  
  do {
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;

    if (str[0] == '-') {
      side = str[1];
      continue;
    }

    if (str[0] == 'A') {
      if (side == '1') lastWest = insert(str, lastWest);
      if (side == '2') lastSouth = insert(str, lastSouth);
      if (side == '3') lastNorth = insert(str, lastNorth);
      if (side == '4') lastEast = insert(str, lastEast);
      count++;
    }

  } while(strcmp(str, "0") != 0);

  west = west->next;
  north = north->next;
  south = south->next;
  east = east->next;

  while (west != NULL || north != NULL || south != NULL || east != NULL) {
    if (west != NULL) {
      printf("%s", west->identifier);
      west = west->next;
      space(west, north, south, east);
    }
    if (north != NULL) {
      printf("%s", north->identifier);
      north = north->next;
      space(west, north, south, east);
    }
    if (south != NULL) {
      printf("%s", south->identifier);
      south = south->next;
      space(west, north, south, east);
    }
    if (east != NULL) {
      printf("%s", east->identifier);
      east = east->next;
      space(west, north, south, east);
    }
  }

  printf("\n");

  return 0;
}

void space(List* a, List* b, List* c, List* d) {
  if (a != NULL || b != NULL || c != NULL || d != NULL) {
    printf(" ");
  }
}

List* insert(char* identifier, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  strcpy(new_cell->identifier, identifier);
  new_cell->next = last->next;
  last->next = new_cell;
  return new_cell;
}
