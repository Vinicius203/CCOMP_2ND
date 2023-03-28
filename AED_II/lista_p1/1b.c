#include <stdio.h>

double somaRecursiva(int numerador, int denominador, int n1, int n2)
{
    if (denominador == n1 + 3)
    {
        return (double)numerador / denominador;
    }
    else if (denominador < n1 + 3)
    {
        return somaRecursiva(numerador + denominador + 1, denominador + 1, n1, n2);
    }
    else if (denominador <= n2 + 1)
    {
        return (double)numerador / denominador + somaRecursiva(numerador + denominador + 1, denominador + 1, n1, n2);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n1, n2;
    printf("Digite dois números inteiros N1 e N2: ");
    scanf("%d %d", &n1, &n2);
    double resultado = somaRecursiva(2, 4, n1, n2);
    printf("Resultado: %.2f", resultado);
    return 0;
}
