#include <stdio.h>

int mdc(int x, int y);

int main()
{
    int x, y;

    printf("Entre com dois numeros inteiros e positivos: ");
    scanf("%d %d", &x, &y);

    printf("O MDC entre os numeros e igual a: %d", mdc(x, y));

    return 0;
}

int mdc(int x, int y)
{
    if ((y <= x) && (x % y == 0))
    {
        return y;
    }
    else if (x < y)
    {
        return mdc(y, x);
    }
    else
    {
        return mdc(y, x % y);
    }
}
