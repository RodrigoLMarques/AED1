#include <stdio.h>

int isArrow(char c) {
  return c == '>' || c == 'v' || c == '<' || c == '^';
}

int setDirection(char c) {
  if (c == '>') return 1;  // Direita
  if (c == 'v') return 2;  // Baixo
  if (c == '<') return 3;  // Esquerda
  if (c == '^') return 4;  // Cima
  return 0;
}

int setX(int x, int d) {
  if (d == 1) return x + 1;
  if (d == 3) return x - 1;
  return x;
}

int setY(int y, int d) {
  if (d == 2) return y + 1;
  if (d == 4) return y - 1;
  return y;
}

int main() {
  int x, y;

  scanf("%d %d", &y, &x);
  getchar();

  char map[x][y];
  int pass[x][y];

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      pass[i][j] = 0;
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      scanf(" %c", &map[i][j]);
    }
  }

  int i = 0, j = 0, direction = 0, win = 0;

  while (!pass[i][j] && !win) {
    char c = map[i][j];

    if (isArrow(c)) {
      pass[i][j] = 1;
      direction = setDirection(c);
    }

    // printf("c = %c, i = %d, j = %d, d = %d\n", c, i, j, direction);

    if (c == '*') {
      win = 1;
      break;
    }

    int newI = setY(i, direction);
    int newJ = setX(j, direction);

    if (newI >= x || newI < 0 || newJ >= y || newJ < 0) {
      break;
    }

    i = newI;
    j = newJ;
  }

  if (win) {
    printf("*\n");
  } else {
    printf("!\n");
  }

  return 0;
}
