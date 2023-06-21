#include <stdio.h>

#define MAX_SIZE 10

struct MyStruct {
    int id;
    char name[20];
    float score;
};

void initializeStructures(struct MyStruct array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        array[i].id = i + 1;
        sprintf(array[i].name, "Name%d", i + 1);
        array[i].score = 0.0;
    }
}

int main() {
    struct MyStruct myArray[MAX_SIZE];
    int i;

    initializeStructures(myArray, MAX_SIZE);

    printf("Initialized Array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("Element %d: id=%d, name=%s, score=%.2f\n", i, myArray[i].id, myArray[i].name, myArray[i].score);
    }

    return 0;
}
