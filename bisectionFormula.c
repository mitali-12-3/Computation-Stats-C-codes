#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define e 0.0001
float f(float x)
{
    float r = (x * x * x) - (2*x) - 5;
    return r;
}
void bisect(float a,float b)
{
    float c;
    int i=0;
    if(f(a)*f(b)>0)
    {
        printf("not valid guesses for a and b \n");
        return;
    }
    while((b-a)>=e)
    {
        i++;
        if (f(a)*f(b) < 0)
        {
            c = (a + b) / 2;
            printf("iteration %d c=%f\n",i,c);
            if(f(c)==0.0)
                break;
            if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;
        }
    }
    printf(" final root is  %f",c);
    printf("total no : of iterations are %d",i);
}
void error(int p,int n)
{
    if((n-p)<=e)
        printf("root is %d",n);
    else
        bisect(p,n);
}
int main()
{
    float a,b;
    int ch;
    printf("enter a and b\n");
    scanf("%f", &a);
    scanf("%f", &b);
    printf("enter choice ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            bisect(a,b);
            break;
        }
        case 2:
        {
            error(a,b);
            break;
        }
        default :
            printf("invalid choice ");
    }
    return 0;
}