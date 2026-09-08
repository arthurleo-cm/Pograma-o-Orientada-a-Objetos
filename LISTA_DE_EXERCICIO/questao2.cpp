/*
QUESTÃO 002. Desenvolver uma aplicação de software, utilizando o paradigma de
orientação a objetos, para cadastrar funcionários de uma empresa, calcular o salário
líquido e descontos de acordo com os seguintes requisitos:
 Dados cadastrados: Nome do Funcionário, Salário hora, horas trabalhadas,
número de filhos, enquadramento funcional (5 níveis: 0 a 4).
 Cálculo do salário bruto = salário hora * horas trabalhadas
 Adicional por filho: para cada filho acrescentar 5% limitado a 20%
 Desconto do imposto de renda - seguir a tabela:
TOTAL BRUTO = SALÁRIO BRUTO + ADICIONAL FILHOS % DESCONTO IR
TOTAL BRUTO < R$ 4000.00 0%
4000.00 <= TOTAL BRUTO < 8000.00 15%
8000.00 <= TOTAL BRUTO < 12000.00 22.5%
12000.00 <= TOTAL BRUTO 27.5%
 Desconto IR deve ser aplicado sobre o salário bruto mais adicional filhos.
 Salário líquido = salário bruto + adicional filhos – desconto IR
Desenvolver, pelo menos, uma classe e os métodos pertinentes para atender aos
requisitos apresentados. Obrigatoriamente incorporar construtor, polimorfismo,
métodos get e set, e sobreposição de classe: toString [retornar: nome
funcionário, salário bruto, salário líquido e enquadramento funcional] .
*/
#include <string>
#include <iostream>
using namespace std;

class FUNCIONARIO
{
private:
    string nome;
    float salarioHora, horasTrabalhadas;
    int filhos, enquadramento;
    float salarioBruto, adicionalFilhos, descontoIR, salarioLiquido;

public:
    FUNCIONARIO()
    {
        nome = "";
        salarioHora = 0;
        horasTrabalhadas = 0;
        filhos = 0;
        enquadramento = 0;
        salarioBruto = 0;
        adicionalFilhos = 0;
        descontoIR = 0;
        salarioLiquido = 0;
    };

    void setValores(string n, float sh, float ht, int f, int e)
    {
        nome = n;
        salarioHora = sh;
        horasTrabalhadas = ht;
        filhos = f;
        enquadramento = e;
    };

    void calcular()
    {
        salarioBruto = salarioHora * horasTrabalhadas;

        float percentualFilhos = filhos * 5;

        if (percentualFilhos > 20)
        {
            percentualFilhos = 20;
        }

        adicionalFilhos = salarioBruto * percentualFilhos / 100;

        float totalBruto = salarioBruto + adicionalFilhos;

        if (totalBruto < 4000)
        {
            descontoIR = 0;
        }
        else if (totalBruto < 8000)
        {
            descontoIR = totalBruto * 15 / 100;
        }
        else if (totalBruto < 12000)
        {
            descontoIR = totalBruto * 22.5 / 100;
        }
        else
        {
            descontoIR = totalBruto * 27.5 / 100;
        }

        salarioLiquido = totalBruto - descontoIR;
    };

    string getNome()
    {
        return nome;
    }

    float getSalarioBruto()
    {
        return salarioBruto;
    }

    float getSalarioLiquido()
    {
        return salarioLiquido;
    }

    int getEnquadramento()
    {
        return enquadramento;
    }

    string toString()
    {
        return nome;
    }
};

int main()
{
    string nome;
    float salarioHora, horas;
    int filhos, enquadramento;

    FUNCIONARIO funcionario;

    printf("\nCADASTRO DE FUNCIONARIO");

    printf("\nDigite o nome: ");
    getline(cin, nome);

    printf("\nDigite o salario por hora: ");
    scanf("%f", &salarioHora);

    printf("\nDigite as horas trabalhadas: ");
    scanf("%f", &horas);

    printf("\nDigite o numero de filhos: ");
    scanf("%d", &filhos);

    printf("\nDigite o enquadramento funcional (0 a 4): ");
    scanf("%d", &enquadramento);

    funcionario.setValores(
        nome,
        salarioHora,
        horas,
        filhos,
        enquadramento
    );

    funcionario.calcular();

    printf("\n\nRESULTADO");
    printf("\nNome: %s", funcionario.getNome().c_str());
    printf("\nSalario bruto: R$ %7.2f",
        funcionario.getSalarioBruto());
    printf("\nSalario liquido: R$ %7.2f",
        funcionario.getSalarioLiquido());
    printf("\nEnquadramento funcional: %d",
        funcionario.getEnquadramento());

    return 0;
}
