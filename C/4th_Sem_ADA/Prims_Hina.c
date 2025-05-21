#include <stdio.h>

int primsMST(int costMatrix[10][10], int vertices);

int main() {
    int costMatrix[10][10];
    int vertices;

    printf("Enter the number of vertices:\n");
    scanf("%d", &vertices);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    printf("The entered cost matrix is:\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            printf("%d\t", costMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Prim's MST edges and their costs:\n");
    int totalCost = primsMST(costMatrix, vertices);
    printf("\nTotal cost of the Minimum Spanning Tree (MST): %d\n", totalCost);
    printf("----------\n");

    return 0;
}

int primsMST(int costMatrix[10][10], int vertices) {
    int nearVertex[10];
    int mstEdges[10][3];
    int totalCost = 0;

    for (int i = 2; i <= vertices; i++) {
        nearVertex[i] = 1;
    }
    nearVertex[1] = 0;  // Start from vertex 1

    for (int edgeCount = 1; edgeCount < vertices; edgeCount++) {
        int min = 999;
        int selectedVertex = 0;

        for (int j = 2; j <= vertices; j++) {
            if (nearVertex[j] != 0 && costMatrix[j][nearVertex[j]] < min) {
                min = costMatrix[j][nearVertex[j]];
                selectedVertex = j;
            }
        }

        mstEdges[edgeCount][1] = selectedVertex;
        mstEdges[edgeCount][2] = nearVertex[selectedVertex];
        totalCost += min;
        nearVertex[selectedVertex] = 0;

        for (int k = 2; k <= vertices; k++) {
            if (nearVertex[k] != 0 && costMatrix[k][nearVertex[k]] > costMatrix[k][selectedVertex]) {
                nearVertex[k] = selectedVertex;
            }
        }

        printf("%d) Minimum edge: (%d, %d) with cost: %d\n",
               edgeCount,
               mstEdges[edgeCount][1],
               mstEdges[edgeCount][2],
               min);
    }

    return totalCost;
}
