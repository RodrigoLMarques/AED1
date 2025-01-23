/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1763 - Tradutor do Papai Noel
  Observações: Usando lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TList {
  char* key;
  char* value;
  struct TList *next;
};

typedef struct TList List;

List* insert(char* key, char* value, List *last);
char* linear_search(char* key, List* list);
void initList(List* last);

int main() {
  List *list = (List*) malloc(sizeof(List));
  List *last = list;
  initList(last);

  char key[1000];

  while (scanf("%s", key) != EOF) {
    char* value = linear_search(key, list);
    if (value == NULL) {
      printf("--- NOT FOUND ---\n");
    } else {
      printf("%s\n", value);
    }
  }

  return 0;
}

List* insert(char* key, char* value, List *last) {
  List *new_cell;
  new_cell = (List*) malloc(sizeof(List));
  new_cell->key = key;
  new_cell->value = value;
  new_cell->next = last->next;
  last->next = new_cell;
  return new_cell;
}

char* linear_search(char* key, List* list) {
  for (List* item = list->next; item != NULL; item = item->next) {
    if (strcmp(key, item->key) == 0) {
      return item->value;
    }
  }

  return NULL;
}

void initList(List* last) {
  last = insert("brasil", "Feliz Natal!", last);
  last = insert("alemanha", "Frohliche Weihnachten!", last);
  last = insert("austria", "Frohe Weihnacht!", last);
  last = insert("coreia", "Chuk Sung Tan!", last);
  last = insert("espanha", "Feliz Navidad!", last);
  last = insert("grecia", "Kala Christougena!", last);
  last = insert("estados-unidos", "Merry Christmas!", last);
  last = insert("inglaterra", "Merry Christmas!", last);
  last = insert("australia", "Merry Christmas!", last);
  last = insert("portugal", "Feliz Natal!", last);
  last = insert("suecia", "God Jul!", last);
  last = insert("turquia", "Mutlu Noeller", last);
  last = insert("argentina", "Feliz Navidad!", last);
  last = insert("chile", "Feliz Navidad!", last);
  last = insert("mexico", "Feliz Navidad!", last);
  last = insert("antardida", "Merry Christmas!", last);
  last = insert("canada", "Merry Christmas!", last);
  last = insert("irlanda", "Nollaig Shona Dhuit!", last);
  last = insert("belgica", "Zalig Kerstfeest!", last);
  last = insert("italia", "Buon Natale!", last);
  last = insert("libia", "Buon Natale!", last);
  last = insert("siria", "Milad Mubarak!", last);
  last = insert("marrocos", "Milad Mubarak!", last);
  last = insert("japao", "Merii Kurisumasu!", last);
}
