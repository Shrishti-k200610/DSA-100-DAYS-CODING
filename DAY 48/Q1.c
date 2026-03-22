#include <stdio.h>

// function to count leaf nodes
int countLeaf(int a[], int n, int i) {
    if (i >= n || a[i] == -1)
        return 0;

    int left = 2*i + 1;
    int right = 2*i + 2;

    // if both children are absent → leaf node
    if ((left >= n || a[left] == -1) &&
        (right >= n || a[right] == -1))
        return 1;

    return countLeaf(a, n, left) + countLeaf(a, n, right);
}

int main() {
    int n, a[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("%d", countLeaf(a, n, 0));

    return 0;
}