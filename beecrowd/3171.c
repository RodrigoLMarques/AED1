/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 3171 - Cordão de Led
  Observações: Usando matriz de adjacência e busca profunda
*/

#include <stdio.h>

#define MAX 101

void initializeGraph(int n, int adj[MAX][MAX], int visited[MAX]);
void addEdge(int x, int y, int adj[MAX][MAX]);
void dfs(int node, int n, int adj[MAX][MAX], int visited[MAX]);
int isGraphConnected(int n, int visited[MAX]);

int main() {
  int adj[MAX][MAX];
  int visited[MAX];
  int n, l;

  scanf("%d %d", &n, &l);
  initializeGraph(n, adj, visited);

  for (int i = 0; i < l; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    addEdge(x, y, adj);
  }

  dfs(1, n, adj, visited);

  if (isGraphConnected(n, visited)) {
    printf("COMPLETO\n");
  } else {
    printf("INCOMPLETO\n");
  }

  return 0;
}

void initializeGraph(int n, int adj[MAX][MAX], int visited[MAX]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      adj[i][j] = 0;
    }
    visited[i] = 0;
  }
}

void addEdge(int x, int y, int adj[MAX][MAX]) {
  adj[x][y] = 1;
  adj[y][x] = 1;
}

void dfs(int node, int n, int adj[MAX][MAX], int visited[MAX]) {
  visited[node] = 1;
  for (int i = 1; i <= n; i++) {
    if (adj[node][i] && !visited[i]) {
      dfs(i, n, adj, visited);
    }
  }
}

int isGraphConnected(int n, int visited[MAX]) {
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      return 0;
    }
  }
  return 1;
}
