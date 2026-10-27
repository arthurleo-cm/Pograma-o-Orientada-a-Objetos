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


class PET
{
protected:
	char nomepet[100],raca[100];
protected:
	float peso,altura;
protected:
	float imc;

public:
	PET()
	{
		strcpy(nomepet,"");
		strcpy(raca,"");
		peso=-1;
		altura=-1;
		imc=-1;
	};

public:
	PET(char *nm, char *rc, float ps, float alt)
	{
		strcpy(nomepet,nm);
		strcpy(raca,rc);
		peso=ps;
		altura=alt;
		imc=calcularIMC();
	};

public:
	void setPET(char *nm,char *rc, float ps, float alt)
	{
		strcpy(nomepet,nm);
		strcpy(raca,rc);
		peso=ps;
		altura=alt;
		imc=calcularIMC();
	};

public:
	float calcularIMC()
	{
		imc = peso/(altura*altura);

		return imc;
	};

public:
	char *getNOMEPET()
	{
		return nomepet;
	};

public:
	char *getRACA()
	{
		return  raca;
	};

public:
	float getPESO()
	{
		return peso;
	};

public:
	float getALTURA()
	{
		return altura;
	};

public:
	float getIMC()
	{
		return imc;
	};


};

class CADASTRO
{
protected:
	char nome[1000];
protected:
	int ddd;
protected:
	char celular[100];
private:
	char aux[1000];

	//CONSTRUTOR
public:
	CADASTRO()
	{
		strcpy(nome,"");
		ddd=-1;
		strcpy(celular,"");
	};

	//CADASTRA OS dados
	//  INTERFACE DOS DADOS EXTERNO COM OS private
public:
	void setCadastro(char *n,int d,char *c)
	{
		strcpy(nome,n);
		ddd=d;
		strcpy(celular,c);
	};

public:
	void setNome(char *n)
	{
		strcpy(nome,n);
	};

public:
	char *getNome()
	{
		return nome;
	};

public:
	int getDDD()
	{
		return ddd;
	};

public:
	void setCelular(char *c)
	{
		strcpy(celular,c);
	};

public:
	void setDDD(int d)
	{
		ddd=d;
	};

public:
	void setDDDCelular(int d,char *c)
	{
		ddd=d;
		strcpy(celular,c);
	};

public:
	char *getCelular()
	{
		return celular;
	};

public:
	char *getDDDCelular()
	{
		sprintf(aux,"(%03d) %s",ddd,celular );
		return aux;
	};

};




class GATO: public PET, public CADASTRO
{
protected:
	int idade;
private:
	char aux[1000];

public:
	GATO()
	{
		//CHAMA O CONSTRUTOR DE CONTATO
		strcpy(nome,"");
		strcpy(celular,"");
		ddd=-1;
		strcpy(nomepet,"");
		strcpy(raca,"");
		peso=-1;
		altura=-1;
		idade=-1;
		imc=-1;
	};

public:
	GATO(char *nm,int d, char *cel,char *nmpet, char *rcpet, float ps, float alt,int idd)
	{
		//CHAMA O CONSTRUTOR DE CONTATO
		strcpy(nome,nm);
		strcpy(celular,cel);
		ddd=d;
		strcpy(nomepet,nmpet);
		strcpy(raca,rcpet);
		peso=ps;
		altura=alt;
		idade=idd;
		imc=calcularIMC();
	};

public:
	void setCadastro(char *nm,int d, char *cel,char *nmpet, char *rcpet, float ps, float alt,int idd)
	{
		//CHAMA O CONSTRUTOR DE CONTATO
		strcpy(nome,nm);
		ddd=d;
		strcpy(celular,cel);
		strcpy(nomepet,nmpet);
		strcpy(raca,rcpet);
		peso=ps;
		altura=alt;
		idade=idd;
		imc=calcularIMC();
	};


public:
	int getIDADE()
	{
		return idade;
	};

public:
	void setIDADE(int i)
	{
		idade=i;
	};
	//ASSINATURA DA CLASSE
	//CONTEM INFORMAÇÃO IMPORTANTE SOBRE A CLASSE
	//INFORMAÇÃO MATERIALIZADAS COM OS DADOS DO OBJETO INSTACIADO
public:
	char *toString()
	{
		sprintf(aux,"[GATO]: %s | (%03d)-%s | %s | %s | %7.2f Kg | %7.2f m | IMC = %7.2f | %d Anos",
		        nome,ddd,celular,nomepet,raca,peso,altura,imc,idade);

		return aux;
	};

};


int main()
{
	char nome[1000],celular[1000],nomepet[1000],raca[1000];
	int ddd;

	strcpy(nome,"MOLYBYDENYUZ");
	strcpy(celular,"970707070");
	ddd=19;
	strcpy(nomepet,"HEKULANUZ");
	strcpy(raca,"GARFIELD");
	GATO gato001;

	gato001.setCadastro(nome,ddd,celular,nomepet,raca, 40., 0.50,20);
	printf("\n\n[NOME]:       %s",gato001.getNome());
	printf("\n[CELULAR]:    (%03d)-%s",gato001.getDDD(),gato001.getCelular());
	printf("\n[NOME PET]:   %s",gato001.getNOMEPET());
	printf("\n[RACA]:       %s",gato001.getRACA());
	printf("\n[PESO]:   %10.2f Kg",gato001.getPESO());
	printf("\n[ALTURA]: %10.2f Metros",gato001.getALTURA());
	printf("\n[IMC]:    %10.2f",gato001.getIMC());
	printf("\n[IDADE]:  %10d Anos",gato001.getIDADE());
	printf("\n[GATO]:   %s",gato001.toString());

	printf("\n\nOBRIGADO POR UTILIZAR UM SOFTWARE TABAJARA");

	return 0;
}
