#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int *v, int tam);
void quicksort(int *v, int esq, int dir);
int particiona(int *v, int esq, int dir);
void geraVetor(int *v, int tam);
int cmpfunc(const void *a, const void *b);
void trocar(int *v, int i, int j);

int main()
{
    clock_t start_t, end_t;
    double total_t_stdlib, total_t;
    int tam;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);
    int values[tam];

    srand(time(NULL));

    geraVetor(values, tam);
    start_t = clock();
    qsort(values, tam, sizeof(int), cmpfunc);
    end_t = clock();
    total_t_stdlib = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    start_t = 0;
    end_t = 0;

    geraVetor(values, tam);
    start_t = clock();
    quicksort(values, 0, tam - 1);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Execution time qSort stdlib: %f\n", total_t_stdlib);
    printf("Execution time manual qSort: %f\n", total_t);
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void imprimeVetor(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

void geraVetor(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(v + i) = rand() % 100;
    }
}

void trocar(int *v, int i, int j)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particiona(int *v, int esq, int dir)
{

    int i, j, x;
    i = esq;
    j = dir;
    x = v[esq];

    while (i < j)
    {
        while ((v[i] <= x) && (i < dir))
            i++;

        while ((v[j] > x))
            j--;

        if (i < j)
        {
            trocar(v, i, j);
        }
    }

    trocar(v, esq, j);

    return j;
}

void quicksort(int *v, int esq, int dir)
{
    int pivo;

    if (esq >= dir)
        return;

    pivo = particiona(v, esq, dir);
    quicksort(v, esq, pivo - 1);
    quicksort(v, pivo + 1, dir);
}