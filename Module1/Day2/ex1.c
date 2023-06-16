#include <stdio.h>

void printExponent(double x) {
    unsigned long long* ptr = (unsigned long long*) &x; // Treat x as a pointer to an unsigned long long
    unsigned long long exponent = (*ptr >> 52) & 0x7FF; // Extract the exponent bits

    // Print in hexadecimal format
    printf("Hexadecimal: 0x%llX\n", exponent);

    // Print in binary format
    printf("Binary: 0b");
    for (int i = 11; i >= 0; i--) {
        int bit = (exponent >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}