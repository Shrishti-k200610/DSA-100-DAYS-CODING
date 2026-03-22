#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// insert function
struct Node* insert(struct Node* root, int x) {
    if (root == NULL) {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->left = t->right = NULL;
        return t;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// inorder print
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, x;
    struct Node* root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}
