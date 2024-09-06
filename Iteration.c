#include <stdio.h>
#include <math.h>

// Define the function f(x) = cos(x) - 3*x + 1
float f(float x) {
    return cos(x) - 3*x + 1;
}

// Define the fixed-point iteration functions
float g1(float x) {
    return (cos(x) + 1) / 3;
}

float g2(float x) {
    return acos(3*x - 1);
}

// Derivative of g1(x)
float dg1(float x) {
    return -sin(x) / 3;
}

// Derivative of g2(x)
float dg2(float x) {
    return -3 / sqrt(1 - pow(3*x - 1, 2));
}

int main() {
    float a, b, x0, h, e;
    int it = 0;

    // Updated user information
    printf("Name: Ashish Tyagi\nRoll no.: 24\nSect: D\n");

    // Input initial guesses
    printf("Guess the initial values of a and b for the equation cos(x) = 3x - 1\n");
    scanf("%f%f", &a, &b);

    // Check if initial guesses are valid
    while (f(a) * f(b) > 0) {
        printf("Invalid guesses!\nGuess the values again!\n");
        scanf("%f%f", &a, &b);
    }

    // Input tolerable error
    printf("Enter the value of tolerable error\n");
    scanf("%f", &e);

    // Choose the initial point x0
    x0 = (fabs(f(a)) < fabs(f(b))) ? a : b;

    // Print the derivatives for both methods at the initial guess
    float dg1_value = dg1(x0);
    float dg2_value = dg2(x0);

    printf("valuen of g1'(x0) = %f is %f\n", x0, dg1_value);
    printf("value of g2'(x0) = %f is %f\n", x0, dg2_value);

    // Choose the iteration method based on the derivative's condition
    if (fabs(dg1_value) < 1) {
        // Print the chosen method
        printf("Chosen method: g1(x)\n");
        printf("Iteration\tx0\n");

        do {
            h = g1(x0);
            x0 = h;
            it++;
            printf("%d\t\t%f\n", it, h);
        } while (fabs(f(h)) > e);
    } else if (fabs(dg2_value) < 1) {
        // Print the chosen method
        printf("Chosen method: g2(x)\n");
        printf("Iteration\tx0\n");

        do {
            h = g2(x0);
            x0 = h;
            it++;
            printf("%d\t\t%f\n", it, h);
        } while (fabs(f(h)) > e);
    } else {
        printf("Real roots cannot be found in this range\n");
        return 0;
    }

    printf("The real approximate root after %d iterations is %f\n", it, h);
    return 0;
}
