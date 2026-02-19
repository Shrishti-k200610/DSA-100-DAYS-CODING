#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = abs(arr[0] + arr[1]);
    int num1 = arr[0], num2 = arr[1];

    // Check all pairs
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < min_sum) {
                min_sum = abs(sum);
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    // Print result
    printf("%d %d", num1, num2);

    return 0;
}
