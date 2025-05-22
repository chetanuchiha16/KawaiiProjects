#include <stdio.h>

#define MAX_VERTICES 10
#define INF 999

void dijkstra(int cost[MAX_VERTICES][MAX_VERTICES], int distance[MAX_VERTICES],
              int source, int numVertices, int prev[MAX_VERTICES],
              int visited[MAX_VERTICES]);
void printPaths(int source, int numVertices, int distance[MAX_VERTICES],
                int prev[MAX_VERTICES], int visited[MAX_VERTICES]);

int main() {
  int i, j, source, numVertices;
  int distance[MAX_VERTICES], visited[MAX_VERTICES];
  int cost[MAX_VERTICES][MAX_VERTICES], prev[MAX_VERTICES];

  printf("DIJKSTRA\n");
  printf("Enter the number of vertices:\n");
  scanf("%d", &numVertices);

  printf("Enter cost matrix\n");
  for (i = 1; i <= numVertices; i++) {
    for (j = 1; j <= numVertices; j++) {
      scanf("%d", &cost[i][j]);
    }
  }

  printf("The entered cost matrix is\n");
  for (i = 1; i <= numVertices; i++) {
    for (j = 1; j <= numVertices; j++) {
      printf("%d\t", cost[i][j]);
    }
    printf("\n");
  }

  printf("Enter source vertex:\n");
  scanf("%d", &source);

  dijkstra(cost, distance, source, numVertices, prev, visited);
  printPaths(source, numVertices, distance, prev, visited);

  printf("-----------\n");
  return 0;
}

void dijkstra(int cost[MAX_VERTICES][MAX_VERTICES], int distance[MAX_VERTICES],
              int source, int numVertices, int prev[MAX_VERTICES],
              int visited[MAX_VERTICES]) {
  int count = 2, minDist, nextVertex = 0;
  for (int i = 1; i <= numVertices; i++) {
    visited[i] = 0;
    distance[i] = cost[source][i];
    if (cost[source][i] == INF)
      prev[i] = 0;
    else
      prev[i] = source;
  }
  visited[source] = 1;

  while (count <= numVertices) {
    minDist = INF;
    for (int v = 1; v <= numVertices; v++) {
      if ((distance[v] < minDist) && (visited[v] == 0)) {
        minDist = distance[v];
        nextVertex = v;
      }
    }
    visited[nextVertex] = 1;
    count++;
    for (int v = 1; v <= numVertices; v++) {
      if (distance[v] > distance[nextVertex] + cost[nextVertex][v]) {
        distance[v] = distance[nextVertex] + cost[nextVertex][v];
        prev[v] = nextVertex;
      }
    }
  }
}

void printPaths(int source, int numVertices, int distance[MAX_VERTICES],
                int prev[MAX_VERTICES], int visited[MAX_VERTICES]) {
  for (int v = 1; v <= numVertices; v++) {
    if (visited[v] == 1 && v != source) {
      printf("\nShortest distance between %d -> %d is %d\n", source, v,
             distance[v]);
      int t = prev[v];
      printf("The path is  %d", v);
      while (t != source) {
        printf(" <-> %d", t);
        t = prev[t];
      }
      printf(" <-> %d \n", source);
    }
  }
}