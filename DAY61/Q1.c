#include <stdio.h>

int main() {
    int n, e, i, j, u, v;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    // Initialize matrix with 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Input edges
    printf("Enter edges (u v):\n");
    for(i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;   // Directed graph

        // Uncomment below for undirected graph
        // adj[v][u] = 1;
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
