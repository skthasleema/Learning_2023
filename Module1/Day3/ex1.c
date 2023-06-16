#include <stdio.h>

void printNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    for (int i = 1; i <= n - 2; i++) {
        printf(" ");
    }
}

void printPattern(int n) {
    for (int i = n; i >= 1; i--) {
        printNumbers(i);
        printSpaces(i);
        printNumbers(i);
        printf("\n");
    }
}

int main() {
    int n = 5;
    printPattern(n);

    return 0;
}