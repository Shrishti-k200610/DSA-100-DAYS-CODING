#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 100

// Comparator for qsort
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];

    // Input names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names
    qsort(names, n, sizeof(names[0]), cmp);

    char winner[LEN];
    int maxVotes = 0;

    for (int i = 0; i < n; ) {
        int count = 1;

        // Count same names
        while (i + count < n && strcmp(names[i], names[i + count]) == 0) {
            count++;
        }

        // Update winner
        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }

        i += count;
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
