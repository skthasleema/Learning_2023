#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student students[], int size, int rollno[], const char* names[], float marks[]) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = rollno[i];
        strncpy(students[i].name, names[i], sizeof(students[i].name) - 1);
        students[i].marks = marks[i];
    }
}

int main() {
    int size = 3;
    int rollno[] = {1001, 1002, 1003};
    const char* names[] = {"Aron", "Bob", "Catherine"};
    float marks[] = {100.00, 90.50, 95.75};

    struct Student students[size];

    initializeArray(students, size, rollno, names, marks);

    printf("Initialized Student Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
