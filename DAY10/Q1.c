#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right;
    int flag = 1;

    // read string
    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    // two-pointer check
    while (left < right) {
        if (s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
