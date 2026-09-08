/*
QUESTÃO 006. Desenvolver uma aplicação de software, utilizando o paradigma de
orientação a objetos, para manipulação de STRINGs. Implementar os seguintes
métodos:
 Cadastrar a String
 Contar o número de caracteres
 Contar o número de caracteres numéricos
 Contar o número de espaços em branco
 Contar o número de vogais
 Contar o número de ocorrências de um caracter.
 Inverter a ordem dos caracteres
 Verificar se a String é numérica
Desenvolver, pelo menos, uma classe e os métodos pertinentes para atender aos
requisitos apresentados. Obrigatoriamente incorporar construtor, polimorfismo,
métodos get e set, e sobreposição de classe: toString [retorno: DEFINIR
PADRÃO] .
*/
#include <string>
#include <iostream>
using namespace std;

class STRING
{
private:
    string texto;

public:
    STRING()
    {
        texto = "";
    };

    void setTexto(string t)
    {
        texto = t;
    };

    string getTexto()
    {
        return texto;
    };

    int contarCaracteres()
    {
        return texto.length();
    };

    int contarNumericos()
    {
        int contador = 0;

        for (int i = 0; i < texto.length(); i++)
        {
            if (texto[i] >= '0' && texto[i] <= '9')
            {
                contador++;
            }
        }

        return contador;
    };

    int contarEspacos()
    {
        int contador = 0;

        for (int i = 0; i < texto.length(); i++)
        {
            if (texto[i] == ' ')
            {
                contador++;
            }
        }

        return contador;
    };

    int contarVogais()
    {
        int contador = 0;

        for (int i = 0; i < texto.length(); i++)
        {
            if (texto[i] == 'a' || texto[i] == 'e' ||
                texto[i] == 'i' || texto[i] == 'o' ||
                texto[i] == 'u' ||
                texto[i] == 'A' || texto[i] == 'E' ||
                texto[i] == 'I' || texto[i] == 'O' ||
                texto[i] == 'U')
            {
                contador++;
            }
        }

        return contador;
    };

    int contarCaracter(char caractere)
    {
        int contador = 0;

        for (int i = 0; i < texto.length(); i++)
        {
            if (texto[i] == caractere)
            {
                contador++;
            }
        }

        return contador;
    };

    string inverter()
    {
        string invertida = "";

        for (int i = texto.length() - 1; i >= 0; i--)
        {
            invertida = invertida + texto[i];
        }

        return invertida;
    };

    bool ehNumerica()
    {
        if (texto.length() == 0)
        {
            return false;
        }

        for (int i = 0; i < texto.length(); i++)
        {
            if (texto[i] < '0' || texto[i] > '9')
            {
                return false;
            }
        }

        return true;
    };

    string toString()
    {
        return texto;
    }
};


int main()
{
    string texto;
    char caractere;

    STRING str;

    printf("\nMANIPULACAO DE STRING");

    printf("\nDigite uma string: ");
    getline(cin, texto);

    str.setTexto(texto);

    printf("\nNumero de caracteres: %d",
        str.contarCaracteres());

    printf("\nNumero de caracteres numericos: %d",
        str.contarNumericos());

    printf("\nNumero de espacos: %d",
        str.contarEspacos());

    printf("\nNumero de vogais: %d",
        str.contarVogais());

    printf("\nDigite um caractere para procurar: ");
    scanf(" %c", &caractere);

    printf("\nOcorrencias: %d",
        str.contarCaracter(caractere));

    printf("\nString invertida: %s",
        str.inverter().c_str());

    if (str.ehNumerica())
    {
        printf("\nA string e numerica");
    }
    else
    {
        printf("\nA string nao e numerica");
    }

    return 0;
}
