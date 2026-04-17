#include <stdio.h>
#include <stdlib.h>

// Structure for hash map entry
typedef struct {
    int key;
    int value;
} HashMapEntry;

// Simple hash function
int hash(int key, int size) {
    return abs(key) % size;
}

int maxLenZeroSum(int arr[], int n) {
    int max_len = 0;
    int sum = 0;

    // Create a simple hash map (using open addressing)
    int size = 2 * n + 1;
    HashMapEntry *map = (HashMapEntry *)malloc(size * sizeof(HashMapEntry));

    // Initialize map
    for (int i = 0; i < size; i++) {
        map[i].key = 1000000000; // dummy value indicating empty
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is zero
        if (sum == 0) {
            max_len = i + 1;
        }

        int idx = hash(sum, size);

        // Linear probing
        while (map[idx].key != 1000000000 && map[idx].key != sum) {
            idx = (idx + 1) % size;
        }

        // If sum already exists
        if (map[idx].key == sum) {
            int length = i - map[idx].value;
            if (length > max_len) {
                max_len = length;
            }
        } else {
            // Store first occurrence
            map[idx].key = sum;
            map[idx].value = i;
        }
    }

    free(map);
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSum(arr, n);
    printf("%d\n", result);

    return 0;
}
