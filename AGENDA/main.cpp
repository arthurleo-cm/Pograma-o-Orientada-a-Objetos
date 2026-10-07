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

/* ***********************************************************
    Desenvolver uma CLASSE para efetuar o gerenciamento de
    dados referente a CADASTROS de dados pessoais.
    Os atributos que deverão ser gerenciados sao:
        Nome (String)
        DDD (int)
        Celular (String)
    Implementar os seguintes metodos:
        Construtor
        setContato(...)
        setNome(...)
        getNome()
	    getDDD()
        setCelular(...)
	    setDDD(...)
        getCelular()
        getDDDCelular()
        @Override toString
        @Override equals
************************************************************ */

class CONTATO
{
    private: char Nome[1000];
    private: int ddd;
    private: char Celular[100];
    private: char aux[1000];
    
    public: CONTATO()
    {
        strcpy(Nome,"");
        ddd=-1;
        strcpy(Celular,"");
    };
    
    public: void setContato(char *n,int d,char *c)
    {
        strcpy(Nome,n);
        ddd=d;
        strcpy(Celular,c);
    };
    
    public: void setNome(char *n)
    {
        strcpy(Nome,n);
    };
    
    public: char *getNome()
    {
        return Nome;
    };
    
    public: int getDDD()
    {
        return ddd;
    };
    
    public: void setCelular(char *c)
    {
        strcpy(Celular,c);
    };
    
    public: void setDDD(int d)
    {
        ddd=d;
    };
    
    public: void setDDDCelular(int d,char *c)
    {
        ddd=d;
        strcpy(Celular,c);
    };
    
    public: char *getCelular()
    {
        return Celular;
    };
    
    public: char *getDDDCelular()
    {
        sprintf(aux,"(%03d) %s",ddd,Celular );
        return aux;
    };
    
};


class AGENDACONTATOS
{
    //DEFINIR O VETOR DE CONTATO
    private: CONTATO contatos[1000];
    private: int nReg=0;
    private: char buffer[1000];
    char nome[1000];
    char celular[1000];
    int ddd;
    //CONSTRUTOR
    public: AGENDACONTATOS()
    {
        nReg=0;
    };
     
    public: int getNumeroContatos()
    {
        return nReg;
    };
    
    public: void setContato(char *n,int d,char *c)
    {
        printf("\n\nNOME: %s",n);
            printf("\n (%03d) - %s",d,c);
        contatos[nReg].setContato(n,d,c);
        printf("\n\nNOME: %s",contatos[nReg].getNome());
            printf("\n (%03d) - %s",contatos[nReg].getDDD(),contatos[nReg].getCelular());
        nReg++;
    };
    
    public: void setAlterarContato(int pos,char *n,int d,char *c)
    {
        contatos[pos].setContato(n,d,c);
    };
    
    public: void setNome(int pos,char *n)
    {
        contatos[pos].setNome(n);
    };
    
    public: char *getNome(int pos)
    {
        return contatos[pos].getNome();
    };
    
    public: int getDDD(int pos)
    {
       return contatos[pos].getDDD();
    };
    
    public: void setCelular(int pos,int d,char *c)
    {
        contatos[pos].setDDDCelular(d,c);
    };
    
    public: char *getCelular(int pos)
    {
        return contatos[pos].getCelular();
    };
    
    public: char *getDDDCelular(int pos)
    {
        return contatos[pos].getDDDCelular();
    };
    
    public: int consultar(char *n)
    {
        char auxNome[1000];
        n[strlen(n)-1]='\0';
        for(int pos=0;pos<nReg;pos++)
        {
            strcpy(auxNome,contatos[pos].getNome());
            auxNome[strlen(auxNome)-1]='\0';
           // printf("\n\nNOME: %d  %s",strlen(auxNome),auxNome);
           // printf("\n (%03d) - %s",contatos[pos].getDDD(),contatos[pos].getCelular());
           // printf("\nCMP: %d  %d NOME: %s", strcmp(contatos[pos].getNome(),n),strlen(n),n);
          if( strcmp(auxNome,n)==0 )
             return pos;
        }
        
        return -1;
    };
    
    public: int consultar(int d,char *c)
    {
        for(int pos=0;pos<nReg;pos++)
        {
            printf("\n\nNOME: %s",contatos[pos].getNome());
            printf("\n (%03d) - %s",contatos[pos].getDDD(),contatos[pos].getCelular());
          if( (strcmp(contatos[pos].getCelular(),c)==0)&&(d==contatos[pos].getDDD()) )
             return pos;
        }
        
        return -1;
    };
    
    public: int arquivoGravarDados(char *nm)
    {
        //[1] DEFINIR PONTEIRO DO ARQUIVO
        FILE *arq;

        //[2] ABRIR ARQUIVO PARA ESCRITA
        arq=fopen(nm,"wt");
        
        //[3] ESCREVER DADOS NO ARQUIVO
        for(int pos =0;pos<nReg;pos++)
        {
            //ESCREVER nome
            fprintf(arq,"%s\n",getNome(pos));
            //ESCREVER ddd
            fprintf(arq,"%d\n",getDDD(pos));
            //ESCREVER celular
            if(pos<nReg-1)
            fprintf(arq,"%s\n",getCelular(pos));
            else
            fprintf(arq,"%s",getCelular(pos));
        }
        
        //[4] FECHAR ARQUIVO
        fclose(arq);

        return nReg;
    };
    //LER DADOS DE UM ARQUIVO TXT
    public: int arquivoLerDados(char *nm)
    {
        char buffer[1000];
        
        //[1] DEFINIR PONTEIRO DO ARQUIVO
        FILE *arq;
        //[2] ABRIR ARQUIVO PARA LEITURA
        arq=fopen(nm,"rt");
        
        nReg=0;
        while (!feof(arq))
        {
            fgets(buffer,900,arq);
            buffer[strlen(buffer)-1]='\0';
            strcpy(nome,buffer);
            
            fgets(buffer,900,arq);
            //CONVERTER BUFFER PARA INTEIRO
            ddd=atoi(buffer);
            
            fgets(buffer,900,arq);
            buffer[strlen(buffer)-1]='\0';
            strcpy(celular,buffer);
            
            setContato(nome,ddd,celular);
            
            //nReg++;
        }
        //[4] FECHAR ARQUIVO
        fclose(arq);
        
        return nReg;
    }
    


};




int main()
{
    	AGENDACONTATOS agenda;
	    
        char opcao[10]={"S"};
        char confirmar='S';
        char aux[1000];
        char nomearquivo[1000] = "AGENDA.txt";
    	int nReg=0;
    	char nome[1000];
    	int ddd;
    	char celular[1000];
    	int auxPos;
	

	    while(opcao[0]!='0')
	    {
	        printf("\n\nSISTEMA DE AGENDA DE TELEFONE\n");
	        printf("\n1 - CADASTRAR CONTATO");
	        printf("\n2 - LISTAR CONTATOS");
	        printf("\n3 - CONSULTAR POR NOME");
	        printf("\n4 - CONSULTAR POR TELEFONE");
	        printf("\n5 - ALTERAR");
	        printf("\nW - SALVAR EM ARQUIVO");
	        printf("\nR - LER DADOS DO ARQUIVO");
	        printf("\n0 - SAIR");

	        printf("\n\nESCOLHA A SUA OPCAO: ");
            fgets(opcao,10,stdin); 
            
            //SAIR
            if(opcao[0]=='0')
            {
              printf("\n\nOBRIGADO POR UTILIZAR UM SOFTWARE TABAJARA");    
            }
            
            //CADASTRAR
            if(opcao[0]=='1')
            {
                printf("\n\nCADASTRAR");
             int pos = 0;
                //LER NOME
                printf("\nDIGITE O NOME: ");
               scanf("%s", nome);
               // LER ddd
               printf("\nDIGITE O DDD: ");
               scanf("%d", ddd);
              //  LER CELULAR
              printf("\nDIGITE O CELULAR: ");
              scanf("%s",celular);
                agenda.setContato(nome,ddd,celular);
            }
            
            //LISTAR
            if(opcao[0]=='2')
            {
                int numerocontatos=agenda.getNumeroContatos();
                int pos = 0;
                while(pos<numerocontatos)
                {
                    printf("\n\nNOME: %s",agenda.getNome(pos));
                    printf("\n(%03d) - %s",agenda.getDDD(pos),agenda.getCelular(pos));
                    pos++;
                }
                
            }
           
            //CONSULTAR NOME
            if(opcao[0]=='3')
            {
            //DIGITAR O NOME PROCURADO
            printf("\n\nDIGITAR O NOME PROCURADO: ");
            //scanf("%s",nome);
            fgets(nome,200,stdin);
            //getchar();
            //REMOVER \N
            //nome[strlen(nome)]='\0';
            printf("\n\nNOME: %s",nome);
            //CHAMAR O METODO CONSULTAR
            auxPos = agenda.consultar(nome);
            printf("\nPOS:  %d",auxPos);
            //VERIFICAR SE POSICAO>=0 IMPRIMIR DADOS
            if(auxPos >=0)
            {
                printf("\nNOME: %s",agenda.getNome(auxPos));
                printf("\n (%03d) - %s",agenda.getDDD(auxPos),agenda.getCelular(auxPos));
            }
            else
            {
                printf("\n\n NOME NAO CADASTRADO");
            }
            }
           
            //CONSULTAR CELULAR
            if(opcao[0]=='4')
            {
                printf("\n\nDIGITAR O CELULAR PROCURADO: ");
                printf("\nDIGITAR O DDD: ");
                scanf("%d",&ddd);
                printf("\nDIGITAR O CELULAR: ");
                scanf("%s",celular);
               //celular[strlen(celular) ]='\0';
               printf("\n (%03d) - %s",ddd,celular);
               // getchar();
        
                int pos =agenda.consultar(ddd,celular);
                if(pos >=0)
                {
                     printf("\nNOME: %s",agenda.getNome(pos));
                    printf("\n (%03d) - %s",agenda.getDDD(pos),agenda.getCelular(pos));
                }
                else
                {
                    printf("\n\n CELULAR NAO CADASTRADO");
                }
            }
            
            //ALTERAR
            if(opcao[0]=='5')
            {

            }
         
            //LER DADOS ARQUIVO
            if(opcao[0]=='R')
            {
                printf("\n\nABRIR ARQUIVO PARA LEITURA");
                agenda.arquivoLerDados(nomearquivo);
                printf("DADOS LIDOS COM SUCESSO");
            }
            
            //GRAVAR DADOS ARQUIVO
            if(opcao[0]=='W')
            {
                printf("\n\nABRIR ARQUIVO PARA ESCRITA");
                agenda.arquivoGravarDados(nomearquivo);
                printf("DADOS GRAVADOS COM SUCESSO");
            }
            
	    }
		
	
    return 0;
}
