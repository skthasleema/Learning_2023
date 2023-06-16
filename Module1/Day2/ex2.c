#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char temp[size]; // Temporary buffer for swapping data
    char* ptrA = (char*)a;
    char* ptrB = (char*)b;

    // Copy data from a to temp
    for (size_t i = 0; i < size; i++) {
        temp[i] = ptrA[i];
    }

    // Copy data from b to a
    for (size_t i = 0; i < size; i++) {
        ptrA[i] = ptrB[i];
    }

    // Copy data from temp to b
    for (size_t i = 0; i < size; i++) {
        ptrB[i] = temp[i];
    }
}

int main() {
    int a = 10;
    int b = 20;

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 3.14;
    double y = 2.71;

    printf("Before swap: x = %f, y = %f\n", x, y);
    swap(&x, &y, sizeof(double));
    printf("After swap: x = %f, y = %f\n", x, y);

    return 0;
}