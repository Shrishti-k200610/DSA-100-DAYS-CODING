#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, key, count = 0;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Creating linked list
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter value: ");
        scanf("%d", &newnode->data);
        
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Enter key to count: ");
    scanf("%d", &key);

    // Counting occurrences
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("Occurrences of %d = %d\n", key, count);

    return 0;
}
