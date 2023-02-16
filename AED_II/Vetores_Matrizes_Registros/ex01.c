#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int *v, int tam);
void preencheVetor(int *v, int tam);
void retornaMaiorMenor(int *v, int tam, int *menor, int *maior);

int main()
{
    int tam, maior = 0, menor = 1000;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &tam);

    int v[tam];

    srand(time(NULL));

    preencheVetor(v, tam);
    imprimeVetor(v, tam);
    retornaMaiorMenor(v, tam, &menor, &maior);
    printf("O maior num e: %d\nO menor num e: %d\n\n", maior, menor);
    return 0;
}

void preencheVetor(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(v + i) = rand() % 100;
    }
}

void imprimeVetor(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d\t", *(v + i));
    }
    printf("\n");
}

void retornaMaiorMenor(int *v, int tam, int *menor, int *maior)
{
    for (int i = 0; i < tam; i++)
    {
        if (*(v + i) < *menor)
        {
            *menor = *(v + i);
        }
        if (*(v + i) > *maior)
        {
            *maior = *(v + i);
        }
    }
}
