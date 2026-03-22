#include <stdio.h>

void heapify(int a[], int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

int main() {
    int n, i, j, a[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Build max heap
    for(i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Heap sort
    for(j = n-1; j > 0; j--) {
        int temp = a[0];
        a[0] = a[j];
        a[j] = temp;

        heapify(a, j, 0);
    }

    // Print sorted array
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
