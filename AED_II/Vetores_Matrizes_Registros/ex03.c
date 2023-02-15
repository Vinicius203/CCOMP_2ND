#include <stdio.h>

void imprimeMatriz(int linhas, int colunas, int m[linhas][colunas]);
void preencheMatrizPonteiro(int linhas, int colunas, int *p);

int main()
{
    int linhas, colunas;

    printf("Entre com o tamanho da matriz quadrada (UM VALOR APENAS): ");
    scanf("%d", &linhas);

    colunas = linhas;
    int m[linhas][colunas];

    preencheMatrizPonteiro(linhas, colunas, m[0]);
    imprimeMatriz(linhas, colunas, m);

    return 0;
}

void imprimeMatriz(int linhas, int colunas, int m[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void preencheMatrizPonteiro(int linhas, int colunas, int *p)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (i == j)
            {
                *(p + i * linhas + j) = 1;
            }
            else
            {
                *(p + i * linhas + j) = 0;
            }
        }
    }
}