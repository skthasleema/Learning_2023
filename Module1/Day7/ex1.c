#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student students[], int size, const char* input) {
    char* token;
    int i = 0;

    token = strtok(input, " ");
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    const char* input = "1001 Aron 100.00";
    int size = 1; // Assuming we want to initialize one structure

    struct Student students[size];

    initializeArray(students, size, input);

    printf("Initialized Student Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
