#include <stdio.h>
#include <math.h>
#include <stdlib.h> // For exit function

// Define the function and its derivatives
float f(float x) {
    return cos(x) - 3*x + 1;
}

float fl(float x) {
    return (cos(x) + 1) / 3;
}

float f2(float x) {
    return acos(3*x - 1);
}

float dl(float x) {
    return -sin(x) / 3;
}

float d2(float x) {
    return -3 / sqrt(1 - pow(3*x - 1, 2));
}

int main() {
    float a, b, x0, h, e;
    int it = 0;

    // User information
    printf("Name: Ashish Tyagi\nRoll no.: 24\n");

    // Input guesses for initial values
    printf("Guess the initial values of a and b for the equation cos(x) = 3x - 1\n"); 
    scanf("%f%f", &a, &b);

    // Check if initial guesses are valid
    while (f(a) * f(b) > 0) {
        printf("Invalid guesses! The function values at a and b must have opposite signs.\n");
        printf("Guess the values again!\n");
        scanf("%f%f", &a, &b);
    }

    // Input tolerable error
    printf("Enter the value of tolerable error\n");
    scanf("%f", &e);

    // Choose initial guess based on function values
    x0 = (fabs(f(a)) < fabs(f(b))) ? a : b;

    // Output header
    printf("Iteration\tRoot\n");

    // Determine which method to use
    if (fabs(dl(x0)) < 1) {
        // Using fixed-point iteration with fl
        do {
            h = fl(x0);
            x0 = h;
            it++;
            printf("%d\t\t%f\n", it, h);
        } while (fabs(f(h)) > e);
    } else if (fabs(d2(x0)) < 1) {
        // Using fixed-point iteration with f2
        do {
            h = f2(x0);
            x0 = h;
            it++;
            printf("%d\t\t%f\n", it, h);
        } while (fabs(f(h)) > e);
    } else {
        printf("Real roots cannot be found in this range\n");
        exit(0);
    }

    // Output the result
    printf("The real approximate root after %d iterations is %f\n", it, h);

    return 0;
}
