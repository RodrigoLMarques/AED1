/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1123 - Desvio de Rota
  Observações:
*/

#include <stdio.h>
#include <limits.h>

#define MAX_N 250
#define INF INT_MAX

int graph[MAX_N][MAX_N];
int dist[MAX_N];
int visited[MAX_N];

void initializeGraph(int n);
void addEdge(int u, int v, int p);
int dijkstra(int n, int c, int k);

int main() {
  while (1) {
    int n, m, c, k;
    scanf("%d %d %d %d", &n, &m, &c, &k);

    if (n == 0 && m == 0 && c == 0 && k == 0) {
      break;
    }

    initializeGraph(n);

    for (int i = 0; i < m; i++) {
      int u, v, p;
      scanf("%d %d %d", &u, &v, &p);
      addEdge(u, v, p);
    }

    int result = dijkstra(n, c, k);
    printf("%d\n", result);
  }

  return 0;
}

void initializeGraph(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = INF;
    }
    dist[i] = INF;
    visited[i] = 0;
  }
}

void addEdge(int u, int v, int p) {
  graph[u][v] = p;
  graph[v][u] = p;
}

int dijkstra(int n, int c, int k) {
  dist[k] = 0;

  for (int count = 0; count < n; count++) {
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
        u = i;
      }
    }

    if (u == -1 || dist[u] == INF) {
      break;
    }

    visited[u] = 1;

    for (int v = 0; v < n; v++) {
      if (graph[u][v] != INF && !visited[v]) {
        if (u < c && v == u + 1) {
          if (dist[v] > dist[u] + graph[u][v]) {
            dist[v] = dist[u] + graph[u][v];
          }
        } else if (u >= c || v >= c) {
          if (dist[v] > dist[u] + graph[u][v]) {
            dist[v] = dist[u] + graph[u][v];
          }
        }
      }
    }
  }

  return dist[c - 1];
}