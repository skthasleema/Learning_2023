#include <stdio.h>
#include <limits.h>

void findSmallestAndLargestDigits(int n, int numbers[]) {
    int smallestDigit = INT_MAX;
    int largestDigit = INT_MIN;
    int i;

    for (i = 0; i < n; i++) {
        int number = numbers[i];

        // Iterate over each digit in the current number
        while (number != 0) {
            int digit = number % 10;
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }
            if (digit > largestDigit) {
                largestDigit = digit;
            }
            number /= 10;
        }
    }

    // Print the results
    if (smallestDigit == INT_MAX || largestDigit == INT_MIN) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Not Valid\n");
        return 0;
    }

    int numbers[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    findSmallestAndLargestDigits(n, numbers);

    return 0;
}