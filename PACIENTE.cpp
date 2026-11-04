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
 
// DESENVOLVER UMA APLICACAO DE SOFTWARE
// IMPLEMENTANDO DUAS CLASSES:
// [1] GESTAO DE DADOS PESSOAIS
//     NOME, IDADE, SEXO
// [2] CADASTRO DE PACIENTE - HERDAR OS DADOS PESSOAIS
//     TIPO DE SANGUE [A,B,AB,O]
//     GLICOSE
//     COLETEROL
 
class DADOSPESSOAL
{
    protected: char nome[100];
    protected: char sexo[100];
    protected: int idade;
   
    //CONSTRUTOR
    public: DADOSPESSOAL()
    {
        strcpy(nome,"");
        strcpy(sexo,"");
        idade=-1;
    };
   
    //CADASTRAR DADOS
    public: void setCadastro(char *nm,char *sx,int idd)
    {
        strcpy(nome,nm);
        strcpy(sexo,sx);
        idade=idd;
    };
   
    public: char *getNOME()
    {
        return nome;
    };
   
    public: void setNOME(char *nm)
    {
        strcpy(nome,nm);
    };
   
    public: char *getSEXO()
    {
        return sexo;
    };
   
    public: void setSEXO(char *sx)
    {
        strcpy(sexo,sx);
    };
   
    public: int getIDADE()
    {
        return idade;
    };
   
    public: void setIDADE(int idd)
    {
        idade=idd;
    };
   
};
 
class PACIENTE: public DADOSPESSOAL
{
    protected: char tiposangue[10];
    protected: float glicose;
    protected: float colesterol;
    
public:PACIENTE()
{
        strcpy(nome,"");
        strcpy(sexo,"");
        idade=-1;
        strcpy(tiposangue,"");
        glicose=-1;
        colesterol=-1;
}
public: void setPaciente(char *nm,char *sx,int idd,char *ts,float g,float col)
    {
        strcpy(nome,nm);
        strcpy(sexo,sx);
        idade=idd;
        strcpy(tiposangue,ts);
        glicose = g;
        colesterol = col;
    };

public: char *getTIPOSANGUE()
{
    return tiposangue;
}
public: float getGLICOSE()
{
    return glicose;
}
public: float getCOLESTEROL()
{
    return colesterol;
}

};
 
int main()
{
 char nome[100],sexo[100],tiposangue[100];
 
 PACIENTE pessoa;
 
 strcpy(nome,"FRODO");
 strcpy(sexo,"MASCULINO");
 strcpy(tiposangue,"B");
 pessoa.setPaciente(nome,sexo,33,tiposangue,80,210);
    printf("\n\n[NOME]:   %s",pessoa.getNOME());
	printf("\n[SEXO]:   %s",pessoa.getSEXO());
	printf("\n[TIPOSANGUE]:   %s",pessoa.getTIPOSANGUE());
	printf("\n[IDADE]:   %d anos",pessoa.getIDADE());
	printf("\n[COLESTEROL]: %10.2f ",pessoa.getCOLESTEROL());
	printf("\n[GLICOSE]:  %10.2f ",pessoa.getGLICOSE());
 
   
    printf("\n\nOBRIGADO POR UTILIZAR UM SOFTWARE TABAJARA"); 
 
    return 0;
}
