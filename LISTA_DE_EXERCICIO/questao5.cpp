/*
QUESTÃO 005. Desenvolver uma aplicação de software, utilizando o paradigma de
orientação a objetos, para validar o CPF: validar os dois dígitos verificadores. Regras
para validação dos dígitos verificadores:
Como validar o CPF:
1) O CPF tem 11 dígitos numéricos: "###.###.###-DV"
2) A 9 primeiros dígitos de cadastro + 2 dígitos de verificação (validação)
3) Calculando o primeiro dígito verificador: multiplique os 9 primeiros dígitos, da
direita para a esquerda, por fatores iniciando de 2 a 10, e some os resultados
parciais, como indicado a seguir: considerar como exemplo: "621.209.258-DV":
total1 = 6 * 10 + 2 * 9 + 1 * 8 + 2 * 7 + 0 * 6 + 9 * 5 + 2 * 4 + 5 * 3 + 8 * 2
4) Validação do primeiro dígito verificador (D): Multiplique o total por 10 e divida
por 11, o valor que interessa é o resto: total * 10 / 11
int digito1 = (total1 *10) % 11
Se digito1 for igual a 10, então, digito1 assume o valor 0 (zero)
Se digito1 for igual a D, então este dígito é válido.

5) Calculando o segundo dígito verificador: utilizar o mesmo procedimento
aplicado na etapa (3) considerando os 9 primeiros dígitos e o primeiro dígito
verificador, mas, multiplicado os dígitos, da direita para a esquerda , por fatores
de 2 a 11:
total2 = 6 * 11 + 2 * 10 + 1 * 9 + 2 * 8 + 0 * 7 + 9 * 6 + 2 * 5 + 5 * 4 + 8 * 3 + D *2
6) Validação do segundo dígito verificador (V): Multiplique o total por 10 e divida
por 11, o valor que interessa é o resto: total * 10 / 11
digito2 =(total2 *10) % 11
Se digito2 for igual a 10, então, digito2 assume o valor 0 (zero)
Se digito2 for igual a V, então este dígito é válido.

7) Se a validação dos dois dígitos verificadores forem True, então, o CPF é válido.
Desenvolver, pelo menos, uma classe e os métodos pertinentes para atender aos
requisitos apresentados. Obrigatoriamente incorporar construtor, polimorfismo,
métodos get e set, e sobreposição de classe: toString [retorno: DEFINIR
PADRÃO] .
*/
class CPF
{
    private: char cpf[20];
    //status:  0 - INVALIDO   1 - VALIDO
    private: int status;
  
    //SETAR O VALOR DO cpf
    public: void setCPF(char *c)
    {
       strcpy(cpf,c);  
    };
    
    public: int validarCPF(char *c)
    {
        setCPF(c);
        return validarCPF();
    }
    
    public: int validarCPF()
    {
        //VALIDAR PRIMEIRO DIGITO
        //                     1
        //           01234567890
        // exemplo: "621209258DV": 
        // total1 = 6 * 10 + 2 * 9 + 1 * 8 + 2 * 7 + 0 * 6 + 9 * 5 + 2 * 4 + 5 * 3 + 8 * 2 
        int total1=0;
        int cont1=0;
        for(int pos=10;pos>=2;pos--)
        {
            total1=total1+ (int)(cpf[cont1]-'0') * pos;
            cont1++;
        }
        
        //int digito1 = (total1 *10) % 11 
        int digito1=(total1*10)%11;
        //Se digito1 for igual a 10, então, digito1 assume o valor 0 (zero) 
        if(digito1==10)
             digito1=0;
        //Se digito1 for igual a D, então este dígito é válido.
        //EFETUAR A COMPARACAO INVERSA, ASSIM, SE O PRIMEIRO
        // DIGITO VERIFICADOR FOR FALSO, ENTAO, NAO CONTINUAR
        // O ALGORITMO
        if( digito1 != (int)(cpf[9]-'0') )
        {
            status=0;
            return status;
        }
        
        //VERIFICAR O DIGITO2
        //total2 = 6 * 11 + 2 * 10 + 1 * 9 + 2 * 8 + 0 * 7 + 9 * 6 + 2 * 5 + 5 * 4 + 8 * 3 + D * 2 
        int total2=0;
        int cont2=0;
        for(int pos=11;pos>=2;pos--)
        {
            total2=total2+ (int) (cpf[cont2]-'0') *pos;
            cont2++;
        }
        
        //digito2 =(total2 *10) % 11 
        int digito2=(total2*10)%11;
        //Se digito2 for igual a 10, então, digito2 assume o valor 0 (zero)
        if(digito2==10)
            digito2=0;
            
        //Se digito2 for igual a V, então este dígito é válido. 
        if(digito2!= (int)(cpf[10]-'0'))
        {
            status=0;
            return status;
        }
        
        status=1;
        return status;
    };
    
    public: int getStatus()
    {
        return status;
    };
    
    public:  char *getCPF()
    {
        return cpf;
    };
};


int main()
{
    //DEFINIR OBJETO
    CPF cpf;
    //char vlCPF[100]="12345678909";
    //char vlCPF[100]="04226990048";
    char vlCPF[100]="78876738010";
    
    cpf.setCPF(vlCPF);
    if(cpf.validarCPF()==1)
       printf("\nCPF: %s - VALIDO",vlCPF);
    else
       printf("\nCPF: %s - INVALIDO",vlCPF);

    if(cpf.validarCPF(vlCPF)==1)
       printf("\nCPF: %s - VALIDO",vlCPF);
    else
       printf("\nCPF: %s - INVALIDO",vlCPF);       
    printf("\n\nOBRIGADO POR UTILIZAR O SOFTWARE TABAJARA");

    return 0;
}
