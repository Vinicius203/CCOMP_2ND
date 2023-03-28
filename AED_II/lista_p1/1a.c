#include <stdio.h>
#include <stdlib.h>

double func(int n);

int main()
{
    int n;
    double r;

    printf("Entre com um valor inteiro e positivo: ");
    scanf("%d", &n);

    r = func(n);

    printf("O resultado e igual a: %.3f", r);

    return 0;
}

double func(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return 1.0 / n + func(n - 1);
    }
}