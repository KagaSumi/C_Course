#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

// Function to add two complex numbers
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to subtract two complex numbers
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Function to multiply two complex numbers
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Function to divide two complex numbers
Complex divide(Complex a, Complex b) {
    Complex result;
    float denominator = b.real * b.real + b.imag * b.imag;
    if (denominator == 0) {
        printf("Error: Division by zero\n");
        result.real = 0;
        result.imag = 0;
    } else {
        result.real = (a.real * b.real + a.imag * b.imag) / denominator;
        result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    }
    return result;
}

int main() {
    Complex num1, num2, result;

    // Taking input for the first complex number
    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    // Taking input for the second complex number
    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    // Calculating and displaying the results
    result = add(num1, num2);
    printf("Sum: %.1f + %.1fi\n", result.real, result.imag);

    result = subtract(num1, num2);
    printf("Difference: %.1f + %.1fi\n", result.real, result.imag);

    result = multiply(num1, num2);
    printf("Product: %.1f + %.1fi\n", result.real, result.imag);

    result = divide(num1, num2);
    printf("Quotient: %.1f + %.1fi\n", result.real, result.imag);

    return 0;
}

