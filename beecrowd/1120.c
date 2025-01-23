/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1120 - Revisão de Contrato
  Observações: Apenas manipulação de string
*/

#include <stdio.h>
#include <string.h>

#define MAX 10100

int main() {
  char digit, str_number[MAX];
  
  while (1) {
    scanf("%c %s", &digit, str_number);
    getchar();

    if (digit == '0' && strcmp(str_number, "0") == 0) {
      break;
    }
    
    char result[MAX];
    int index = 0;
    for (size_t i = 0; i < strlen(str_number); i++) {
      if (str_number[i] != digit) {
        result[index++] = str_number[i];
      }
    }
    result[index] = '\0';

    if (index == 0) {
      printf("0\n");
    } else {
      int i = 0;
      while (result[i] == '0') {
        i++;
      }

      if (result[i] == '\0') {
        printf("0\n");
      } else {
        printf("%s\n", &result[i]);
      }
    }
  }

  return 0;
}
