#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    char raca[50];
    int idade;
} Cao;

// Registro
void imprimeCao(Cao cao[], int tam);
void insereCao(Cao *cao, int id, char nome[], char raca[], int idade);

// Pesquisa
int pesquisaBinaria(Cao cao[], int dado, int esq, int dir);

int main()
{
    int tam = 10, dado, pesquisa;

    Cao cao[10];

    insereCao(&cao[0], 1, "Rex", "Vira Lata", 3);
    insereCao(&cao[1], 2, "Toby", "Poodle", 6);
    insereCao(&cao[2], 3, "Aslan", "Pitbull", 10);
    insereCao(&cao[3], 4, "Zoro", "Pastor Alemão", 4);
    insereCao(&cao[4], 5, "Bilu", "Shiba Inu", 8);
    insereCao(&cao[5], 6, "Caramelo", "Caramelus", 1);
    insereCao(&cao[6], 7, "Pichula", "Vira Lata", 12);
    insereCao(&cao[7], 8, "Laika", "Terrier", 2);
    insereCao(&cao[8], 9, "Malu", "Pug", 15);
    insereCao(&cao[9], 10, "Arcanine", "Vira Lata", 5);

    imprimeCao(cao, tam);

    printf("Entre com o ID que deseja procurar: ");
    scanf("%d", &dado);

    printf("\nPesquisa Binaria:\n");
    pesquisa = pesquisaBinaria(cao, dado, 0, tam - 1);
    if (pesquisa == -1)
        printf("Nao foi possivel encontrar o dado solicitado...\n");
    else
        printf("A pesquisa encontrou os seguintes dados:\nID: %d\nNome: %s\nRaca: %s\nIdade: %d\n", cao[pesquisa].id, cao[pesquisa].nome, cao[pesquisa].raca, cao[pesquisa].idade);
    return 0;
}

void insereCao(Cao *cao, int id, char nome[], char raca[], int idade)
{
    cao->id = id;
    strcpy(cao->nome, nome);
    strcpy(cao->raca, raca);
    cao->idade = idade;
}

void imprimeCao(Cao cao[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", cao[i].id);
        printf("%s\n", cao[i].nome);
        printf("%s\n", cao[i].raca);
        printf("%d\n", cao[i].idade);
        printf("\n");
    }
    printf("\n");
}

int pesquisaBinaria(Cao cao[], int dado, int esq, int dir)
{
    int meio = (esq + dir) / 2; // posicao do meio

    if (cao[meio].id == dado) // se for o elemento, retorna meio
        return meio;
    if (esq >= dir) // se o vetor corrente for unitario ou esq > dir, pesquisa nao encontrou nada, retorna -1.
        return -1;
    if (dado > cao[meio].id) // se o elemento procurado eh maior que v[meio], procura no lado direito do vetor
        return pesquisaBinaria(cao, dado, meio + 1, dir);
    else // se for menor, procura no lado esquerdo
        return pesquisaBinaria(cao, dado, esq, meio - 1);
}