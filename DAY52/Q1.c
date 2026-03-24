#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from array (level order)
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Function to find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If one node matches
    if (root->data == n1 || root->data == n2)
        return root;

    // Search left and right
    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    // If both sides return non-NULL, this is LCA
    if (left && right)
        return root;

    // Otherwise return non-NULL child
    return (left != NULL) ? left : right;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int n1, n2;
    printf("Enter two nodes: ");
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n, 0);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca)
        printf("LCA: %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
