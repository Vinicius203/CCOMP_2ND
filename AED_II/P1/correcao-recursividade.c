#include<stdio.h>

int imprimeInteiros(int n);
int somatorio(int n);
int mdc(int x, int y);

int main(){

     int n;
     scanf("%d", &n);
     imprimeInteiros(n);
     printf("\nSoma: %d\n", somatorio(n));

     int x, y;
     scanf("%d %d", &x, &y);
     printf("MDC: %d", mdc(x, y));

}

int imprimeInteiros(int n){
    if(n >= 0)
        printf("%d ", imprimeInteiros(n-1));
    return n + 1;
}

int somatorio(int n){
    if(n == 0)
        return n;

    return n + somatorio(n-1);

}

int mdc(int x, int y){
    if((y <= x) && (x % y == 0))
        return y;
    if(x < y)
        return mdc(y, x);

    return mdc(y, x % y);
}
