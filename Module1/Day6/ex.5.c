#include <stdio.h>

typedef struct {
    int field1;
    float field2;
    char field3;
} Structure;

void swapFields(Structure *s1, Structure *s2);

int main() {
    Structure struct1, struct2;

    printf("Enter the value for struct1:\n");
    printf("Field 1: ");
    scanf("%d", &struct1.field1);
    printf("Field 2: ");
    scanf("%f", &struct1.field2);
    printf("Field 3: ");
    scanf(" %c", &struct1.field3);

    printf("\nEnter the value for struct2:\n");
    printf("Field 1: ");
    scanf("%d", &struct2.field1);
    printf("Field 2: ");
    scanf("%f", &struct2.field2);
    printf("Field 3: ");
    scanf(" %c", &struct2.field3);

    printf("\nBefore swapping:\n");
    printf("struct1: %d %.2f %c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("struct2: %d %.2f %c\n", struct2.field1, struct2.field2, struct2.field3);

    swapFields(&struct1, &struct2);

    printf("\nAfter swapping:\n");
    printf("struct1: %d %.2f %c\n", struct1.field1, struct1.field2, struct1.field3);
    printf("struct2: %d %.2f %c\n", struct2.field1, struct2.field2, struct2.field3);

    return 0;
}

void swapFields(Structure *s1, Structure *s2) {
    Structure temp;

    temp.field1 = s1->field1;
    temp.field2 = s1->field2;
    temp.field3 = s1->field3;

    s1->field1 = s2->field1;
    s1->field2 = s2->field2;
    s1->field3 = s2->field3;

    s2->field1 = temp.field1;
    s2->field2 = temp.field2;
    s2->field3 = temp.field3;
}
