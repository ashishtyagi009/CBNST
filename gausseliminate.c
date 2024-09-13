#include <stdio.h>
#include <math.h>

#define N 3  // Number of equations (3 for this case)

void printMatrix(double matrix[N][N+1]) {
    // Function to print the augmented matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%10.4lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussianElimination(double matrix[N][N+1], double result[N]) {
    // Perform Gaussian elimination to convert matrix to upper triangular form
    for (int i = 0; i < N; i++) {
        // Pivoting: Swap rows if necessary for numerical stability
        for (int k = i+1; k < N; k++) {
            if (fabs(matrix[i][i]) < fabs(matrix[k][i])) {
                for (int j = 0; j <= N; j++) {
                    double temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }

        // Forward elimination
        for (int k = i+1; k < N; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= N; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }

        printf("Matrix after step %d of forward elimination:\n", i+1);
        printMatrix(matrix);
    }

    // Back substitution to find the result
    for (int i = N-1; i >= 0; i--) {
        result[i] = matrix[i][N];
        for (int j = i+1; j < N; j++) {
            result[i] -= matrix[i][j] * result[j];
        }
        result[i] /= matrix[i][i];
    }
}

int main() {
    printf("Ashish Tyagi \t Section D \t Roll no 24\n");

    // Define the augmented matrix (3 equations with 3 unknowns)
    double matrix[N][N+1];  // Last column is the constants (RHS)
    double result[N];       // To store the solutions of x, y, z

    // Input the augmented matrix
    printf("Enter the coefficients of the equations (including the constants):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Initial Augmented Matrix:\n");
    printMatrix(matrix);

    // Perform Gaussian elimination and back substitution
    gaussianElimination(matrix, result);

    // Output the results
    printf("The solutions are:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %10.4lf\n", i+1, result[i]);
    }

    return 0;
}
