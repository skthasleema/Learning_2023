#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

void calculateVolume(struct Box* boxPtr) {
    float volume = boxPtr->length * boxPtr->width * boxPtr->height;
    printf("Volume: %.2f\n", volume);
}

void calculateSurfaceArea(struct Box* boxPtr) {
    float surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
    printf("Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;

    // Input dimensions
    printf("Enter length: ");
    scanf("%f", &(boxPtr->length));
    printf("Enter width: ");
    scanf("%f", &(boxPtr->width));
    printf("Enter height: ");
    scanf("%f", &(boxPtr->height));

    // Calculate volume and surface area
    calculateVolume(boxPtr);
    calculateSurfaceArea(boxPtr);

    return 0;
}
