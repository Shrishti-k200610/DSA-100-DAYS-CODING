#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int V, int **adj, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // edge exists
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            } else if (recStack[i]) {
                return true; // cycle found
            }
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

// Function to check cycle in graph
bool hasCycle(int V, int **adj) {
    bool *visited = (bool *)calloc(V, sizeof(bool));
    bool *recStack = (bool *)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack)) {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }

    free(visited);
    free(recStack);
    return false;
}

int main() {
    int V = 4;

    // Allocate adjacency matrix
    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)calloc(V, sizeof(int));
    }

    // Example edges
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1; // cycle here

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    // Free memory
    for (int i = 0; i < V; i++) {
        free(adj[i]);
    }
    free(adj);

    return 0;
}
