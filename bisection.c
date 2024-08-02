#include<stdio.h>
#include<math.h>
double equation(double x)
{
return x*x*x-2*x-5;
}

void bisection(double a,double b,double e)
{
if(equation(a)*equation(b)>=0)
{
printf("invalid values");
return;
}
double mid=a;
int i=0;
printf("\nItr\tx0\tx1\tx2");
while((b-a)>=e)
{
mid=(b+a)/2;
double fmid=equation(mid);

printf("\n%d\t%lf\t%lf\t%lf",i,a,b,mid);
if(fmid==0.0)
break;
if(equation(mid)*equation(a)<0)
b=mid;
else
a=mid;

i++;
}
printf("\nthe value of root=: %lf \n",mid);
}


int main()
{
printf("\n\n\t\tName:Ashish Tyagi \n\t\tRoll no:24\n\t\tSec:D\n");
double g1,g2,err;
printf("\n input lower guess: ");
scanf("%lf",&g1);
printf("\n input upper guess: ");
scanf("%lf",&g2);
printf("\n input error :");
scanf("%lf",&err);
bisection(g1,g2,err);
return 0;
}
