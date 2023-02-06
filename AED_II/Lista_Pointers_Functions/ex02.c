#include <stdio.h>

void converte(int idade, int *meses, int *dias);

int main()
{
    int idade, meses, dias;

    printf("Entre com sua idade em anos: ");
    scanf("%d", &idade);

    converte(idade, &meses, &dias);

    printf("A idade de %d anos e igual: %d meses ou %d dias.\n", idade, meses, dias);

    return 0;
}

void converte(int idade, int *meses, int *dias)
{
    *meses = idade * 12;
    *dias = idade * 365;
}