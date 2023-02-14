#include <stdio.h>

typedef struct
{
    double salario;
    int num_filhos;
} Prefeitura;

void inserePrefeitura(Prefeitura *registro, double salario, int num_filhos);
void imprimePrefeitura(Prefeitura registro[], int tam);
void mediaSalario(Prefeitura registro[], int tam);
void media_numFilhos(Prefeitura registro[], int tam);
Prefeitura maiorSalario(Prefeitura *registro, int tam);
void percentual(Prefeitura registro[], int tam);

int main()
{
    Prefeitura registro[6];
    inserePrefeitura(&registro[0], 1500.30, 2);
    inserePrefeitura(&registro[1], 2600.72, 3);
    inserePrefeitura(&registro[2], 3100, 0);
    inserePrefeitura(&registro[3], 10200, 4);
    inserePrefeitura(&registro[4], 350, 1);
    inserePrefeitura(&registro[5], 7453.29, 1);

    // imprimePrefeitura(registro, 6);
    mediaSalario(registro, 6);
    media_numFilhos(registro, 6);
    Prefeitura maior = maiorSalario(registro, 6);
    printf("O maior salario e de: %.2f\n", maior.salario);
    percentual(registro, 6);
}

void inserePrefeitura(Prefeitura *registro, double salario, int num_filhos)
{
    registro->salario = salario;
    registro->num_filhos = num_filhos;
}

void imprimePrefeitura(Prefeitura registro[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Salario: %.2f, Numero de Filhos: %d\n", registro[i].salario, registro[i].num_filhos);
    }
    printf("\n");
}

void media_numFilhos(Prefeitura registro[], int tam)
{
    double media = 0;

    for (int i = 0; i < tam; i++)
    {
        media += registro[i].num_filhos;
    }

    printf("A media de filhos e igual a: %.2f\n", media / 6);
}

void mediaSalario(Prefeitura registro[], int tam)
{
    double media = 0;

    for (int i = 0; i < tam; i++)
    {
        media += registro[i].salario;
    }

    printf("A media de salario e igual a: %.2f\n", media / 6);
}

Prefeitura maiorSalario(Prefeitura *registro, int tam)
{
    Prefeitura p;
    p.salario = 0;

    for (int i = 0; i < tam; i++)
    {
        if (registro[i].salario > p.salario)
        {
            p.salario = registro[i].salario;
        }
    }

    return p;
}

void percentual(Prefeitura registro[], int tam)
{
    double percentual = 0, aux;

    for (int i = 0; i < tam; i++)
    {
        if (registro[i].salario > 350.00)
        {
            percentual++;
        }
    }

    aux = (percentual * 100) / 6;

    printf("O percentual de pessoas com salario ate R$350,00 e: %.2f%%\n", aux);
}