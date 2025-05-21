#include <stdio.h>

void read_matrix(int nodes, int adj[10][10]) {
    int row, col;
    for(row = 0; row < nodes; row++) {
        for(col = 0; col < nodes; col++) {
            scanf("%d", &adj[row][col]);
        }
    }
}

void calculate_indegree(int nodes, int adj[10][10], int indegree[]) {
    int row, col, total;
    for(col = 0; col < nodes; col++) {
        total = 0;
        for(row = 0; row < nodes; row++) {
            total += adj[row][col];
        }
        indegree[col] = total;
    }
}

void topological_sort(int nodes, int adj[10][10]) {
    int i, stack[10], indegree[10], top = -1;
    int result[10], result_index = 0;
    int current_node, neighbor;

    calculate_indegree(nodes, adj, indegree);

    for(i = 0; i < nodes; i++) {
        if(indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    while(top != -1) {
        current_node = stack[top--];
        result[result_index++] = current_node;

        for(neighbor = 0; neighbor < nodes; neighbor++) {
            if(adj[current_node][neighbor] == 1) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    stack[++top] = neighbor;
                }
            }
        }
    }

    if(result_index != nodes) {
        printf("\nTopological Sequence not possible\n");
    } else {
        printf("\nThe Topological Sequence:\n");
        for(i = 0; i < nodes; i++) {
            printf("%d\t", result[i]);
        }
        printf("\n");
    }
}

int main() {
    int nodes, adj_matrix[10][10];

    printf("Enter number of nodes:\n");
    scanf("%d", &nodes);

    printf("Enter adjacency matrix:\n");
    read_matrix(nodes, adj_matrix);

    topological_sort(nodes, adj_matrix);

    return 0;
}
