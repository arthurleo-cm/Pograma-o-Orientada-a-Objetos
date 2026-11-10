#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//LISTAR_CARACTERES
int main()
{
    char nome[1000];

    strcpy(nome, "JUVENAL");

    printf("\n\n");

    for (int i = 0; i < strlen(nome); i++)
    {
        printf("\n%3d - %c - %3d", i, nome[i], nome[i]);
    }

    return 0;
}
