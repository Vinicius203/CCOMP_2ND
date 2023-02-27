#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int retornaStatusSemaforo(int n);
void printaStatus(int r);

int main () {
    int r, n;

    srand(time(NULL));
    printf("Entre com o id do semaforo desejado: ");
    scanf("%d", &n);

    r = retornaStatusSemaforo(n);
    printaStatus(r);

    return 0;
}

int retornaStatusSemaforo(int n) {
    int r, x = 0;

    while(1) {
        r = rand() % 3;

        switch(n) {
            case(10):
            case(20):
            case(30):
            case(40):
            case(50):
            case(60):
                x = 1;
                break;
            default:
                printf("Entre com um valor valido para o id do semaforo:\n");
                scanf("%d", &n);
        }

        if(x == 1) {
            break;
        }

    }
}

void printaStatus(int r) {
    if(r == 0) {
       printf("O semaforo esta no estado VERMELHO.");
    }
    else if(r == 1) {
        printf("O semaforo esta no estado AMARELO.");
    }
    else {
        printf("O semaforo esta no estado VERDE.");
    }
}
