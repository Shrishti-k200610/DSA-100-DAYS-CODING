#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val;
    struct Node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    // Create circular linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    if(temp != NULL) {
        temp->next = head;
    }

    // Traverse circular linked list
    if(head != NULL) {
        struct Node* ptr = head;
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while(ptr != head);
    }

    return 0;
}
