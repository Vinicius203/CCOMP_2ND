#include <stdio.h>

void ordenaVetor(int v[], int tam);

int main()
{
    int v[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    ordenaVetor(v, 10);
    return 0;
}

void ordenaVetor(int v[], int tam)
{
    int maior, menor;
    maior = menor = v[0];
    for(int i = 0; i < tam; i ++) {
        if(v[i] > maior) {
            maior = v[i];
        }
        if(v[i] < menor) {
            menor = v[i];
        }
    }
    printf("O menor valor e: %d\n", menor);
    printf("O maior valor e: %d\n", maior);
}