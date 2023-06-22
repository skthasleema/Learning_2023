#include <stdio.h>

// Define the structure
struct Person {
    char name[50];
    int age;
    float salary;
};

// Function to display all members in the array of structures
void displayMembers(struct Person members[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Member %d:\n", i + 1);
        printf("Name: %s\n", members[i].name);
        printf("Age: %d\n", members[i].age);
        printf("Salary: %.2f\n\n", members[i].salary);
    }
}

int main() {
    // Create an array of structures
    struct Person members[] = {
        {"John Doe", 25, 2500.50},
        {"Jane Smith", 30, 3500.75},
        {"Michael Johnson", 35, 4500.25}
    };

    // Calculate the size of the array
    int size = sizeof(members) / sizeof(members[0]);

    // Call the function to display members
    displayMembers(members, size);

    return 0;
}
