#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b) {
    if (b == 0)
        return 1;          // base case
    else
        return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Input two space-separated integers
    scanf("%d %d", &a, &b);

    // Print result
    printf("%d", power(a, b));

    return 0;
}
