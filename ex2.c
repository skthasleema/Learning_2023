#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

// Function to read a complex number from the user
void readComplexNumber(Complex* c) {
    printf("Enter real part: ");
    scanf("%f", &(c->real));
    printf("Enter imaginary part: ");
    scanf("%f", &(c->imaginary));
}

// Function to write a complex number to the console
void writeComplexNumber(Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imaginary);
}

// Function to add two complex numbers
Complex addComplexNumbers(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplexNumbers(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

int main() {
    Complex num1, num2, sum, product;

    // Read the first complex number
    printf("Enter the first complex number:\n");
    readComplexNumber(&num1);

    // Read the second complex number
    printf("Enter the second complex number:\n");
    readComplexNumber(&num2);

    // Perform addition
    sum = addComplexNumbers(num1, num2);
    printf("Sum of the complex numbers: ");
    writeComplexNumber(sum);

    // Perform multiplication
    product = multiplyComplexNumbers(num1, num2);
    printf("Product of the complex numbers: ");
    writeComplexNumber(product);

    return 0;
}
