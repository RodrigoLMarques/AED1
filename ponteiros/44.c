#include <stdio.h>

int main() {
  int x = 1, y = 3;
  int *px = &y, *py = &y;

  *px = *px + *py;

  

  printf("x=%d, y=%d\n", x, y);
  printf("*px=%d, *py=%d\n", *px, *py);
  printf("px=%p, py=%p\n", px, py);
  printf("&x=%p, &y=%p\n", &x, &y);

  px++;
  py += 2;

  printf("\npx=%p, *px=%d\n", px, *px);
  printf("py=%p, *py=%d\n\n", py, *py);

  for (int i = 0; i < 10; i++) {
    px++;
    printf("py=%p, *py=%d\n", px, *px);
  }

  return 0;
}