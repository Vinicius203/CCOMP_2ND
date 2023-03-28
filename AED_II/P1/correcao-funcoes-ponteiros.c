#include<stdio.h>

void calculaRestoDivisao(int a, int b, int *div, int *resto);
int calculaMesesDias(int idade, int *dias);
void ordenaValores(int *a, int *b, int *c);
void troca(int *p1, int *p2);

int main(){

    //Ex 1:
    int a, b, div, resto;

    printf("Digite dois numeros: \n");
    scanf("%d %d", &a, &b);
    calculaRestoDivisao(a, b, &div, &resto);
    printf("Resultado divisao %d com resto %d\n", div, resto);

    //----------------------------------------------------

    //Ex 2:
    int dias, meses, anos;

    printf("Digite sua idade:\n");
    scanf("%d", &anos);
    meses = calculaMesesDias(anos, &dias);
    printf("Dias = %d, meses = %d\n", dias, meses);

     //----------------------------------------------------

     //Ex 3:
     int x, y, z;

     printf("Digite tres numeros a serem ordenados:\n");
     scanf("%d %d %d", &x, &y, &z);
     ordenaValores(&x, &y, &z);
     printf("%d %d %d", x, y, z);

      return 0;
}

void calculaRestoDivisao(int a, int b, int *div, int *resto){
    *div = a / b;
    *resto = a % b;

}

int calculaMesesDias(int idade, int *dias){
    *dias = idade * 365;
    return idade * 12;
}

void ordenaValores(int *a, int *b, int *c){
    if(*a > *b){
        troca(a, b);
    }
    if(*a > *c){
        troca(a, c);
    }
    if (*b > *c){
        troca(b, c);
    }
}

void troca(int *p1, int *p2){
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;

}
