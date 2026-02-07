#include <stdio.h>

// Recursive function to find Fibonacci number
int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);   // input n
    printf("%d", fib(n));  // print nth Fibonacci number
    return 0;
}
