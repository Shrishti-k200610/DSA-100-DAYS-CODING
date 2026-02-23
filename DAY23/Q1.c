#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// create node
struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// merge two sorted lists
struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

// print list
void print(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL, *temp;

    // first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = newNode(x);
        temp->next = head1;
        head1 = temp;
    }

    // second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        temp = newNode(x);
        temp->next = head2;
        head2 = temp;
    }

    head1 = merge(head1, head2);
    print(head1);

    return 0;
}
