#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {

    // If both values are smaller, go left
    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    // If both values are greater, go right
    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    // Otherwise, this is LCA
    return root;
}

int main() {
    int n, i, val, a, b;
    struct Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter two nodes: ");
    scanf("%d %d", &a, &b);

    struct Node* lca = findLCA(root, a, b);

    printf("LCA = %d\n", lca->data);

    return 0;
}
