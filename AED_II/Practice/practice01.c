#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *v, int tam);
void preencheVetor(int *v, int tam);
void swap(int *v, int i, int j);
void bubbleSort(int *v, int tam);

int main()
{
    int tam;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);

    int v[tam];
    srand(time(NULL));

    preencheVetor(v, tam);
    printVetor(v, tam);

    bubbleSort(v, tam);
    printVetor(v, tam);

    return 0;
}

void preencheVetor(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(v + i) = rand() % 1000;
    }
}

void printVetor(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void swap(int *v, int i, int j)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void bubbleSort(int *v, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v, j, j+1);
            }
        }
    }
}