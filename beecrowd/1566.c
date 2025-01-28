/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1566 - Altura
  Observações: Usando quick sort
*/

#include <stdio.h>

int separa(int p, int r, int v[]);
void quicksort(int p, int r, int v[]);
void print_array(int n, int v[]);

int main() {
  int nc, n;

  scanf("%d", &nc);

  for (int i = 0; i < nc; i++) {
    scanf("%d", &n);

    int h[n];
    for (int j = 0; j < n; j++) {
      scanf("%d", &h[j]);
    }

    quicksort(0, n-1, h);
    print_array(n, h);
  }

  return 0;
}

void print_array(int n, int v[]) {  
  for (int j = 0; j < n; j++) {
    printf("%d", v[j]);

    if (j < n - 1)  {
      printf(" ");
    } else  {
      printf("\n");
    }
  }
}

int separa(int p, int r, int v[]) {
  int c, j, k, t;
  c = v[r]; j = p;
  for (k = p; k < r; k++) {
    if (v[k] <= c) {
      t = v[j], v[j] = v[k], v[k] = t;
      j++;
    }
  }
  v[r] = v[j], v[j] = c;
  return j;
}

void quicksort(int p, int r, int v[]) {
  int j;
  if (p < r) {
    j = separa(p, r, v);
    quicksort(p, j - 1, v);
    quicksort(j + 1, r, v);
  }
}