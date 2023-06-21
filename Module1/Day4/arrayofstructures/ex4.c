#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct MyStruct {
    int id;
    char name[20];
    float score;
};

int compareDescending(const void* a, const void* b) {
    const struct MyStruct* structA = (const struct MyStruct*)a;
    const struct MyStruct* structB = (const struct MyStruct*)b;

    if (structA->score > structB->score) {
        return -1;
    } else if (structA->score < structB->score) {
        return 1;
    } else {
        return 0;
    }
}

void sortStructures(struct MyStruct array[], int size) {
    qsort(array, size, sizeof(struct MyStruct), compareDescending);
}

void displayStructures(struct MyStruct array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Element %d: id=%d, name=%s, score=%.2f\n", i, array[i].id, array[i].name, array[i].score);
    }
}

int main() {
    struct MyStruct myArray[MAX_SIZE];
    int i;

    // Assume myArray has been initialized with data before sorting

    sortStructures(myArray, MAX_SIZE);

    printf("Sorted Array:\n");
    displayStructures(myArray, MAX_SIZE);

    return 0;
}
