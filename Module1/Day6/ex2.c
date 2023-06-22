#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex readComplex();
void writeComplex(Complex num);
Complex addComplex(Complex num1, Complex num2);
Complex multiplyComplex(Complex num1, Complex num2);

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    num1 = readComplex();

    printf("Enter the second complex number:\n");
    num2 = readComplex();

    printf("\nComplex numbers you entered:\n");
    writeComplex(num1);
    writeComplex(num2);

    sum = addComplex(num1, num2);
    product = multiplyComplex(num1, num2);

    printf("\nSum of the complex numbers:\n");
    writeComplex(sum);

    printf("\nProduct of the complex numbers:\n");
    writeComplex(product);

    return 0;
}

Complex readComplex() {
    Complex num;

    printf("Enter the real part: ");
    scanf("%f", &num.real);

    printf("Enter the imaginary part: ");
    scanf("%f", &num.imag);

    return num;
}

void writeComplex(Complex num) {
    printf("%.2f + %.2fi\n", num.real, num.imag);
}

Complex addComplex(Complex num1, Complex num2) {
    Complex sum;

    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;

    return sum;
}

Complex multiplyComplex(Complex num1, Complex num2) {
    Complex product;

    product.real = num1.real * num2.real - num1.imag * num2.imag;
    product.imag = num1.real * num2.imag + num1.imag * num2.real;

    return product;
}
