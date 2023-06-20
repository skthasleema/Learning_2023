#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of Student structures
    Student* students = (Student*)malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Input data for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &(students[i].age));
        printf("GPA: ");
        scanf("%f", &(students[i].gpa));
    }

    // Display data for each student
    printf("\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
