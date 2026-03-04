#include <stdio.h>

int stack[100];
int top = -1;

int main() {
    int n, m;

    // Number of elements to push
    scanf("%d", &n);

    // Push elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    // Number of pops
    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        if(top != -1)
            top--;
    }

    // Display remaining elements (top to bottom)
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
