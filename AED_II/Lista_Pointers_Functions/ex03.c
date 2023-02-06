#include <stdio.h>

void ordem(float a, float b, float c, float *maior, float *medio, float *menor);

int main()
{
    float a, b, c, maior, medio, menor;
    printf("Entre com tres numeros: ");
    scanf("%f %f %f", &a, &b, &c);

    ordem(a, b, c, &maior, &medio, &menor);

    printf("O maior numero e: %.2f\n", maior);
    printf("O numero do meio e: %.2f\n", medio);
    printf("O menor numero e: %.2f\n", menor);
    return 0;
}

void ordem(float a, float b, float c, float *maior, float *medio, float *menor)
{
    *maior = a, *medio = b, *menor = c;

    if (a > b && a > c)
    {
        *maior = a;
        if (b > c)
        {
            *medio = b;
            *menor = c;
        }
        else
        {
            *medio = c;
            *menor = b;
        }
    }

    else if (b > a && b > c)
    {
        *maior = b;
        if (a > c)
        {
            *medio = a;
            *menor = c;
        }
        else
        {
            *medio = c;
            *menor = a;
        }
    }

    else if (c > a && c > b)
    {
        *maior = c;
        if (a > b)
        {
            *medio = a;
            *menor = b;
        }
        else
        {
            *medio = b;
            *menor = a;
        }
    }
}