#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue implementation
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Function to print right view
void rightView(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            // Print last node of level
            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

// Main function
int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     6

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    rightView(root);

    return 0;
}
