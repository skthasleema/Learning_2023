#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *boxPtr) {
    double volume = boxPtr->length * boxPtr->width * boxPtr->height;
    return volume;
}

double calculateSurfaceArea(struct Box *boxPtr) {
    double surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
    return surfaceArea;
}

int main() {
    struct Box myBox;
    struct Box *boxPtr = &myBox;

    // Assign values to the box dimensions
    boxPtr->length = 5.0;
    boxPtr->width = 3.0;
    boxPtr->height = 2.0;

    // Calculate volume and surface area using structure pointer with (*) and (.) operators
    double volume = calculateVolume(&myBox);
    double surfaceArea = calculateSurfaceArea(&myBox);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
