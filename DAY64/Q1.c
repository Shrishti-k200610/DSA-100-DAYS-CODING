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

// Queue structure for BFS
typedef struct Queue {
    int* items;
    int front;
    int rear;
    int maxSize;
} Queue;

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

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Queue operations
Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->maxSize = size;
    return q;
}

void enqueue(Queue* q, int value) {
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int value = q->items[q->front];
    q->front++;
    return value;
}

bool isEmpty(Queue* q) {
    return q->front > q->rear;
}

// BFS function
void BFS(Graph* graph, int start) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;

    Queue* q = createQueue(graph->numVertices);

    visited[start] = true;
    enqueue(q, start);

    printf("BFS Traversal starting from vertex %d: ", start);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        Node* temp = graph->adjLists[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                enqueue(q, temp->vertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    free(q->items);
    free(q);
}

// Main function
int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    scanf("%d", &s); // source vertex
    BFS(graph, s);

    return 0;
}
