#include <stdio.h>

int findRoot(int vertex, int parent[]) {
    while (parent[vertex] != 0)
        vertex = parent[vertex];
    return vertex;
}

int unionSets(int root1, int root2, int parent[]) {
    if (root1 != root2) {
        parent[root2] = root1;
        return 1;
    }
    return 0;
}

int kruskalMST(int costMatrix[10][10], int totalVertices) {
    int edgeCount = 1, minEdgeCost, totalCost = 0;
    int startVertex, endVertex, rootStart, rootEnd;
    int parent[10] = {0}; // Disjoint set parent array

    while (edgeCount < totalVertices) {
        minEdgeCost = 999;

        // Find the smallest edge
        for (int row = 1; row <= totalVertices; row++) {
            for (int col = 1; col <= totalVertices; col++) {
                if (costMatrix[row][col] < minEdgeCost) {
                    minEdgeCost = costMatrix[row][col];
                    startVertex = row;
                    endVertex = col;
                }
            }
        }

        rootStart = findRoot(startVertex, parent);
        rootEnd = findRoot(endVertex, parent);

        if (unionSets(rootStart, rootEnd, parent)) {
            printf("%d) Edge (%d, %d) with cost %d included in MST\n", edgeCount, startVertex, endVertex, minEdgeCost);
            totalCost += minEdgeCost;
            edgeCount++;
        }

        // Mark the edge as visited
        costMatrix[startVertex][endVertex] = costMatrix[endVertex][startVertex] = 999;
    }

    return totalCost;
}

int main() {
    int totalVertices;
    int costMatrix[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &totalVertices);

    printf("Enter the cost adjacency matrix:\n");
    for (int row = 1; row <= totalVertices; row++) {
        for (int col = 1; col <= totalVertices; col++) {
            scanf("%d", &costMatrix[row][col]);
        }
    }

    printf("\nThe entered cost matrix is:\n");
    for (int row = 1; row <= totalVertices; row++) {
        for (int col = 1; col <= totalVertices; col++) {
            printf("%d\t", costMatrix[row][col]);
        }
        printf("\n");
    }

    printf("\nKruskal's MST edges and their costs:\n");
    int totalMSTCost = kruskalMST(costMatrix, totalVertices);
    printf("\nTotal cost of MST: %d\n", totalMSTCost);
    printf("----------\n");

    return 0;
}
