#include <stdio.h>

int main() {
    int n, a[100];

    scanf("%d", &n);

    // input (level order already)
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // print level order (same as input)
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            printf("%d ", a[i]);
    }

    return 0;
}
