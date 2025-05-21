#include <stdio.h>
#define INF 999

void dijkstra(int cost[10][10], int dist[10], int source, int numVertices, int path[10], int visited[10]);
void printPath(int source, int numVertices, int dist[10], int path[10], int visited[10]);

int main() {
    int cost[10][10], dist[10], path[10], visited[10];
    int numVertices, source;

    printf("🟣 DIJKSTRA ALGORITHM 🟣\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the cost matrix (use 999 for infinity):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nYou entered the following cost matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    printf("Enter the source vertex (0 to %d): ", numVertices - 1);
    scanf("%d", &source);

    dijkstra(cost, dist, source, numVertices, path, visited);
    printPath(source, numVertices, dist, path, visited);

    printf("-----------\n");
    return 0;
}

void dijkstra(int cost[10][10], int dist[10], int source, int numVertices, int path[10], int visited[10]) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        dist[i] = cost[source][i];
        path[i] = (cost[source][i] != INF) ? source : -1;
    }

    visited[source] = 1;

    for (int count = 1; count < numVertices; count++) {
        int minDist = INF;
        int u = -1;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // All reachable vertices processed
        visited[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                path[v] = u;
            }
        }
    }
}

void printPath(int source, int numVertices, int dist[10], int path[10], int visited[10]) {
    for (int i = 0; i < numVertices; i++) {
        if (i != source && visited[i]) {
            printf("\nShortest distance from %d to %d is: %d\n", source, i, dist[i]);

            // Trace path backwards
            int current = i;
            printf("Path: %d", current);

            while (path[current] != source && path[current] != -1) {
                current = path[current];
                printf(" <- %d", current);
            }

            if (path[current] != -1) {
                printf(" <- %d\n", source);
            } else {
                printf(" (No path)\n");
            }
        }
    }
}
