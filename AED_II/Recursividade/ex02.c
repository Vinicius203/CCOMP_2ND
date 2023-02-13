#include <stdio.h>

int valores(int n);

int main()
{
    int n;

    printf("Entre com um numero inteiro e positivo: ");
    scanf("%d", &n);

    printf("O resultado e: %d", valores(n));

    return 0;
}

int valores(int n)
{
    int res;

    if (n == 0) {
        return n;
    }

    res = n + valores(n-1);
    return res;
}
