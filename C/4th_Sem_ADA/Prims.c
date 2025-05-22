#include <stdio.h>

#define MAX_VERTICES 10
#define INF 999

int find(int vertex, int parent[MAX_VERTICES]);
int unionSets(int u, int v, int parent[MAX_VERTICES]);
int kruskal(int cost[MAX_VERTICES][MAX_VERTICES], int numVertices);

int main() {
  int cost[MAX_VERTICES][MAX_VERTICES];
  int numVertices, minCost;

  printf("Enter the number of vertices:\n");
  scanf("%d", &numVertices);

  printf("Enter cost matrix\n");
  for (int i = 1; i <= numVertices; i++) {
    for (int j = 1; j <= numVertices; j++) {
      scanf("%d", &cost[i][j]);
    }
  }

  printf("The entered cost matrix is\n");
  for (int i = 1; i <= numVertices; i++) {
    for (int j = 1; j <= numVertices; j++) {
      printf("%d\t", cost[i][j]);
    }
    printf("\n");
  }

  printf("Kruskal's MST edges and cost are:\n");
  minCost = kruskal(cost, numVertices);
  printf("\nMST cost is %d\n", minCost);
  printf("----------\n");

  return 0;
}

int kruskal(int cost[MAX_VERTICES][MAX_VERTICES], int numVertices) {
  int parent[MAX_VERTICES] = {0};
  int numEdges = 1, minCost = 0;

  while (numEdges < numVertices) {
    int min = INF, a = 0, b = 0, u = 0, v = 0;

    for (int i = 1; i <= numVertices; i++) {
      for (int j = 1; j <= numVertices; j++) {
        if (cost[i][j] < min) {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }

    u = find(u, parent);
    v = find(v, parent);

    if (unionSets(u, v, parent)) {
      printf("%d) min edge is (%d,%d) and cost is %d\n", numEdges, a, b, min);
      minCost += min;
      numEdges++;
    }
    cost[a][b] = cost[b][a] = INF;
  }
  return minCost;
}

int find(int vertex, int parent[MAX_VERTICES]) {
  while (parent[vertex] != 0) vertex = parent[vertex];
  return vertex;
}

int unionSets(int u, int v, int parent[MAX_VERTICES]) {
  if (u != v) {
    parent[v] = u;
    return 1;
  }
  return 0;
}