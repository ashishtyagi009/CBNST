#include <stdio.h>
#include <math.h>

double func(double x)
{
    return x * x * x - 5 * x + 1;
}

double secant(double a, double b, double e)
{
double c;
    int n=1;
        printf("Iteration\ta\tb\tc\tF(c)\n");
    while(n<5)
    {
    double f0=func(a);
    double f1=func(b);
    if(f1-f0==0)
    {
    printf("error");
    return b;
    }
    c=b-f1*(b-a)/(f1-f0);
    double f2=func(c);
            printf("%d\t%lf\t%lf\t%lf\t%lf\n", n, a, b, c, f2);
    if(fabs(c-b)<e)
    {
    return c;
    }
    a=b;
    b=c;
    n++;
    }
    printf(" no convergence");
    return c;
}

int main()
{
printf("Name:\t Ashish Tyagi \t Roll no:\t 24\n");
    double a, b, e;
    while (1)
    {
        printf("Enter X0, X1, Tolerance: ");
        if (scanf("%lf %lf %lf", &a, &b, &e) != 3)
        {
            printf("Invalid input. Please enter numerical values.\n");
            while (getchar() != '\n');
            continue;
        }
        if (e <= 0)
        {
            printf("Tolerance must be positive.\n");
            continue;
        }
        double root =secant(a, b, e);
        printf("The value of the approximate root is %lf\n", root);
        char cont;
        printf("Do you want to try again? (y/n): ");
        while (getchar() != '\n');
        scanf("%c", &cont);
        if (cont == 'n' || cont == 'N')
        {
            break;
        }
    }
    return 0;
}
