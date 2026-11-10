
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//INVERTER A ORDEM DOS CARACTERES
int main()
{
    char frase[1000];
    char auxiliar;
    int i, tamanho;

    strcpy(frase, "GUARANY CAMPEAO");

    tamanho = strlen(frase);

    for (i = 0; i < tamanho / 2; i++)
    {
        auxiliar = frase[i];
        frase[i] = frase[tamanho - 1 - i];
        frase[tamanho - 1 - i] = auxiliar;
    }

    printf("Frase invertida: %s\n", frase);
    
    return 0;
}
