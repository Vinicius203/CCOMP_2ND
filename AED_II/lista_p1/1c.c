#include <stdio.h>
#include <stdlib.h>

void inverte(char *str);

int main()
{
    char n[51];

    printf("Entre com uma string de ate 50 caracteres: ");
    scanf("%[^\n]s", n);

    inverte(n);

    return 0;
}

void inverte(char *str)
{
    if (*str)
    {
        inverte(str + 1);
        printf("%c", *str);
    }
}