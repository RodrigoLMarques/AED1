// TODO

#include <stdio.h>
#include <string.h>

int main() {
  char str[301];
  while (scanf("%s", str) != EOF) {
    int b = 0, c = 0, f = 0, s = 0;
    for (int i = 0; i < strlen(str); i++) {
      if (str[i] == 'B') b++;
      if (str[i] == 'C') c++;
      if (str[i] == 'F') f++;
      if (str[i] == 'S') s++;
    }
    int n1 = b < s ? b : s;
    int n2 = c < f ? c : f;
    int total = n1 + n2;
    printf("%d\n", total);
  }
}