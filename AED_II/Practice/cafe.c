#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_resultado, aux = 0, x = 0;
    double saca_min, saca_max, valor_final, valor_desejado;

    scanf("%lf %lf", &saca_min, &saca_max);
    scanf("%lf", &valor_final);

    qtd_resultado = valor_final / saca_max;

    printf("%d", qtd_resultado);

    while (x == 0)
    {

        for (valor_desejado = saca_min; valor_desejado <= saca_max; valor_desejado++)
        {
            if (valor_desejado * qtd_resultado == valor_final)
            {
                aux = 1;
                break;
            }
        }

        if (aux == 1)
        {
            x = 1;
        }
    }

    printf("%d %.2f", qtd_resultado, valor_desejado);

    return 0;
}