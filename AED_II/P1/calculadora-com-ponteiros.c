#include <stdio.h>

void somar(float *a, float *b, float *r);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);
void calculadora(float a, float b, char op, float *r);

int main(){

    float a, b, r;
    char op, exit;

    do{
        printf("Digite dois num e a operacao desejada:\n");
        printf("+ -> soma\n");
        printf("- -> subtracao\n");
        printf("* -> multiplicacao\n");
        printf("/ -> divisao\n");
        printf("% -> resto\n");
        scanf("%f %f %c", &a, &b, &op);
        fflush(stdin);
        calculadora(a, b, op, &r);
        printf("O resultado eh: %f\n\n", r);
        printf("Deseja continuar? (s/n)\n");
        scanf("%c", &exit);

    }while(exit == 's');

    return 0;
}

/*
A funcao somar recebe e manipula tres referencias. Nao retorna valor algum, pois manipula r diretamente em seu endereco de memoria.
Temos aqui instanciados três ponteiros, que irao manipular variaveis no escopo de onde esta funcao foi chamada.
No caso de nossa aplicacao, a e b são ponteiros para variaveis instanciadas em calculadora(), e r eh um ponteiro para a variavel r instanciada no main().
*/
void somar(float *a, float *b, float *r){
    *r = *a + *b;
}

float subtrair(float a, float b){
    return a - b;
}

float multiplicar(float a, float b){
    return a * b;
}

float dividir(float a, float b){
    return a / b;
}

/*
A funcao calculadora tambem eh do tipo void, e nao possui retorno.
Ela instancia a, b e op em seu escopo, e recebe copias dos valores de a, b e op instanciados no main().
Ela instancia um ponteiro r, que recebe o endereco de memoria da variavel r, instanciada no main().
*/
void calculadora(float a, float b, char op, float *r){

    switch(op){
        case '+': somar(&a, &b, r); //passando o endereco das variaveis a e b, instanciadas aqui, e o ponteiro r, que por si so guarda o endereco de r instanciado na main()
            break;
        case '-': *r = subtrair(a, b);
            break;
        case '*': *r = multiplicar(a, b);
            break;
        case '/': *r = dividir(a, b);
            break;
        default: *r = 0;
            printf("Operacao invalida");
    }
}

