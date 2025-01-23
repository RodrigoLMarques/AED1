#include <stdio.h>

int main() {
  while (1) {
    int n, m, c, k;
    scanf("%d %d %d %d", &n, &m, &c, &k);

    if (n == 0 && m == 0 && c == 0 && k == 0) {
      break;
    }

    int u, v, p, graph[n][n];
    for (int i = 0; i < m; i++)  {
      scanf("%d %d %d", &u, &v, &p);
      graph[u][v] = p;
      graph[v][u] = p;
    }

  
  }

  return 0;
}