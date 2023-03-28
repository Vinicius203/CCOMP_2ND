#include<stdio.h>

int fatorial(int n);
int fib(int n);

int main(){

    //Calculando o fatorial:
    int n;

    printf("Digite um numero para saber o fatorial");
    scanf("%d", &n);
    printf("Resultado fatorial eh %d", fatorial(n));

    //-------------------------------------------------------------

    //Calculando fibonacci
    int f;
    scanf("%d", &f);
    printf("Resultado fibonacci eh %d", fib(f));


    return 0;
}
/*
    Exemplo:
    5! = 5 * 4 * 3 * 2 * 1
    5! = 5 * 4!
             4! = 4 * 3 * 2 * 1
             4! = 4 * 3!
                      3! = 3 * 2 * 1
                      3! = 3 * 2!
                               2! = 2 * 1
                               2! = 2 * 1!
                                        1! = 1
*/
int fatorial(int n){
    int res;

    if(n == 1)
        return 1;

    res = n * fatorial(n-1);
    return res;
}

/*
    Exemplo:

    fib(1) = 1
    fib(2) = 1
    fib(3) = 1 + 1 = 2
    fib(4) = 2 + 1 = 3
    fib(5) = 3 + 2 = 5
    fib(6) = 5 + 3 = 8
    ...
    fib(n) = fib(n-1) + fib(n-2)

*/
int fib(int n){
    if((n == 1) || (n == 2))
        return 1;

    return fib(n-1) + fib(n-2);

}
