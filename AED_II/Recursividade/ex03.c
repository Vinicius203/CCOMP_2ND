#include <stdio.h>

int produto(int n);

int main()
{

    int n;

    printf("Entre com um numero inteiro e positivo: ");
    scanf("%d", &n);

    printf("O resultado e igual a: %d", produto(n));
    return 0;
}

int produto(int n)
{
    if (n == 1)
    {
        return n;
    }
    else
    {
        int res;
        res = n * produto(n-1);
        return res;
    }
}
