#include <stdio.h>
#include <string.h>

struct Student{
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* inputString, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token;
    int count = 0;
    
    // Parse the input string and initialize the array of structures
    token = strtok((char*)inputString, delimiter);
    while (token != NULL && count < numStudents) {
        students[count].rollno = atoi(token);
        
        token = strtok(NULL, delimiter);
        if (token != NULL) {
            strncpy(students[count].name, token, sizeof(students[count].name) - 1);
            students[count].name[sizeof(students[count].name) - 1] = '\0';
        }
        
        token = strtok(NULL, delimiter);
        if (token != NULL) {
            students[count].marks = atof(token);
        }
        
        count++;
        token = strtok(NULL, delimiter);
    }
}

int main() {
    const char* inputString = "1001 Aron 100.00";
    const int numStudents = 1;
    struct Student students[numStudents];
    
    parseString(inputString, students, numStudents);
    
    // Print the initialized array of structures
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
    
    return 0;
}
