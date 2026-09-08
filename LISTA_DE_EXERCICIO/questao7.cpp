/*
QUESTÃO 007. Desenvolver uma aplicação de software, utilizando o paradigma de
orientação a objetos, para implementar operações matemáticas com 2 números reais
(N1 e N2). Implementar os seguintes métodos:
 Soma, multiplicação, subtração, divisão.
 Percentual N2 de N1: N2 % de N1.
 Retornar o maior.
 Retornar o menor.
 Verificar se são iguais.
 Arredondamento para inteiro.
 Verificar se número é positivo ou negativo.
 Status de erro operacional (por exemplo, divisão por zero).
Desenvolver, pelo menos, uma classe e os métodos pertinentes para atender aos
requisitos apresentados. Obrigatoriamente incorporar construtor, polimorfismo,
métodos get e set, e sobreposição de classe: toString [retorno: DEFINIR
PADRÃO] .
*/
#include <string>
#include <cmath>
using namespace std;

class MATEMATICA
{
private:
    float n1, n2;

public:
    MATEMATICA()
    {
        n1 = 0;
        n2 = 0;
    };

    void setValores(float a, float b)
    {
        n1 = a;
        n2 = b;
    };

    float getN1()
    {
        return n1;
    }

    float getN2()
    {
        return n2;
    }

    float somar()
    {
        return n1 + n2;
    };

    float subtrair()
    {
        return n1 - n2;
    };

    float multiplicar()
    {
        return n1 * n2;
    };

    float dividir()
    {
        if (n2 == 0)
        {
            return 0;
        }

        return n1 / n2;
    };

    float percentual()
    {
        return n1 * n2 / 100;
    };

    float maior()
    {
        if (n1 > n2)
        {
            return n1;
        }

        return n2;
    };

    float menor()
    {
        if (n1 < n2)
        {
            return n1;
        }

        return n2;
    };

    bool iguais()
    {
        return n1 == n2;
    };

    int arredondarN1()
    {
        return round(n1);
    };

    int arredondarN2()
    {
        return round(n2);
    };

    bool n1Positivo()
    {
        return n1 >= 0;
    };

    bool n2Positivo()
    {
        return n2 >= 0;
    };

    bool erroDivisao()
    {
        return n2 == 0;
    };

    string toString()
    {
        return "Operacoes Matematicas";
    }
};


int main()
{
    float n1, n2;

    MATEMATICA mat;

    printf("\nOPERACOES MATEMATICAS");

    printf("\nDigite o primeiro numero: ");
    scanf_s("%f", &n1);

    printf("\nDigite o segundo numero: ");
    scanf_s("%f", &n2);

    mat.setValores(n1, n2);

    printf("\n\nRESULTADOS");

    printf("\nSoma = %7.2f",
        mat.somar());

    printf("\nSubtracao = %7.2f",
        mat.subtrair());

    printf("\nMultiplicacao = %7.2f",
        mat.multiplicar());

    if (mat.erroDivisao())
    {
        printf("\nDivisao: ERRO - divisao por zero");
    }
    else
    {
        printf("\nDivisao = %7.2f",
            mat.dividir());
    }

    printf("\n%d%% de %7.2f = %7.2f",
        (int)n2,
        n1,
        mat.percentual());

    printf("\nMaior = %7.2f",
        mat.maior());

    printf("\nMenor = %7.2f",
        mat.menor());

    if (mat.iguais())
    {
        printf("\nOs numeros sao iguais");
    }
    else
    {
        printf("\nOs numeros sao diferentes");
    }

    printf("\nN1 arredondado = %d",
        mat.arredondarN1());

    printf("\nN2 arredondado = %d",
        mat.arredondarN2());

    if (mat.n1Positivo())
    {
        printf("\nN1 e positivo");
    }
    else
    {
        printf("\nN1 e negativo");
    }

    if (mat.n2Positivo())
    {
        printf("\nN2 e positivo");
    }
    else
    {
        printf("\nN2 e negativo");
    }

    return 0;
}
