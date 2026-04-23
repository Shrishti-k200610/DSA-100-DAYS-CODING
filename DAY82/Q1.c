#include <stdio.h>

// Function to find lower bound (first element >= x)
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;  // move left
        } else {
            low = mid + 1;   // move right
        }
    }
    return ans;
}

// Function to find upper bound (first element > x)
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;  // move left
        } else {
            low = mid + 1;   // move right
        }
    }
    return ans;
}

int main() {
    int n, x;

    // Input
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    // Find bounds
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    // Output
    printf("%d %d\n", lb, ub);

    return 0;
}
