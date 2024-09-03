#include <stdio.h>
#include <math.h>

// Define the function f(x)
double func(double x) {
    return x * x - 4 * x + 3;  // Example: f(x) = x^2 - 4x + 3
}

// Define the function Q(x) such that x = Q(x)
double Q(double x) {
    return (x * x + 3) / 4;  // Example: Q(x) = (x^2 + 3) / 4
}

// Iteration method function
double iteration(double x0, double e) {
    double x1;
    int n = 1;

    printf("Iteration\tX0\t\tX1\t\tf(X1)\n");

    while (n < 100) {  // Max iterations to avoid infinite loop
        x1 = Q(x0);  // Calculate X1 = Q(X0)
        double f1 = func(x1);

        printf("%d\t\t%lf\t%lf\t%lf\n", n, x0, x1, f1);

        if (fabs(f1) < e) {  // Check convergence criterion |f(X1)| < e
            return x1;
        }

        x0 = x1;  // Update X0 for the next iteration
        n++;
    }

    printf("No convergence after maximum iterations.\n");
    return x1;
}

int main() {
    printf("Name:\t Ashish Tyagi \t Roll no:\t 24\n");
    double x0, e;

    while (1) {
        printf("Enter initial guess X0 and Tolerance: ");
        if (scanf("%lf %lf", &x0, &e) != 2) {
            printf("Invalid input. Please enter numerical values.\n");
            while (getchar() != '\n');
            continue;
        }
        if (e <= 0) {
            printf("Tolerance must be positive.\n");
            continue;
        }

        double root = iteration(x0, e);
        printf("The value of the approximate root is %lf\n", root);

        char cont;
        printf("Do you want to try again? (y/n): ");
        while (getchar() != '\n');
        scanf("%c", &cont);
        if (cont == 'n' || cont == 'N') {
            break;
        }
    }

    return 0;
}
