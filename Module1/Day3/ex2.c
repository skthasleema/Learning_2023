#include <stdio.h>

void print_bits(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    unsigned int integer;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &integer);
    print_bits(integer);
    return 0;
}