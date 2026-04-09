#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Step 1: Add all nodes with indegree 0 to queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int topoOrder[MAX];
    int count = 0;

    // Step 2: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        topoOrder[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Step 3: Check for cycle
    if (count != V) {
        printf("Graph has a cycle! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", topoOrder[i]);
        }
        printf("\n");
    }

    return 0;
}
