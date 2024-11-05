#include <stdio.h>

void factorial() {
    // Initialize Variables
    int i, product = 1;

    //Loop 10 times
    for (i = 1; i < 11; ++i) {
        //Calculate Factorial and Print it out
        product = product * i;
        printf("%d ", product);
    }
}

void triangular_number() {
    //Initialize Variables
    int i = 5, result;

    //Loop from 5 - 50, step 5
    for (i; i < 50; i += 5) {
        //Perform Math and print
        result = (i * (i + 1)) / 2;
        printf("%d ", result);
    }
}

void division_number() {
    // Initialize Variables
    // I am using float here because we care about decimal places. User wouldn't know otherwise.
    float a, b;

    //Get User Input
    printf("Enter first number: ");
    scanf("%f", &a);
    printf("Enter second number: ");
    scanf("%f", &b);

    // Check Division by Zero Error
    if (b == 0) {
        printf("Division By Zero Error");
        return;
    }

    // Calculate Result
    float result = a / b;
    printf("Result: %.3f", result);
}

void fib_seq() {
    // Initialize Variables
    int a = 0, b = 1, temp;

    //Print First 2 numbers
    printf("%d %d ", a, b);

    //Loop 15 times
    for (int i = 2; i < 15; ++i) {
        //Calculate New Number
        temp = a + b;
        printf("%d ", temp);

        //Reassign values
        a = b;
        b = temp;
    }
}

void reverse_number() {
    //initialize Variables
    int user_input, result = 0, remainder, original;

    //Get user input
    printf("Enter a number: ");
    scanf("%d", &user_input);
    original = user_input;
    // Check if user_input is 0
    if (user_input == 0) {
        printf("0");
        return;
    }

    // While user_input is not 0 loop through
    // and take right most digit and append it result
    // then multiply it by 10 and shift it down to the left.
    while (user_input != 0) {
        remainder = user_input % 10;
        result = result * 10 + remainder;
        user_input /= 10;
    }

    printf("Reversed number: ");

    //Print Trailing 0s
    if (original %10 == 0){
        while(original % 10 == 0) {
            printf("0");
            original /=10;
        }
    }
    printf("%d\n", result);
}

int main() {
    factorial();
    printf("\n");
    triangular_number();
    printf("\n");
    division_number();
    printf("\n");
    fib_seq();
    printf("\n");
    reverse_number();
    return 0;
}
