#include<stdio.h>

int factorial(int n)
{
    if (n==0||n==1)
    {
        return 1;
    }
    else
    {
        return(n*factorial(n-1));
    }
}

int main()
{
    int n;
    printf("ENTER A NUMBER FOR FACTORIAL :- ");
    scanf("%d",&n);
    if(n<0)
    {
        printf("FACTORIAL FOR NEGATIVE NUMBER IS NOT DEFINED.");
        return 0;
    }
    else
    {
        printf("FACTORIAL OF %d IS %d.",n,factorial(n));
    }
}