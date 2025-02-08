/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1242 - Ácido Ribonucleico Alienígena
  Observações:
*/

#include <stdio.h>
#include <string.h>

#define MAX 301

int maxPairs(char *str);

int main() {
  char str[MAX];
  while (scanf("%s", str) != EOF) {
    int result = maxPairs(str);
    printf("%d\n", result);
  }
  return 0;
}

int maxPairs(char *str) {
  int len = strlen(str);
  int stack[MAX];
  int top = -1;
  int pairs = 0;

  for (int i = 0; i < len; i++) {
    if (top >= 0) {
      if ((str[i] == 'B' && stack[top] == 'S') || (str[i] == 'S' && stack[top] == 'B')) {
        pairs++;
        top--;
      } else if ((str[i] == 'C' && stack[top] == 'F') || (str[i] == 'F' && stack[top] == 'C')) {
        pairs++;
        top--;
      } else {
        stack[++top] = str[i];
      }
    } else {
      stack[++top] = str[i];
    }
  }

  return pairs;
}