#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];
bool visited[MAX];

// DFS function
bool dfs(int node, int parent, int V) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, V))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adjSize[i] = 0;
        visited[i] = false;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u; // undirected graph
    }

    // Check each component
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
