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
    protected: char nomepet[100],raca[100];
    protected: float peso,altura;
    protected: float imc;

    public: PET()
    {
        strcpy(nomepet,"");
        strcpy(raca,"");
        peso=-1;
        altura=-1;
        imc=-1;
    };
    
    public: PET(char *nm, char *rc, float ps, float alt)
    {
        strcpy(nomepet,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        imc=calcularIMC();
    };
    
    public: void setPET(char *nm,char *rc, float ps, float alt)
    {
        strcpy(nomepet,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        imc=calcularIMC();
    };
    
    public: float calcularIMC()
    {
        imc = peso/(altura*altura);
        
        return imc;
    };

    public: char *getNOMEPET()
    {
        return nomepet;
    };
    
    public: char *getRACA()
    {
        return  raca;
    };
    
    public: float getPESO()
    {
        return peso;
    };
    
    public: float getALTURA()
    {
        return altura;
    };
    
    public: float getIMC()
    {
        return imc;
    };
     
};
     
class AVES: public PET
{
    protected: char corPENA[100];
    protected: float diametro0V0;
    private: char aux[1000];

public: AVES()
{
    strcpy(nomepet,"");
    strcpy(raca,"");
    peso=-1;
    altura=-1;
    imc=-1;
    strcpy(corPENA,"");
    diametro0V0=-1;
    
};
    public: AVES(char *nm,char *rc,float ps,float alt,char *cp,float dov)
    {
        strcpy(nomepet,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        strcpy(corPENA,cp);
        diametro0V0=dov;
        imc=calcularIMC();
    };
    public:  void setCadastroAVES(char *nm, char *rc, float ps, float alt,char *cp,float dov)
    {
        
        strcpy(nomepet,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        imc=calcularIMC();
        strcpy(corPENA,cp);
        diametro0V0=dov;
    };
    
    public: char *getCORPENA()
    {
        return corPENA;
    }
    public: void setCORPENA(char * cp)
    {
        strcpy(corPENA,cp);
    }
    public: void setDIAMETROOVO(float dov)
    {
        diametro0V0=dov;
    };
    
    public: float getDIAMETROOVO()
    {
        return diametro0V0;
    }
     public: char *toString()
    {
        
        sprintf(aux,"[AVES]: %20s | %20s  | %20s",nomepet,raca,corPENA);

        return aux;
    };
    
    
};



int main()
{
    char nome[1000],raca[1000],corpena[100];
    printf("Hello World");
    AVES papagaio;
    strcpy(nome,"HAGAMENON");
    strcpy(raca,"LORO");
    strcpy(corpena,"VERDE");
    
    papagaio.setCadastroAVES(nome,raca,5, 0.2,corpena,5);
    printf("\n\n[NOME]:   %s",papagaio.getNOMEPET());
    printf("\n[RACA]:   %s",papagaio.getRACA());
    printf("\n[PENA]:   %s",papagaio.getCORPENA());
    printf("\n[PESO]:   %10.2f Kg",papagaio.getPESO());
    printf("\n[ALTURA]: %10.2f m",papagaio.getALTURA());
    printf("\n[IMC]:    %10.2f",papagaio.getIMC());
    printf("\n[D_OVO]:  %10.2f cm",papagaio.getDIAMETROOVO());
    
    printf("\n\nOBRIGADO POR UTILIZAR UM SOFTWARE TABAJARA");  
    return 0;
}
