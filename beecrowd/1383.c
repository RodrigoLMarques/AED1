#include <stdio.h>
 
int validar(int sudoku[9][9]);

int main() { 
  int n;
  scanf("%d", &n);

  int sudokus[n][9][9];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        scanf("%d", &sudokus[i][j][k]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("Instancia %d\n", i + 1);

    if (validar(sudokus[i])) {
      printf("SIM\n");
    } else {
      printf("NAO\n");
    }

    if (i != n - 1) {
      printf("\n");
    }
  }

  return 0;
}

int validar(int sudoku[9][9]) {
  // Valida as linhas e colunas do Sudoku
  for (int i = 0; i < 9; i++) {
    int n, linhas[10] = { 0 };
    for (int j = 0; j < 9; j++) {
      n = sudoku[i][j];
      linhas[n]++;
      if (linhas[n] > 1) {
        return 0;
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    int colunas[10] = { 0 };
    for (int j = 0; j < 9; j++) {
      int n = sudoku[j][i];
      colunas[n]++;
      if (colunas[n] > 1) {
        return 0;
      }
    }
  }

  // Valida os blocos do Sudoku
  int index[9][2] = {
    {0, 0}, {0, 3}, {0, 6}, 
    {3, 0}, {3, 3}, {3, 6}, 
    {6, 0}, {6, 3}, {6, 6}
  };
  
  for (int i = 0; i < 9; i++) {
    int linha = index[i][0];
    int coluna = index[i][1];
    int bloco[10] = { 0 };

    for (int j = linha; j < linha + 3; j++) {
      for (int k = coluna; k < coluna + 3; k++) {
        int n = sudoku[j][k];
        bloco[n]++;
        if (bloco[n] > 1) {
          return 0;
        }
      }
    }
  }

  // Sudoku Válido
  return 1;
}


