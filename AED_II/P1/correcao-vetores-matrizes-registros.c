#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    float salario;
    int numFilhos;

} Pessoa;

void imprimeVetor(int *v, int tam);
void preencheVetor(int *v, int tam);
void retornaMaiorMenor(int *v, int tam, int *menor, int *maior);

void registraPessoasAleatorias(Pessoa *p, int tam);
void imprimePessoas(Pessoa *p, int tam);
void mediaSalario(Pessoa *pessoas, int tam, float *mediaSal);
void mediaFilho(Pessoa *pessoas, int tam, int *mediaFilhos);
void maiorSalario(Pessoa *pessoas, int tam, float *maiorSal);
void percentualSalario(Pessoa *pessoas, int tam, float *percentual, float salBase);
void senso(Pessoa *pessoas, int tam, float *mediaSal, int *mediaFilhos, float *maiorSal, float *percentual);

void preencheMatriz(int *pMatriz, int dimensoes);
void imprimeMatriz(int *pMatriz, int dimensoes);

int main(){

    //Ex 1:
    int tam, maior = 0, menor = 1000;
    printf("Digite o tamanho do seu vetor:\n");
    scanf("%d", &tam);
    int v[tam];

    srand(time(NULL));

    preencheVetor(v, tam);
    imprimeVetor(v, tam);
    retornaMaiorMenor(v, tam, &menor, &maior);
    printf("Maior: %d, menor: %d\n\n", maior, menor);

    //Ex 2:
    int tamSenso, mediaFilhos = 0;
    float mediaSal = 0, maiorSal = 0, percentual = 0;
    printf("Digite quantas pessoas irao participar do senso:");
    scanf("%d", &tamSenso);
    Pessoa pessoas[tamSenso];

    registraPessoasAleatorias(pessoas, tamSenso);
    imprimePessoas(pessoas, tamSenso);
    senso(pessoas, tamSenso, &mediaSal, &mediaFilhos, &maiorSal, &percentual);
    printf("Dados do senso:\n");
    printf("Salario medio: %.2f\n", mediaSal);
    printf("Quantidade media de filhos (arredondado): %d\n", mediaFilhos);
    printf("Maior salario da populacao: %.2f\n", maiorSal);
    printf("Percentual de pessoas que ganham menos de RS 350,00: %.2f%%\n\n", (percentual*100));

    //Ex 3:
    int dimensao;
    printf("Digite a dimensao de sua matriz quadrada\n");
    scanf("%d", &dimensao);
    int m[dimensao][dimensao];
    preencheMatriz(m[0], dimensao);
    imprimeMatriz(m[0], dimensao);


    return 0;
}

void imprimeVetor(int *v, int tam){

    for(int i = 0; i < tam; i++){
        printf("%d\t", v[i]);
    }
    printf("\n");

}
void preencheVetor(int *v, int tam){

    for(int i = 0; i < tam; i++){
        v[i] = rand() % 1000;
    }

}

void retornaMaiorMenor(int *v, int tam, int *menor, int *maior){
    for(int i = 0; i < tam; i++){
        if(v[i] > *maior)
            *maior = v[i];
        if(v[i] < *menor)
            *menor = v[i];
    }
}

void registraPessoasAleatorias(Pessoa *p, int tam){
    for(int i = 0; i < tam; i++){
        p[i].salario = rand() % 2000;
        p[i].numFilhos = rand() % 6;
    }
}

void imprimePessoas(Pessoa *p, int tam){

    for(int i = 0; i < tam; i++){
        printf("Salario: %f; NumFilhos: %d\n", p[i].salario, p[i].numFilhos);
    }
    printf("\n");

}

void mediaSalario(Pessoa *pessoas, int tam, float *mediaSal){
    for(int i = 0; i < tam; i++){
        *mediaSal += pessoas[i].salario;
    }
    *mediaSal /= tam;
}

void mediaFilho(Pessoa *pessoas, int tam, int *mediaFilhos){
    for(int i = 0; i < tam; i++){
        *mediaFilhos += pessoas[i].numFilhos;
    }
    *mediaFilhos = *mediaFilhos / tam;
}

void maiorSalario(Pessoa *pessoas, int tam, float *maiorSal){
    for(int i = 0; i < tam; i++){
        if(*maiorSal < pessoas[i].salario)
            *maiorSal = pessoas[i].salario;
    }
}

void percentualSalario(Pessoa *pessoas, int tam, float *percentual, float salBase){
    for(int i = 0; i < tam; i++){
        if(pessoas[i].salario < salBase)
            (*percentual)++;
    }
    (*percentual) = (float) *percentual / tam;
}

void senso(Pessoa *pessoas, int tam, float *mediaSal, int *mediaFilhos, float *maiorSal, float *percentual){
    mediaSalario(pessoas, tam, mediaSal);
    mediaFilho(pessoas, tam, mediaFilhos);
    maiorSalario(pessoas, tam, maiorSal);
    percentualSalario(pessoas, tam, percentual, 350);

}

void preencheMatriz(int *pMatriz, int dimensoes){
    for(int i = 0; i < dimensoes; i++){
        for(int j = 0; j < dimensoes; j++){
            if(i == j)
                *(pMatriz + i*dimensoes + j) = 1;
            else
                *(pMatriz + i*dimensoes + j) = 0;
        }
    }
}
void imprimeMatriz(int *pMatriz, int dimensoes){
    for(int i = 0; i < dimensoes; i++){
        for(int j = 0; j < dimensoes; j++){
            printf("%d\t", *(pMatriz + i*dimensoes + j));
        }
        printf("\n");
    }
    printf("\n");
}
