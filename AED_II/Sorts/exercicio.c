#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    double salario;
} Empregado;

// Registro
void imprimePessoa(Empregado empregado[], int tam);
void inserePessoa(Empregado *empregado, int id, char nome[], double salario);

// Sorts
void bubblesort(Empregado empregado[], int tam);
int particiona(Empregado empregado[], int esq, int dir);
void quicksort(Empregado empregado[], int esq, int dir);

// Troca
void trocar(Empregado empregado[], int i, int j);

// Pesquisa
int pesquisaSequencial(Empregado empregado[], int tam, int dado);
int pesquisaBinaria(Empregado empregado[], int dado, int esq, int dir);

int main()
{
    int tam = 10, dado, pesquisa;

    Empregado empregado[10];

    inserePessoa(&empregado[0], 1, "Frodo Baggins", 2300.00);
    inserePessoa(&empregado[1], 2, "Bilbo Baggins", 1600.00);
    inserePessoa(&empregado[2], 3, "Samwise Gamgee", 3730.25);
    inserePessoa(&empregado[3], 4, "Gandalf", 0.00);
    inserePessoa(&empregado[4], 5, "Boromir", 9000.00);
    inserePessoa(&empregado[5], 6, "Aragorn", 1320.00);
    inserePessoa(&empregado[6], 7, "Meriadoc Brandybuck", 600.00);
    inserePessoa(&empregado[7], 8, "Peregrin Took", 735.00);
    inserePessoa(&empregado[8], 9, "Legolas Greenleaf", 6200.00);
    inserePessoa(&empregado[9], 10, "Fingolfin", 932.45);

    imprimePessoa(empregado, tam);
    bubblesort(empregado, tam);
    printf("----------------------------------------------\n\n");
    imprimePessoa(empregado, tam);
    quicksort(empregado, 0, tam - 1);
    printf("----------------------------------------------\n\n");
    imprimePessoa(empregado, tam);
    printf("----------------------------------------------\n\n");
    printf("Entre com o ID que deseja procurar: ");
    scanf("%d", &dado);

    printf("\nPesquisa Sequencial:\n");
    pesquisa = pesquisaSequencial(empregado, tam, dado);
    if (pesquisa == -1)
        printf("Esse ID não existe!");
    else
        printf("A pesquisa encontrou os seguintes dados:\nID: %d\nNome: %s\nSalario: %.2f\n", empregado[pesquisa].id, empregado[pesquisa].nome, empregado[pesquisa].salario);

    printf("\nPesquisa Binaria:\n");
    pesquisa = pesquisaBinaria(empregado, dado, 0, tam - 1);
    if (pesquisa == -1)
        printf("Nao foi possivel encontrar o dado solicitado...\n");
    else
        printf("A pesquisa encontrou os seguintes dados:\nID: %d\nNome: %s\nSalario: %.2f\n", empregado[pesquisa].id, empregado[pesquisa].nome, empregado[pesquisa].salario);
    return 0;
}

void inserePessoa(Empregado *empregado, int id, char nome[], double salario)
{
    empregado->id = id;
    strcpy(empregado->nome, nome);
    empregado->salario = salario;
}

void imprimePessoa(Empregado empregado[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", empregado[i].id);
        printf("%s\n", empregado[i].nome);
        printf("%.2lf\n", empregado[i].salario);
        printf("\n");
    }
    printf("\n");
}

void trocar(Empregado empregado[], int i, int j)
{
    Empregado aux;

    aux = empregado[i];
    empregado[i] = empregado[j];
    empregado[j] = aux;
}

void bubblesort(Empregado empregado[], int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - 1 - i; j++)
        {
            if (strcmp(empregado[j].nome, empregado[j + 1].nome) > 0)
                trocar(empregado, j, j + 1);
        }
    }
}

int particiona(Empregado empregado[], int esq, int dir)
{
    int i = esq, j = dir, x = empregado[esq].id;

    while (i < j)
    {
        while ((empregado[i].id <= x) && (i < dir))
            i++;
        while (empregado[j].id > x)
            j--;
        if (i < j)
            trocar(empregado, i, j);
    }
    trocar(empregado, esq, j);
    return j;
}

void quicksort(Empregado empregado[], int esq, int dir)
{
    if (esq >= dir)
        return;
    int pivo = particiona(empregado, esq, dir);
    quicksort(empregado, esq, pivo - 1);
    quicksort(empregado, pivo + 1, dir);
}

int pesquisaSequencial(Empregado empregado[], int tam, int dado)
{
    for (int i = 0; i < tam; i++)
    {
        if (empregado[i].id == dado)
            return i;
    }
    return -1;
}

int pesquisaBinaria(Empregado empregado[], int dado, int esq, int dir)
{
    int meio = (esq + dir) / 2; // posicao do meio

    if (empregado[meio].id == dado) // se for o elemento, retorna meio
        return meio;
    if (esq >= dir) // se o vetor corrente for unitario ou esq > dir, pesquisa nao encontrou nada, retorna -1.
        return -1;
    if (dado > empregado[meio].id) // se o elemento procurado eh maior que v[meio], procura no lado direito do vetor
        return pesquisaBinaria(empregado, dado, meio + 1, dir);
    else // se for menor, procura no lado esquerdo
        return pesquisaBinaria(empregado, dado, esq, meio - 1);
}
