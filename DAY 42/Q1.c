#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int queue[100], stack[100];
    int top = -1;

    // Input queue
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Push into stack
    for(i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack (reverse)
    for(i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for(i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
