#include <stdio.h>

int findMaxUsingIfElse(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int findMaxUsingTernary(int num1, int num2) {
    int max = (num1 > num2) ? num1 : num2;
    return max;
}

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int max1 = findMaxUsingIfElse(num1, num2);
    printf("Using if-else: The maximum number is %d\n", max1);
    
    int max2 = findMaxUsingTernary(num1, num2);
    printf("Using ternary operator: The maximum number is %d\n", max2);
    
    return 0;
}