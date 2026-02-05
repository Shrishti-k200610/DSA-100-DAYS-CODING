#include <stdio.h>

int main() {
    int p, q;
    int i = 0, j = 0, k = 0;

    // Input sizes
    scanf("%d", &p);
    int a[p];
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    int b[q];
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int c[p + q];
    i = 0;
    j = 0;

    // Merge both sorted arrays
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // Remaining elements of first array
    while (i < p) {
        c[k++] = a[i++];
    }

    // Remaining elements of second array
    while (j < q) {
        c[k++] = b[j++];
    }

    // Output
    for (i = 0; i < p + q; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
