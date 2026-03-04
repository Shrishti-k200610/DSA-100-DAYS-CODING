#include <stdio.h>

int stack[100];
int top = -1;

int main() {
    int n, ch, val;
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &ch);

        if(ch == 1) {          // Push
            scanf("%d", &val);
            if(top == 99)
                printf("Stack Overflow\n");
            else
                stack[++top] = val;
        }

        else if(ch == 2) {     // Pop
            if(top == -1)
                printf("Stack Underflow\n");
            else
                printf("%d\n", stack[top--]);
        }

        else if(ch == 3) {     // Display
            if(top == -1)
                printf("Stack is empty\n");
            else {
                for(int i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
