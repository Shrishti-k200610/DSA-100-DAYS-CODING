#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// insert (to build BST)
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

// search in BST
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n, x, key;
    struct Node* root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);

    if (search(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
