#include <stdio.h>

void printExponent(double x) {
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long bits = *ptr;
    unsigned int exponent = (bits >> 52) & 0x7FF;  // Extracting the exponent bits
    
    printf("Hexadecimal: 0x%X\n", exponent);
    printf("Binary: 0b");
    
    // Printing the exponent bits in binary format
    int i;
    for (i = 10; i >= 0; i--) {
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
