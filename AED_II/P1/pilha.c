#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Struct questao
typedef struct
{
    int pergunta;
    int respostas;
} Questao;
// Struct No
typedef struct no
{
    Questao d;
    int dado;
    struct no *prox; // ponteiro para a proxima struct no
} No;
// struct Pilha
// ela sempre aponta para o no do TOPO da Pilha
typedef struct
{
    No *topo;
    int tamPilha;
} Pilha;
// funcoes de manipulacao
void insereQuestao(Questao *q, int pergunta, int respostas);
void cria(Pilha *s);
int empilha(Pilha *s, int dado, Questao *d, int i);
int desempilha(Pilha *s, int *dado);
// funcoes de checagem / visualizacao
int estaVazia(Pilha s);
int getTopo(Pilha s);
int getTamanho(Pilha s);
void mostra(Pilha s);
int main()
{
    Pilha s;
    Questao d[3];
    int dado, sucesso;

    insereQuestao(&d[0], 1, 5);
    insereQuestao(&d[1], 2, 3);
    insereQuestao(&d[2], 3, 1);

    srand(time(NULL));
    cria(&s);
    if (estaVazia(s))
        printf("Pilha esta vazia!\n\n");
    else
        printf("Pilha nao esta vazia!\n\n");
    // Empilhando
    printf("Gerando e empilhando dados:\n");
    for (int i = 0; i < 3; i++)
    {
        dado = rand() % 1000;
        printf("Empilhando %d...\n", dado);
        sucesso = empilha(&s, dado, d, i);
        if (!sucesso)
        {
            printf("Problemas ao empilhar o dado %d", dado);
        }
    }
    // Visualizando
    if (!estaVazia(s))
    {
        printf("\nTamanho da pilha: %d\nDado no topo: %d\n\n", getTamanho(s),
               getTopo(s));
        printf("Exibindo todos os dados da pilha...\n\n");
        mostra(s);
    }
    else
        printf("Pilha esta vazia!\n\n");
    // Desempilhando
    /*
    printf("\nDesempilhando dados:\n\n");
    while (!estaVazia(s))
    {
        sucesso = desempilha(&s, &dado);
        if (sucesso)
            printf("Dado desempilhado: %d\n", dado);
        else
            printf("Pilha vazia...\n");
    }
    */
}
/*
A funcao 'cria' apenas inicializa a Pilha.
Ela seta o topo apontando para NULL e o tamanho como 0.
*/
void cria(Pilha *s)
{
    s->topo = NULL;
    s->tamPilha = 0;
}
/*
A funcao 'empilha' adiciona um no na Pilha. Para isso, realiza-se os seguintes
passos:
- cria um novo no na HEAP
- atribui a ele o dado a ser empilhado
- o novo no aponta para o antigo topo
- o topo eh atualizado apontando para o novo no
A funcao retorna 1 se o empilhamento foi bem sucedido, ou 0 se n o.�
*/
int empilha(Pilha *s, int dado, Questao *d, int i)
{
    No *aux;
    aux = (No *)malloc(sizeof(No));
    if (aux == NULL)
        return 0;
    aux->d = *(d + i);
    aux->prox = s->topo;
    s->topo = aux;
    s->tamPilha++;
    return 1;
}
/*
A funcao 'desempilha' remove um no da Pilha. Para isso, realiza-se os seguintes
passos:
- topo aponta para o proximo no na pilha
- o antigo topo eh liberado
A funcao retorna 1 se o desempilhamento foi bem sucedido, ou 0 se n o.�
*/
int desempilha(Pilha *s, int *dado)
{
    No *aux = s->topo;
    if (aux == NULL)
        return 0;
    *dado = aux->dado;
    s->topo = aux->prox;
    s->tamPilha--;
    free(aux);
    return 1;
}
/*
Verifica se a pilha esta vazia.
A pilha esta vazia se seu topo aponta para NULL.
*/
int estaVazia(Pilha s)
{
    if (s.topo == NULL)
        return 1;
    return 0;
}
/*
Funcao para visualizar o dado do topo.
*/
int getTopo(Pilha s)
{
    return s.topo->dado;
}
/*
Funcao para visualizar o tamanho da pilha.
*/
int getTamanho(Pilha s)
{
    return s.tamPilha;
}
/*
Funcao para visualizar os dados da pilha.
Se ela estiver vazia, aviso o usuario.
Caso contrario, vou navegando nela atraves dos ponteiros de prox e exibindo os
dados.
*/
void mostra(Pilha s)
{
    No *aux = s.topo;
    if (aux == NULL)
        printf("Pilha vazia...\n");
    else
    {
        while (aux != NULL)
        {
            printf("Dado armazenado: %d\n", aux->d);
            aux = aux->prox;
        }
    }
}

void insereQuestao(Questao *q, int pergunta, int respostas)
{
    q->pergunta = pergunta;
    q->respostas = respostas;
}
