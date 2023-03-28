#include<stdio.h>
#include<string.h>

/* Outro formato de declaracao:

struct Pessoa{
    char nome[50];
    int idade;
};
*/
typedef struct{
    char nome[50];
    int idade;

}Pessoa;

//funcoes para vetores
void imprimeVetor(int v[], int tam);
void preencheVetor(int v[], int tam);
void preencheVetorPonteiro(int *p, int tam);

//funcoes para matrizes
void imprimeMatriz(int linhas, int colunas, int m[linhas][colunas]);
void preencheMatriz(int linhas, int colunas, int m[linhas][colunas]);
void preencheMatrizPonteiro(int linhas, int colunas, int *p);

//funcoes para structs
void imprimePessoas(Pessoa pessoas[], int tam);
void inserePessoa(Pessoa *pessoa, char nome[], int idade);
Pessoa maisVelho(Pessoa *pessoas, int tam);

int main(){

    printf("\n\nVetores \n\n");

    /*
        vetores sao na verdade ponteiros, que apontam para a primeira posicao de um bloco
        continuo de memorias alocadas para o seu tipo. O compilador interpreta a variavel
        como um ponteiro do tipo declarado, e a quantia de memoria alocada na stack eh
        igual a tipo(vetor) * tamanho(vetor).

        Por exemplo:
        float v[50] -> *float apontando para bloco de memoria com:
                                    4 bytes * 50 = 200 bytes
    */
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    imprimeVetor(v, 10);
    preencheVetor(v, 10);
    imprimeVetor(v, 10);
    preencheVetorPonteiro(&v[0], 10); // endereco da primeira posicao
    // alternativamente, pode chamar: preencheVetorPonteiro(v, 10);
    imprimeVetor(v, 10);


    printf("\n\nMatrizes \n\n");

    /*
        Matrizes estaticas são na verdade alocadas em um bloco de memoria continuo na stack,
        e sao vistas como vetores consecutivos. Uma matriz eh enxergada como um vetor de
        vetores para o compilador.

        Exemplo:
        m[5][10] -> *float[5] apontando para um bloco de memoria continuo com:
                                4 bytes * 5 * 10 = 200bytes
    */

    int m[3][3] = {1, 2, 3,
                   4, 5, 6,
                   7, 8, 9};
    imprimeMatriz(3, 3, m);
    preencheMatriz(3, 3, m);
    imprimeMatriz(3, 3, m);
    preencheMatrizPonteiro(3, 3, m[0]); //m[0] referencia o endereco da primeira posicao do primeiro vetor
    // preencheMatrizPonteiro(3, 3, m); ate funciona, mas eh conversao errada de ponteiro e gera warning
    // preencheMatrizPonteiro(3, 3, m[1]); nesse caso, o ponteiro receberia o endereco a primeira posicao do segundo vetor
    imprimeMatriz(3, 3, m);


    printf("\n\nRegistros \n\n");

    /*
        Registros ocupam na memoria o total de memoria requirido por suas variaveis.
        Pessoa ocupa:
            char[50] -> 50bytes
            int -> 4bytes,
            total = 54bytes

        O acesso a registros se vai através de ponto ('.'). Com ponteiros, a notacao muda
        para uma flecha ('->').
        Exemplo:
        Pessoa a, *p;
        a.idade = 32;
        p = &a;
        p->idade = 47;

        Um vetor de Pessoa funciona igual a um vetor de tipos basicos, e ocupa um bloco
        continuo de memoria igual a tam(vetor) * tam(registro).
        Exemplo:
        Pessoa v[50] -> *Pessoa apontando para bloco de memoria com:
                                    54 bytes * 50 = 2700 bytes

    */
    Pessoa pessoas[10];

    inserePessoa(&pessoas[0], "Clark Kent", 20); //endereço de memoria da posicao 0 do vetor
    inserePessoa(&pessoas[1], "Daenerys Targaryen", 18); //endereço de memoria da posicao 1 do vetor
    inserePessoa(&pessoas[2], "Diana Prince", 110);
    inserePessoa(&pessoas[3], "Homer Simpsons", 44);
    inserePessoa(&pessoas[4], "Jessica Jones", 35);
    inserePessoa(&pessoas[5], "Frodo Baggins", 50);
    inserePessoa(&pessoas[6], "Peter Parker", 29);
    inserePessoa(&pessoas[7], "Leia Skywalker", 25);
    inserePessoa(&pessoas[8], "Phoebe Buffay", 20);
    inserePessoa(&pessoas[9], "Roland Deschain", 60);
    imprimePessoas(pessoas, 10);

    Pessoa velho = maisVelho(pessoas, 10);
    printf("Mais velho:\n");
    printf("Nome: %s\n", velho.nome);
    printf("Idade: %d\n", velho.idade);


    return 0;
}

/*
    Passando v[] e tam, minha funcao consegue manipular qualquer tamanho de vetor
*/
void imprimeVetor(int v[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d\t", v[i]);
    }
    printf("\n\n");
}

void preencheVetor(int v[], int tam){
    for(int i = 0; i < tam; i++){
        v[i] = 2;
    }
}
/*
    Vetores sao ponteiros para blocos de memoria, entao pode-se utilizar notacao de
    ponteiros no lugar de notacao de vetores. As duas sao equivalentes
*/
void preencheVetorPonteiro(int *p, int tam){
    for(int i = 0; i < tam; i++){
        *(p+i) = i * 2; //*(p+i) equivale a p[i], as duas notacoes sao validas
    }
}

/*
    Matrizes sao um caso especial de vetores, e a funcao necessita saber pelo menos
    quantas linhas (quantos vetores contiguos) a estrutura tem.
    Nesse caso, optei por passar numero de linhas e colunas primeiro, e a matriz ja
    com seu tamanho definido pelas variaveis.
*/
void imprimeMatriz(int linhas, int colunas, int m[linhas][colunas]){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void preencheMatriz(int linhas, int colunas, int m[linhas][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            m[i][j] = 15;
        }
        printf("\n");
    }
}

/*
    Eu posso acessar uma matriz atraves de ponteiros. Porem, um ponteiro
    nao vai ter a informacao da quantidade de linhas (numero de vetores) que
    a matriz tem. Portanto, ao chamar a funcao, precisa-se dizer exatamente qual
    vetor o ponteiro esta recebendo (por isso, no main(), chamamos passando m[0].
*/
void preencheMatrizPonteiro(int linhas, int colunas, int *p){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            // como o ponteiro nao sabe a quantidade de linhas, eh ilegal chamar p[i][j]
            // o acesso deve ser realizado atraves de operacoes com ponteiros:
            *(p + i*colunas + j) = 30; //i*colunas me diz a posicao na memoria da linha corrente, j a posicao na coluna
        }
        printf("\n");
    }
}

/*
    Apesar de um vetor ser um ponteiro, ao aplicar a notacao pessoas[i], isso se refere ao
    conteudo daquela posicao no vetor, entao a notacao utilizada deve ser ponto.
    Ex: pessoas[2].nome;
*/
void imprimePessoas(Pessoa pessoas[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%s\n", pessoas[i].nome);
        printf("%d\n\n", pessoas[i].idade);
    }
    printf("\n\n");
}

/*
    Essa funcao realiza a insercao de uma pessoa a uma posicao de um vetor alocado em outro contexto
    da pilha. Como chamamos a funcao no main(), o ponteiro *pessoa aponta para o endereco de memoria
    de uma posicao de um vetor alocado na main().
    Como estamos apontando para um local da memoria, utiliza-se a notacao de flecha (->)
    Exemplo:
    pessoa->nome;
*/
void inserePessoa(Pessoa *pessoa, char nome[], int idade){
    pessoa->idade = idade;
    strcpy(pessoa->nome, nome);
    //copia de strings (vetores de char) devem ser feitas com strcpy(), da biblioteca string.h
}

/*
    Essa funcao aloca uma variavel Pessoa p nesse escopo, percorre o vetor de pessoas alocado no escopo
    que a chamou (nesse caso, a main()), e copia seus valores para a variavel p. No fim, ela retorna
    Pessoa p para o escopo anterior (a main()).
*/
Pessoa maisVelho(Pessoa *pessoas, int tam){
    Pessoa p;
    p.idade = 0;
    for(int i = 0; i < tam; i++){
        if(pessoas[i].idade > p.idade){
            strcpy(p.nome, pessoas[i].nome);
            p.idade = pessoas[i].idade;
        }
    }
    return p;
}









