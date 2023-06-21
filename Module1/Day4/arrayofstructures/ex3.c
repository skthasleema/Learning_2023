#include <stdio.h>

#define MAX_SIZE 10

struct MyStruct {
    int id;
    char name[20];
    float score;
};

void displayStructures(struct MyStruct array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Element %d: id=%d, name=%s, score=%.2f\n", i, array[i].id, array[i].name, array[i].score);
    }
}

int main() {
    struct MyStruct myArray[MAX_SIZE];
    int i;

    // Assume myArray has been initialized with data before calling the display function

    displayStructures(myArray, MAX_SIZE);

    return 0;
}
