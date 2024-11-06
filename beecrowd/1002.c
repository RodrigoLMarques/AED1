/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1002 - Área do Círculo
  Observações: Usando a estrutura de dados Lista
*/

#include <stdio.h>
 
int main() {
  double r, pi = 3.14159;

  scanf("%lf", &r);

  double area = pi * r * r;

  printf("A=%.4lf\n", area);

  return 0;
}