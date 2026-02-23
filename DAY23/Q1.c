#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Merge two sorted lists
struct Node* merge(struct Node* l1, struct Node* l2) {
    struct Node dummy;          // temporary node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL, *temp, *head1 = NULL, *head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = createNode(x);
        if (head1 == NULL)
            head1 = temp;
        else
            l1->next = temp;
        l1 = temp;
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        temp = createNode(x);
        if (head2 == NULL)
            head2 = temp;
        else
            l2->next = temp;
        l2 = temp;
    }

    struct Node* result = merge(head1, head2);
    printList(result);

    return 0;
}