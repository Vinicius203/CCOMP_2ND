#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char cor;
    float coordX, coordY;
}Ponto;

Ponto registraPonto();
int rPonto(FILE *f, Ponto *p);
int wPonto(FILE *f);

int main () {
    char filename[20] = "pontos.txt";
    FILE *f;
    Ponto p;
    int qtd_pontos;

    f = fopen(filename, "a+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    printf("Lendo pontos salvos:\n");
    while(rPonto(f, &p) != -1) {
        printf("%d %c %.2f %.2f\n", p.id, p.cor, p.coordX, p.coordY);
    }

    printf("\n\n-------------- Cadastrando Pontos ------------\n");
    printf("Digite quantos pontos quer cadastrar: ");
    scanf("%d", &qtd_pontos);

    for(int i = 0; i < qtd_pontos; i ++) {
        wPonto(f);
    }

    fclose(f);

    return 0;
}

Ponto registraPonto () {
    Ponto p;

    printf("-------------------------------------\n");
    printf("\tDigite um novo ponto: \n");
    printf("-------------------------------------\n");
    printf("ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Cor: ");
    scanf("%c", &p.cor);
    printf("Coordenada X: ");
    scanf("%f", &p.coordX);
    printf("Coordenada Y: ");
    scanf("%f", &p.coordY);

    return p;
}

int rPonto (FILE *f, Ponto *p) {
    return fscanf(f, "%d %c %f %f", &p->id, &p->cor, &p->coordX, &p->coordY);
}

int wPonto(FILE *f) {
    Ponto p = registraPonto();

    return fprintf(f, "%d %c %.2f %.2f\n", p.id, p.cor, p.coordX, p.coordY);
}

