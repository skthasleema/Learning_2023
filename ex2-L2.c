#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float calculateDistance(Point p1, Point p2) {
    float distance;
    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

int main() {
    Point point1, point2;

    printf("Enter coordinates for Point 1:\n");
    printf("x-coordinate: ");
    scanf("%f", &(point1.x));
    printf("y-coordinate: ");
    scanf("%f", &(point1.y));

    printf("\nEnter coordinates for Point 2:\n");
    printf("x-coordinate: ");
    scanf("%f", &(point2.x));
    printf("y-coordinate: ");
    scanf("%f", &(point2.y));

    float distance = calculateDistance(point1, point2);

    printf("\nDistance between the two points: %.2f\n", distance);

    return 0;
}
