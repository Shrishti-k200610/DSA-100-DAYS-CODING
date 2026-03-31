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

// Find index in inorder
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Pick current node from preorder
    struct Node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    // If only one node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, root->data);

    // Build left and right
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main
int main() {
    int n = 5;

    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[]  = {4, 2, 5, 1, 3};

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}
