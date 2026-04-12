#include <stdio.h>
#include <string.h>

#define EMPTY -1

int m;              // table size
int table[1000];    // assuming max size

void init() {
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
}

void insert(int key) {
    for (int i = 0; i < m; i++) {
        int idx = (key % m + i * i) % m;
        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
    // Optional: handle table full
}

void search(int key) {
    for (int i = 0; i < m; i++) {
        int idx = (key % m + i * i) % m;
        
        if (table[idx] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }
        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    init();

    while (q--) {
        char op[10];
        int val;

        scanf("%s %d", op, &val);

        if (strcmp(op, "INSERT") == 0) {
            insert(val);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(val);
        }
    }

    return 0;
}
