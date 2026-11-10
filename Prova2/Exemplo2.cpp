#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DADOS UMA STRING - CADEIA DE CARACTERES
// SOMAR O SEU VALOR NUMERICO
int main()
{
    char VALOR[1000];
    int soma = 0;
    strcpy(VALOR, "123456789");

    for(int i = 0;i < strlen(VALOR);i++)
    {
        soma = soma + (VALOR[i] - '0');    
    }
    printf("\nSTRING: %s", VALOR);
    printf("\nSOMA: %d\n",soma);

    return 0;
}
