#include <stdio.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        }
        else if (mid * mid < n) {
            ans = mid;      // store possible answer
            low = mid + 1;  // move right
        }
        else {
            high = mid - 1; // move left
        }
    }

    printf("Integer square root: %d\n", ans);

    return 0;
}
