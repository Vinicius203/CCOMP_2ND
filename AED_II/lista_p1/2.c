#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(float *salario, int tam);
void trocar(float *salario, int i, int j);
void insereVetor(float *salario, int tam);
void imprimeVetor(float *salario, int tam);

int main()
{
    int tam;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);

    float salario[tam];

    srand(time(NULL));

    insereVetor(salario, tam);
    imprimeVetor(salario, tam);
    bubbleSort(salario, tam);
    imprimeVetor(salario, tam);
}

void insereVetor(float *salario, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(salario + i) = rand() % 3500;
    }
}

void imprimeVetor(float *salario, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%.2f\t", *(salario + i));
    }
    printf("\n");
}

void trocar(float *salario, int i, int j)
{
    float aux;

    aux = salario[i];
    salario[i] = salario[j];
    salario[j] = aux;
}

void bubbleSort(float *salario, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - 1 - i; j++)
        {
            if (salario[j] < salario[j + 1])
                trocar(salario, j, j + 1);
        }
    }
}
