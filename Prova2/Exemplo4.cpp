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
// CONTAR O NUMERO DE OCORRENCIAS DE UM CARACTER
// INVERTER A ORDEM DE UMA CADEIA DE CARACTERES
// SUBSTITUIR UM CARACTER POR OUTRO
// SUBSTITUIR OS CARACTERES MINUSCULOS POR MAIUSCULOS
//

class CARACTERES
{
    protected: char stringoriginal[1000];
    protected: int numerocaracteres;
    protected: int ehnumerica;

public: CARACTERES()
{
    strcpy(stringoriginal,"");
    numerocaracteres = 0;
    ehnumerica = 0;
    
};

public: CARACTERES(char *string)
{
    strcpy(stringoriginal,string);
    numerocaracteres=numeroCaracteres();
    ehnumerica=ehnumericas();
};

public: void setCADASTRO(char *string)
{
    strcpy(stringoriginal,string);
    numerocaracteres=numeroCaracteres();
    ehnumerica=ehnumericas();
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
        //  printf("NAO Eh NUMERO  ");
          return 0;    
        }
       // else
        //  {
         //     printf("Eh NUMERO  ");
        //  }
       // return 1;
    }
    
    return 1;
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
}
