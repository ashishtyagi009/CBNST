#include <stdio.h>
#include <math.h>

double func(double x)
{
    return x * x * x - 2 * x - 5;
}

void regulaFalsi(double a, double b, double e)
{
    if (func(a) * func(b) >= 0)
    {
        printf("Error: The function has the same sign at the endpoints.\n");
        return;
    }
    double mid;
    printf("Iteration\ta\tb\tc\tF(c)\n");
    int itr = 1;
    while (1)
    {
        mid = (a * func(b) - b * func(a)) / (func(b) - func(a));
        double f_mid = func(mid);
        printf("%d\t%lf\t%lf\t%lf\t%lf\n", itr, a, b, mid, f_mid);
        if (fabs(f_mid) < e) {
            break;
        }
        if (f_mid * func(a) < 0) {
            b = mid;
        }
        else {
            a = mid;
        }
        itr++;
    }
    printf("The value of the approximate root is %lf\n", mid);
}

int main()
{
printf("Name:t\t Ashish Tyagi \n Roll no:\t\t 24");
    double a, b, e;
    while (1)
    {
        printf("Enter X0, X1, Tolerance: ");
        if (scanf("%lf %lf %lf", &a, &b, &e) != 3)
        {
            printf("Invalid input. Please enter numerical values.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        if (e <= 0)
        {
            printf("Tolerance must be positive.\n");
            continue;
        }
        regulaFalsi(a, b, e);
        char cont;
        printf("Do you want to try again? (y/n): ");
        while (getchar() != '\n'); // Clear the input buffer
        scanf("%c", &cont);
        if (cont == 'n' || cont == 'N')
        {
            break;
        }
    }
    return 0;
}
