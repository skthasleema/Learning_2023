#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int searchStudent(Student arr[], int n, const char* name) {
    int i;
    
    for (i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return i;  // Return the index if the name is found
        }
    }
    
    return -1;  // Return -1 if the name is not found
}

int main() {
    int index;
    Student students[] = {
        {"John", 80},
        {"Jane", 95},
        {"Mike", 75},
        {"Sarah", 90},
        {"David", 85}
    };
    int numStudents = sizeof(students) / sizeof(students[0]);
    const char* searchName = "Mike";
    
    index = searchStudent(students, numStudents, searchName);
    
    if (index != -1) {
        printf("Student %s found at index %d.\n", searchName, index);
        printf("Marks: %d\n", students[index].marks);
    } else {
        printf("Student %s not found.\n", searchName);
    }
    
    return 0;
}
