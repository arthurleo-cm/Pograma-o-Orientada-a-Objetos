/*QUESTÃO 004. Desenvolver uma aplicação de software, utilizando o paradigma de
orientação a objetos, para calcular o perímetro e área das seguintes figuras
geométricas: retângulo, triangulo, trapézio, círculo. Obrigatoriamente incorporar
construtor, polimorfismo, métodos get e set, e sobreposição de classe: toString
[retorno: DEFINIR PADRÃO] .*/
#include <string>
using namespace std;

class RETANGULO
{
private:
    float base, altura;

public:
    RETANGULO()
    {
        base = 0;
        altura = 0;
    };

    void setValores(float b, float a)
    {
        base = b;
        altura = a;
    };

    float getBase()
    {
        return base;
    }

    float getAltura()
    {
        return altura;
    }

    float calcularArea()
    {
        return base * altura;
    };

    float calcularPerimetro()
    {
        return 2 * (base + altura);
    };

    string toString()
    {
        return "Retangulo";
    }
};


class TRIANGULO
{
private:
    float base, altura, lado1, lado2, lado3;

public:
    TRIANGULO()
    {
        base = 0;
        altura = 0;
        lado1 = 0;
        lado2 = 0;
        lado3 = 0;
    };

    void setValores(float b, float a, float l1, float l2, float l3)
    {
        base = b;
        altura = a;
        lado1 = l1;
        lado2 = l2;
        lado3 = l3;
    };

    float getBase()
    {
        return base;
    }

    float getAltura()
    {
        return altura;
    }

    float calcularArea()
    {
        return (base * altura) / 2;
    };

    float calcularPerimetro()
    {
        return lado1 + lado2 + lado3;
    };

    string toString()
    {
        return "Triangulo";
    }
};


class TRAPEZIO
{
private:
    float baseMaior, baseMenor, altura;
    float lado1, lado2;

public:
    TRAPEZIO()
    {
        baseMaior = 0;
        baseMenor = 0;
        altura = 0;
        lado1 = 0;
        lado2 = 0;
    };

    void setValores(float bm, float bn, float a, float l1, float l2)
    {
        baseMaior = bm;
        baseMenor = bn;
        altura = a;
        lado1 = l1;
        lado2 = l2;
    };

    float calcularArea()
    {
        return ((baseMaior + baseMenor) * altura) / 2;
    };

    float calcularPerimetro()
    {
        return baseMaior + baseMenor + lado1 + lado2;
    };

    float getBaseMaior()
    {
        return baseMaior;
    }

    float getBaseMenor()
    {
        return baseMenor;
    }

    string toString()
    {
        return "Trapezio";
    }
};


class CIRCULO
{
private:
    float raio;

public:
    CIRCULO()
    {
        raio = 0;
    };

    void setRaio(float r)
    {
        raio = r;
    };

    float getRaio()
    {
        return raio;
    };

    float calcularArea()
    {
        return 3.14159 * raio * raio;
    };

    float calcularPerimetro()
    {
        return 2 * 3.14159 * raio;
    };

    string toString()
    {
        return "Circulo";
    }
};


int main()
{
    float base, altura;
    float l1, l2, l3;
    float raio;

    RETANGULO retangulo;

    printf("\nRETANGULO");

    printf("\nDigite a base: ");
    scanf("%f", &base);

    printf("\nDigite a altura: ");
    scanf("%f", &altura);

    retangulo.setValores(base, altura);

    printf("\nArea = %7.2f", retangulo.calcularArea());
    printf("\nPerimetro = %7.2f", retangulo.calcularPerimetro());


    TRIANGULO triangulo;

    printf("\n\nTRIANGULO");

    printf("\nDigite a base: ");
    scanf("%f", &base);

    printf("\nDigite a altura: ");
    scanf("%f", &altura);

    printf("\nDigite o lado 1: ");
    scanf("%f", &l1);

    printf("\nDigite o lado 2: ");
    scanf("%f", &l2);

    printf("\nDigite o lado 3: ");
    scanf("%f", &l3);

    triangulo.setValores(base, altura, l1, l2, l3);

    printf("\nArea = %7.2f", triangulo.calcularArea());
    printf("\nPerimetro = %7.2f", triangulo.calcularPerimetro());


    TRAPEZIO trapezio;

    printf("\n\nTRAPEZIO");

    printf("\nDigite a base maior: ");
    scanf("%f", &base);

    printf("\nDigite a base menor: ");
    scanf("%f", &altura);

    printf("\nDigite a altura: ");
    scanf("%f", &raio);

    printf("\nDigite o lado 1: ");
    scanf("%f", &l1);

    printf("\nDigite o lado 2: ");
    scanf("%f", &l2);

    trapezio.setValores(base, altura, raio, l1, l2);

    printf("\nArea = %7.2f", trapezio.calcularArea());
    printf("\nPerimetro = %7.2f", trapezio.calcularPerimetro());


    CIRCULO circulo;

    printf("\n\nCIRCULO");

    printf("\nDigite o raio: ");
    scanf("%f", &raio);

    circulo.setRaio(raio);

    printf("\nArea = %7.2f", circulo.calcularArea());
    printf("\nPerimetro = %7.2f", circulo.calcularPerimetro());

    return 0;
}
