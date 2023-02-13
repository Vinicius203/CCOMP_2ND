#include <stdio.h>

int valores(int n);

int main()
{
    int n;

    printf("Entre com um numero inteiro e positivo: ");
    scanf("%d", &n);

    valores(n);

    return 0;
}

int valores(int n)
{
    if (n < 0) {
        return n;
    }

    printf("%d\n", n);
    n = n + valores(n-1);
}
