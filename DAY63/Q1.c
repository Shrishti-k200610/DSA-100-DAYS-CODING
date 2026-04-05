#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Add an edge to the graph (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS recursive function
void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* adj = graph->adjLists[vertex];
    while (adj) {
        if (!visited[adj->vertex])
            DFS(graph, adj->vertex, visited);
        adj = adj->next;
    }
}

int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    scanf("%d", &s); // starting vertex for DFS

    bool* visited = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++)
        visited[i] = false;

    printf("DFS Traversal starting from vertex %d: ", s);
    DFS(graph, s, visited);
    printf("\n");

    free(visited);
    return 0;
}
