#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

struct MyStruct {
    int id;
    char name[20];
    float score;
};

void searchByName(struct MyStruct array[], int size, const char* targetName) {
    int i;
    int found = 0;

    for (i = 0; i < size; i++) {
        if (strcmp(array[i].name, targetName) == 0) {
            printf("Element found at index %d: id=%d, name=%s, score=%.2f\n", i, array[i].id, array[i].name, array[i].score);
            found = 1;
        }
    }

    if (!found) {
        printf("No element found with the name: %s\n", targetName);
    }
}

int main() {
    struct MyStruct myArray[MAX_SIZE];
    int i;

    // Assume myArray has been initialized with data before searching

    searchByName(myArray, MAX_SIZE, "John");

    return 0;
}
