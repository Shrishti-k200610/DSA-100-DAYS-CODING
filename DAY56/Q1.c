#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check mirror
int isMirror(struct Node* t1, struct Node* t2) {
    // Both NULL
    if (t1 == NULL && t2 == NULL)
        return 1;

    // One NULL
    if (t1 == NULL || t2 == NULL)
        return 0;

    // Check data + mirror condition
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Check symmetric
int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}

// Main
int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     2
    //    / \   / \
    //   3  4  4   3

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
