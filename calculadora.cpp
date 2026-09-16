
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class CALCULADORA

{
private:
	float n1,n2,resultado;

public:
	void setValores(float a,float b)
	{
        n1 = a;
        n2 = b;
        
	}
	 float getN1()
    {
        return n1;
    }

    float getN2()
    {
        return n2;
    }
    float getRESULTADO()
    {
        return resultado;
    }
public:
    float somar()
    {
        resultado = n1 + n2;
        return resultado;
    };
    float somar(float n1,float n2)
    {
       setValores(n1,n2);
        return somar();
        
    }
public:
    float subtrair()
    {
        resultado = n1 - n2;
        return resultado;
    }
    float subtrair(float n1,float n2)
    {
        n1 = n1;
        n2 = n2;
        subtrair();
        return resultado;
    }
public:
    float multiplicar()
    {
        resultado = n1 * n2;
        return resultado;
    }
public:
    float divisao()
    {
         if (n2 == 0)
        {
            resultado = 0;
            return 0;
        }
        resultado = n1 / n2;
        return resultado;
    };


};


int main()
{
    float nv1,nv2,vresultado;
    CALCULADORA cal;
    printf("\nINICIANDO A CALCULADORA\n");
    printf("\nDigite o primeiro numero: ");
    scanf("%f", &nv1);
    printf("\nDigite o segundo numero: ");
    scanf("%f", &nv2);
    cal.setValores(nv1,nv2);
    printf("\nSoma = %7.2f",cal.somar());
    printf("\nSubtração = %7.2f",cal.subtrair());
    printf("\nMultiplicação = %7.2f",cal.multiplicar());
    printf("\nDivisão = %7.2f",cal.divisao());
}
