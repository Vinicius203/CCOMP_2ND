#include <stdio.h>

void resto(int a, int b, int *d, int *r);

int main()
{
    int a, b, d, r;

    printf("Entre com duas variaveis inteiras: ");
    scanf("%d %d", &a, &b);

    resto(a, b, &d, &r);
    printf("A divisao inteira e igual a: %d\n", d);
    printf("O resto da divisao inteira e igual a: %d", r);

    return 0;
}

void resto(int a, int b, int *d, int *r)
{
    *d = a / b;
    *r = a % b;
}