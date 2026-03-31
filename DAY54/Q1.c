#include <stdio.h>
#include <stdlib.h>

// Structure of tree node
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

// Queue for level order
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

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);
    int leftToRight = 1;

    while (front <= rear) {
        int size = rear - front + 1;
        int arr[100], i;

        // Store current level
        for (i = 0; i < size; i++) {
            struct Node* temp = dequeue();
            arr[i] = temp->data;

            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }

        // Print in zigzag manner
        if (leftToRight) {
            for (i = 0; i < size; i++)
                printf("%d ", arr[i]);
        } else {
            for (i = size - 1; i >= 0; i--)
                printf("%d ", arr[i]);
        }

        // Toggle direction
        leftToRight = !leftToRight;
    }
}

// Main function
int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4  5  6  7

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zigzagTraversal(root);

    return 0;
}
