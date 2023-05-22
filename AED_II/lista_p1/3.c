#include <stdio.h>
#include <stdlib.h>
#include <time.h>
;
void trocar(float *salario, int i, int j);
void insereVetor(float *salario, int tam);
void imprimeVetor(float *salario, int tam);
void quickSort(float *salario, int esq, int dir);
int particiona(float *salario, int esq, int dir);

int main()
{
    int tam, pivo;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);

    float salario[tam];

    srand(time(NULL));

    insereVetor(salario, tam);
    imprimeVetor(salario, tam);

    quickSort(salario, 0, tam - 1);

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

int particiona(float *salario, int esq, int dir)
{
    int r = rand() % (dir - esq + 1) + esq;
    trocar(salario, r, dir);
    int i = esq, j = dir - 1, x = salario[dir];

    while (i <= j)
    {
        while (i <= j && salario[i] < x)
            i++;
        while (i <= j && salario[j] >= x)
            j--;
        if (i < j)
            trocar(salario, i, j);
    }
    trocar(salario, i, dir);
    return i;
}

void quickSort(float *salario, int esq, int dir)
{
    if (esq >= dir)
        return;
    int pivo = particiona(salario, esq, dir);
    quickSort(salario, esq, pivo - 1);
    quickSort(salario, pivo + 1, dir);
}