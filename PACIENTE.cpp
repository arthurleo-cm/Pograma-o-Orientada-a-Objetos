
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class DADOSPESSOAL
{
protected:
	char nome[100];
	char sexo[100];
	int idade;

public:


	DADOSPESSOAL()
	{
		strcpy(nome, "");
		strcpy(sexo, "");
		idade = -1;
	}


	void setCadastro(char *nm, char *sx, int idd)
	{
		strcpy(nome, nm);
		strcpy(sexo, sx);
		idade = idd;
	}

	char *getNOME()
	{
		return nome;
	}

	void setNOME(char *nm)
	{
		strcpy(nome, nm);
	}

	char *getSEXO()
	{
		return sexo;
	}

	void setSEXO(char *sx)
	{
		strcpy(sexo, sx);
	}

	int getIDADE()
	{
		return idade;
	}

	void setIDADE(int idd)
	{
		idade = idd;
	}
};



class PACIENTE : public DADOSPESSOAL
{
protected:
	char tiposangue[100];
	float glicose;
	float colesterol;
	float gc;

public:

	PACIENTE()
	{
		strcpy(tiposangue, "");
		glicose = -1;
		colesterol = -1;
		gc = -1;
	}


	void setPaciente(char *nm, char *sx, int idd,
	                 char *ts, float g, float col)
	{
		setCadastro(nm, sx, idd);

		strcpy(tiposangue, ts);
		glicose = g;
		colesterol = col;
		gc = calcularGC();
	}


	char *getTIPOSANGUE()
	{
		return tiposangue;
	}


	float getGLICOSE()
	{
		return glicose;
	}


	float getCOLESTEROL()
	{
		return colesterol;
	}


	float calcularGC()
	{
		if (glicose > 0)
			gc = colesterol / (glicose * glicose * 1.45);

		return gc;
	}


	float getGC()
	{
		return gc;
	}
};
// IMPLEMENTAR A CLASSE CONSULTA
//HERDARA OS DADOS DA CLASSE PACIENTE
class CONSULTA : public PACIENTE
{
    protected: char observacao[1000];
    protected: char nomeMedico[1000];
    protected: data[200];
    protected: horario[200];
}


int main()
{
	char nome[100], sexo[100], tiposangue[100];

	PACIENTE pessoa;

	strcpy(nome, "FRODO");
	strcpy(sexo, "MASCULINO");
	strcpy(tiposangue, "B");

	pessoa.setPaciente(nome, sexo, 33, tiposangue, 80, 210);

	printf("\n[NOME]: %s", pessoa.getNOME());
	printf("\n[SEXO]: %s", pessoa.getSEXO());
	printf("\n[TIPO SANGUINEO]: %s", pessoa.getTIPOSANGUE());
	printf("\n[IDADE]: %d anos", pessoa.getIDADE());

	printf("\n[COLESTEROL]: %.2f", pessoa.getCOLESTEROL());
	printf("\n[GLICOSE]: %.2f", pessoa.getGLICOSE());
	printf("\n[GC]: %.6f", pessoa.getGC());

	printf("\n\nOBRIGADO POR UTILIZAR UM SOFTWARE TABAJARA");

	return 0;
}
