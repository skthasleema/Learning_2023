#include <stdio.h>

typedef struct {
    char name[50];
    int marks;
} Student;

void sortStudents(Student arr[], int n) {
    int i, j;
    Student temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i;
    Student students[] = {
        {"John", 80},
        {"Jane", 95},
        {"Mike", 75},
        {"Sarah", 90},
        {"David", 85}
    };
    int numStudents = sizeof(students) / sizeof(students[0]);
    
    printf("Before sorting:\n");
    for (i = 0; i < numStudents; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }
    
    sortStudents(students, numStudents);
    
    printf("\nAfter sorting:\n");
    for (i = 0; i < numStudents; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }
    
    return 0;
}
