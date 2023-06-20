#include <stdio.h>

typedef struct {
    int field1;
    float field2;
    char field3;
} Structure;

// Function to swap the fields of two structures using pointers
void swapStructures(Structure* s1, Structure* s2) {
    Structure temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main() {
    Structure struct1, struct2;

    // Input values for structure 1
    printf("Enter values for Structure 1:\n");
    printf("Field 1: ");
    scanf("%d", &(struct1.field1));
    printf("Field 2: ");
    scanf("%f", &(struct1.field2));
    printf("Field 3: ");
    scanf(" %c", &(struct1.field3));

    // Input values for structure 2
    printf("\nEnter values for Structure 2:\n");
    printf("Field 1: ");
    scanf("%d", &(struct2.field1));
    printf("Field 2: ");
    scanf("%f", &(struct2.field2));
    printf("Field 3: ");
    scanf(" %c", &(struct2.field3));

    printf("\nBefore swapping:\n");
    printf("Structure 1: Field 1 = %d, Field 2 = %.2f, Field 3 = %c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("Structure 2: Field 1 = %d, Field 2 = %.2f, Field 3 = %c\n", struct2.field1, struct2.field2, struct2.field3);

    // Swap the fields of the structures using pointers
    swapStructures(&struct1, &struct2);

    printf("\nAfter swapping:\n");
    printf("Structure 1: Field 1 = %d, Field 2 = %.2f, Field 3 = %c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("Structure 2: Field 1 = %d, Field 2 = %.2f, Field 3 = %c\n", struct2.field1, struct2.field2, struct2.field3);

    return 0;
}
