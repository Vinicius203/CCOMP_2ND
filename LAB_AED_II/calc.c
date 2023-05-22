#include<stdio.h>

double soma(double x, double y){
    return x + y;
}

double subtracao(double x, double y){
    return x - y;
}

double multiplicacao(double x, double y){
    return x * y;
}

double divisao(double x, double y){
    return x / y;
}

unsigned short int continuar (void){
    int flag;
    printf("Deseja continuar?\n 1 = Sim\n 2 = Nao\n");
    scanf("%d", &flag);
    return flag;
}

int main(void) {

    double r, x, y;
    int tipo, a=1, n=0, f=0;

    while (n != 5) {

        if (a == 1){
                printf("Use os botoes:\n 1 - Adicao\n 2 - Subtracao\n 3 - Multiplicacao\n 4 - Divisao\n 5 - Encerrar\n\n");
        }
        else{
            printf(" 1 - Adicao\n 2 - Subtracao\n 3 - Multiplicacao\n 4 - Divisao\n 5 - Encerrar\n");
        }
                scanf("%d", &tipo);

        switch(tipo){

        case(1):
            printf("Digite dois valores: ");
            scanf("%lf %lf", &x, &y);
            r = soma(x, y);
            printf("Resultado da adicao eh: %.2lf\n", r);
            f = continuar();
            if (f == 1){
                printf("Qual operacao deseja fazer agora?\n");
            }
            else{
                n = 5;
            }

            a++;
            break;

        case(2):
            printf("Digite dois valores: ");
            scanf("%lf %lf", &x, &y);
            r = subtracao(x, y);
            printf("Resultado da subtracao eh: %.2lf\n", r);
            f = continuar();
            if (f == 1){
                printf("Qual operacao deseja fazer agora?\n");
            }
            else{
                n = 5;
            }
            a++;
            break;


        case(3):
            printf("Digite dois valores: ");
            scanf("%lf %lf", &x, &y);
            r = multiplicacao(x, y);
            printf("Resultado da multiplicao eh: %.2lf\n", r);
            f = continuar();
            if (f == 1){
                printf("Qual operacao deseja fazer agora?\n");
            }
            else{
                n = 5;
            }
            a++;
            break;

         case(4):
            printf("Digite dois valores: ");
            scanf("%lf %lf", &x, &y);
            r = divisao(x, y);
            printf("Resultado da divisao eh: %.2lf\n", r);
            f = continuar();
            if (f == 1){
                printf("Qual operacao deseja fazer agora?\n");
            }
            else{
                n = 5;
            }
            a++;
            break;

        case(5):

            n = 5;
            break;
        }

    }
    printf("Obrigado por utilizar o programa!");
    return 0;
}


