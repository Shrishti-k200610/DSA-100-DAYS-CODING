#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int val;

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
    return head;
}

// Function to find intersection
void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node *temp1 = head1, *temp2 = head2;

    while(temp1 != NULL) {
        temp2 = head2;
        while(temp2 != NULL) {
            if(temp1->data == temp2->data) {
                printf("%d", temp1->data);
                return;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}
