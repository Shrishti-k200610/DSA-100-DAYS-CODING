#include <stdio.h>

// function to find height
int height(int a[], int n, int i) {
    if (i >= n || a[i] == -1)
        return 0;

    int left = height(a, n, 2*i + 1);
    int right = height(a, n, 2*i + 2);

    return (left > right ? left : right) + 1;
}

int main() {
    int n, a[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("%d", height(a, n, 0));

    return 0;
}
