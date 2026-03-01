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

// Function to rotate list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int length = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make list circular
    temp->next = head;

    // Reduce k if greater than length
    k = k % length;

    // Find new tail position (length - k)
    int steps = length - k;
    temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // Set new head
    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

int main() {
    int n, k, value;
    struct Node *head = NULL, *temp = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
