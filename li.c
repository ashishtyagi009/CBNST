#include <stdio.h>

void main() {
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;

    // Input Section
    printf("========================================\n");
    printf("       Lagrange Interpolation\n");
    printf("========================================\n");
    printf("Enter number of data points (n): ");
    scanf("%d", &n);

    printf("Enter data points:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter interpolation point (xp): ");
    scanf("%f", &xp);

    // Implementing Lagrange Interpolation
    for (i = 0; i < n; i++) {
        p = 1; // Initialize p for the i-th term
        for (j = 0; j < n; j++) {
            if (i != j) {
                p *= (xp - x[j]) / (x[i] - x[j]); // Calculate the Lagrange basis polynomial
            }
        }
        yp += p * y[i]; // Add the contribution of the i-th term
    }

    // Output the result
    printf("========================================\n");
    printf("Interpolated value at %.3f is %.3f.\n", xp, yp);
    printf("========================================\n");
}
