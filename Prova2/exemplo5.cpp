/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
// deenvolver uma classe,passivel de Herança
//incorporando funcionalidade associadas a manipulação de string - Cadeia de Caracteres
// Atributos : char stringoriginal[1000];
// METODOS BASICOS:
//           CONSTRUTOR
//          setCADASTRO ou setSTRING
//            getSTRING
// METODOS:
// CONTAR O NÚMERO DE Caracteres feita
// VERIFICAR SE A STRING EH NUMERICA feita
// INVERTER A ORDEM DE UMA CADEIA DE CARACTERES feita
// SUBSTITUIR UM CARACTER POR OUTRO
// SUBSTITUIR OS CARACTERES MINUSCULOS POR MAIUSCULOS
// CONTAR O NUMERO DE OCORRENCIAS DE UM CARACTER
class CARACTERES
{
    protected: char stringoriginal[1000];
    protected: int numerocaracteres;
    protected: int ehnumerica;
    protected: int inverso;

public: CARACTERES()
{
    strcpy(stringoriginal,"");
    numerocaracteres = 0;
    ehnumerica = 0;
    inverso = 0;
};

public: CARACTERES(char *string)
{
    strcpy(stringoriginal,string);
    numerocaracteres=numeroCaracteres();
    ehnumerica=ehnumericas();
    inverso = 0;
};

public: void setCADASTRO(char *string)
{
    strcpy(stringoriginal,string);
    numerocaracteres=numeroCaracteres();
    ehnumerica=ehnumericas();
    inverso = 0;
};

public: char *getSTRING()
{
    return stringoriginal;
};

public: int numeroCaracteres()
{
    numerocaracteres = 0;

    for(int i = 0; stringoriginal[i] != '\0'; i++)
    {
        numerocaracteres++;
    }

    return numerocaracteres;
};

public: int ehnumericas()
{
    for(int i = 0; stringoriginal[i] != '\0'; i++)
    {
        if((stringoriginal[i] < '0') || (stringoriginal[i] > '9'))
        {
            return 0;
        }
    }

    return 1;
};

public: int inverter()
{
    char auxiliar;
    int tamanho = strlen(stringoriginal);
    for(int i = 0; i < tamanho / 2; i++)
    {
        auxiliar = stringoriginal[i];
        stringoriginal[i] = stringoriginal[tamanho - 1 - i];
        stringoriginal[tamanho - 1 - i] = auxiliar;
    }
    printf("Frase invertida: %s\n", stringoriginal);
    return 0;
};
public: int contarOcorrencias(char caracter)
{
    int contador = 0;

    for(int i = 0; stringoriginal[i] != '\0'; i++)
    {
        if(stringoriginal[i] == caracter)
        {
            contador++;
        }
    }

    return contador;
};

public: void substituirCaracter(char antigo, char novo)
{
    for(int i = 0; stringoriginal[i] != '\0'; i++)
    {
        if(stringoriginal[i] == antigo)
        {
            stringoriginal[i] = novo;
        }
    }

    ehnumerica = ehnumericas();
};

public: void maiusculas()
{
    for(int i = 0; stringoriginal[i] != '\0'; i++)
    {
        if((stringoriginal[i] >= 'a') && (stringoriginal[i] <= 'z'))
        {
            stringoriginal[i] = stringoriginal[i] - ('a' - 'A');
        }
    }
};

};

int main()
{
    char stringoriginal[1000];
    CARACTERES vcaracter;

    strcpy(stringoriginal, "BILBO  ");
    vcaracter.setCADASTRO(stringoriginal);
    printf("Numero de caracteres: %d\n",vcaracter.numeroCaracteres());
    printf("Eh numerica? %d\n",vcaracter.ehnumericas());
    vcaracter.inverter();
    strcpy(stringoriginal, "bilbo baggins");
    vcaracter.setCADASTRO(stringoriginal);
    printf("Ocorrencias de 'b': %d\n", vcaracter.contarOcorrencias('b'));
    vcaracter.substituirCaracter('b', 'x');
    printf("Apos substituir: %s\n", vcaracter.getSTRING());
    vcaracter.maiusculas();
    printf("Em maiusculas: %s\n", vcaracter.getSTRING());

    return 0;
}
