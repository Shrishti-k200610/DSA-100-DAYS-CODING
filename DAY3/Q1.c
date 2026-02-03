#include <stdio.h>

int main() {
    int n, i, key, count = 0;
    int arr[100];

    // Input size
    scanf("%d", &n);

    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &key);

    // Linear search
    for (i = 0; i < n; i++) {
        count++;
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", count);
            return 0;
        }
    }

    // If not found
    printf("Not Found\n");
    printf("Comparisons = %d\n", count);

    return 0;
}
