#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];

    scanf("%d", &n);          // size of array

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // array elements
    }

    scanf("%d", &pos);        // position (1-based)
    scanf("%d", &x);          // element to insert

    // shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // insert the element
    arr[pos - 1] = x;

    // print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
