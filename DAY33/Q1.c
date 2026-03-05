#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack functions
void push(char c) {
    if(top < MAX - 1) stack[++top] = c;
}

char pop() {
    if(top >= 0) return stack[top--];
    return '\0';
}

char peek() {
    if(top >= 0) return stack[top];
    return '\0';
}

// Operator precedence
int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char* exp) {
    char postfix[MAX] = "";
    int k = 0;
    
    for(int i = 0; exp[i]; i++) {
        char c = exp[i];

        if(isalnum(c)) { // Operand
            postfix[k++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else { // Operator
            while(top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char exp[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);
    return 0;
}
