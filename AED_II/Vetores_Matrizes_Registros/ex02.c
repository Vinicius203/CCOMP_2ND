#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    float salario;
    int numFilhos;
} Pessoa;

void registraPessoasAleatorias(Pessoa *p, int tam);
void imprimePessoas(Pessoa *p, int tam);
void mediaSalario(Pessoa *pessoas, int tam, float *mediaSal);
void mediaFilho(Pessoa *pessoas, int tam, int *mediaFilhos);
void maiorSalario(Pessoa *pessoas, int tam, float *maiorSal);
void percentualSalario(Pessoa *pessoas, int tam, float *percentual, float salBase);
void senso(Pessoa *pessoas, int tam, float *mediaSal, int *mediaFilhos, float
*maiorSal, float *percentual);

int main () {

    int tamSenso, mediaFilhos = 0;
    float mediaSal = 0, maiorSal = 0, percentual = 0;
    printf("Digite quantas pessoas irao participar do senso: ");
    scanf("%d", &tamSenso);

    Pessoa pessoas[tamSenso];

    srand(time(NULL));

    registraPessoasAleatorias(pessoas, tamSenso);
    imprimePessoas(pessoas, tamSenso);
    senso(pessoas, tamSenso, &mediaSal, &mediaFilhos, &maiorSal, &percentual);

    printf("Dados do senso:\n");
    printf("Salario medio: %.2f\n", mediaSal);
    printf("Quantidade media de filhos (arredondado): %d\n", mediaFilhos);
    printf("Maior salario da populacao: %.2f\n", maiorSal);
    printf("Percentual de pessoas que ganham menos de RS 350,00: %.2f%%\n\n", percentual);

    return 0;
}

void registraPessoasAleatorias(Pessoa *p, int tam) {
    for (int i = 0; i < tam; i ++) {
        p[i].salario = rand() % 700;
        p[i].numFilhos = rand() % 5;
    }
}

void imprimePessoas(Pessoa *p, int tam) {
    for (int i = 0; i < tam; i ++) {
        printf("Salario: %.2f\tNumero de Filhos: %d\n", p[i].salario, p[i].numFilhos);
    }
}

void mediaSalario(Pessoa *pessoas, int tam, float *mediaSal) {
    for (int i = 0; i < tam; i ++) {
        *mediaSal += pessoas[i].salario;
    }
    *mediaSal /= tam;
}

void mediaFilho(Pessoa *pessoas, int tam, int *mediaFilhos) {
    for (int i = 0; i < tam; i ++) {
        *mediaFilhos += pessoas[i].numFilhos;
    }
    *mediaFilhos /= tam;
}

void senso(Pessoa *pessoas, int tam, float *mediaSal, int *mediaFilhos, float *maiorSal, float *percentual) {
    mediaSalario(pessoas, tam, mediaSal);
    mediaFilho(pessoas, tam, mediaFilhos);
    maiorSalario(pessoas, tam, maiorSal);
    percentualSalario(pessoas, tam, percentual, 350);
}

void maiorSalario(Pessoa *pessoas, int tam, float *maiorSal) {
    for(int i = 0; i < tam; i ++) {
        if(pessoas[i].salario > *maiorSal) {
            *maiorSal = pessoas[i].salario;
        }
    }
}

void percentualSalario(Pessoa *pessoas, int tam, float *percentual, float salBase) {
    int aux = 0;
    for(int i = 0; i < tam; i ++) {
        if(pessoas[i].salario <= salBase) {
            aux ++;
        }
    }
    *percentual = (aux * 100) / tam;
}




