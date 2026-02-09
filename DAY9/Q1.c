#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, n;
    char temp;

    // Input string
    scanf("%s", s);

    n = strlen(s);

    // Mirror (reverse) the string
    for (i = 0; i < n / 2; i++) {
        temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    // Output
    printf("%s", s);

    return 0;
}
