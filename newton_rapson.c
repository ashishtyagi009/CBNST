#include <stdio.h>
#include <math.h>

#define E 2.718281828459045 // Value of e for precise calculations

// Define the function f(x) = cos(x) - x * e^x
float f(float x) {
    return cos(x) - x * pow(E, x);
}

// Define the derivative of f(x), which is f'(x) = -sin(x) - e^x - x * e^x
float df(float x) {
    return -sin(x) - pow(E, x) - x * pow(E, x);
}

int main() {
    printf("Name : Ashish Tyagi\n");
    printf("Roll : 24\n");
    printf("Sect : D\n");
    float a, b, x0, x1, h, allerr;
    
    // Input for the interval [a, b] on separate lines
    printf("Enter the value of a: ");
    scanf("%f", &a);
    
    printf("Enter the value of b: ");
    scanf("%f", &b);

    // Input for the allowed error on a separate line
    printf("Enter the allowed error: ");
    scanf("%f", &allerr);

    // Calculate function values at a and b
    float fa = f(a);
    float fb = f(b);

    // Check if f(a) and f(b) have opposite signs
    if (fa * fb >= 0) {
        printf("Function does not change sign in the interval [a, b].\n");
        return 1;
    }

    // Choose initial guess x0 based on which function value is closer to zero
    if (fabs(fa) < fabs(fb)) {
        x0 = a;
    } else {
        x0 = b;
    }

    printf("Initial guess x0 = %9.6f\n", x0);
    
    int itr = 0; // Initialize iteration counter

    while (1) {
        itr++;
        h = f(x0) / df(x0);
        x1 = x0 - h;
        printf("At Iteration no. %3d, x = %9.6f\n", itr, x1);
        
        if (fabs(h) < allerr) {
            printf("After %3d iterations, root = %8.6f\n", itr, x1);
            return 0;
        }
        
        x0 = x1;
    }

    // This line will never be reached; included for completeness
    printf("The required solution does not converge.\n");
    return 1;
}
