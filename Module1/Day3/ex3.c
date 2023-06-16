#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;

    // Convert the integer to a string for easier manipulation
    char str[5];
    sprintf(str, "%d", num);

    int i, j;
    for (i = 0; i < 4; i++) {
        // Create a temporary string to store the number with the current digit deleted
        char temp[4];
        int k = 0;
        for (j = 0; j < 4; j++) {
            if (j != i) {
                temp[k] = str[j];
                k++;
            }
        }
        temp[k] = '\0';

        // Convert the temporary string back to an integer
        int tempNum = atoi(temp);

        // Update the largest number if necessary
        if (tempNum > largest) {
            largest = tempNum;
        }
    }

    return largest;
}

int main() {
    int number;
    printf("Enter a 4-digit number: ");
    scanf("%d", &number);

    int result = findLargestNumber(number);
    printf("The largest number obtained by deleting a single digit: %d\n", result);

    return 0;
}