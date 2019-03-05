#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

//exemplo em sala:
//Objetivo A * X = B
//int vet[3][3] = {3,2,4,1,1,2,4,3,-2};
//int b[3]={1,2,3};
//res x[3] = 1 , -1 , 1

void liberamem(float **p,int ordem)
{
     int i;
     for (i=0;i<ordem;i++)
     {
         free(p[i]);
     }
}

void cadmatriz(float **p,int ordem, char nome[10])
{
     int i,j;
     char test;
     bool teste;
     system("cls");
     printf("Iniciando captura da Matriz %s [%d][%d]\n",nome,ordem,ordem);
     for (i=0;i<ordem;i++)
     {
         for(j=0;j<ordem;j++)
         {
               
               printf("Digite o valor da matriz na posicao [%d][%d]:",i+1,j+1);
               scanf("%f",&p[i][j]);
              
               if ((i==j) && (p[i][j] == 0)) //valores para diagonal = zero
               {
                   do
                   {
                          teste=true;
                          printf("Voce inseriu um valor zero ao item da diagonal principal posicao[%d][%d]\n",i+1,j+1);
                          printf("Com isso fica impossivel realizar calculos a frente pois não pode acontecer divisao por zero.\n");
                          printf("Caso deseje corrigir esse valor digite (S) ou qq valor para finalizar o programa");
                          scanf("%c",&test);
                          if ((test == 'S') || (test == 's'))
                          {
                                printf("Digite o valor para pos[%d][%d]",i+1,j+1);
                                scanf("%f",&p[i][j]);
                                if (p[i][j] != 0)
                                {
                                       teste=false;
                                }
                          }
                          else
                          {
                                liberamem(p,ordem);
                                exit(EXIT_FAILURE);
                          }
                   }while(teste);
               }
         }
     }
}

float *alocarvetor(int ordem)
{
     float *vet;
     vet = (float *) malloc(ordem * sizeof(float));
     if (vet == NULL)
     {
            printf("Falhou em alocar o endereço");
            getch();
            exit(EXIT_FAILURE);
     }
     return vet;
}

void cadvet(float *m,int ordem, char nome[10])
{
      
      int i;
      system("cls");
      printf("Captura da matriz %s [%d][1]\n",nome,ordem); 
      for (i=0;i<ordem;i++)
      {
          printf("Digite o valor para B[%d][1]",i+1);
          scanf("%f",&m[i]);
      }
}

float **criamatriz(int ordem) //aloca a matriz na memoria
{
    float **vet;
    float calculo;
    float giga=9.31322574615479e-10;
    int i;
    system("cls");
    printf("Alocando a Matriz na memoria Aguarde...");
    vet = (float **) (malloc(ordem * sizeof(float*)));
    for(i=0;i<ordem;i++)
    {
        vet[i] = (float*) (malloc(ordem * sizeof(float*)));
        if (vet[i] == NULL)
        {
            printf("Falhou em alocar o endereco de Memoria\nAtual Valor: %d\n",i);
            printf("Maximo alocado foi: %d bytes\n",((ordem * sizeof(float*))*i));
            calculo = ((ordem * (sizeof(float*)))*i)* giga;
            printf("Aparentemente esse e o maximo que o sistema suporta: %.2fGB",calculo);
            getch();
            exit(EXIT_FAILURE);
        }
    }
    return vet;
}

void decomposicao(float **l,float **u,float **a,int ordem)
{
     float soma;
     int i,j,k;
     for(i=0; i< ordem; i++){
		for(j=0; j< ordem; j++){
			if(i<=j)
            {
                soma=0;
				for(k=0; k<i; k++)
                {	
					soma = soma + (l[i][k] * u[k][j]);
				}
				u[i][j] = a[i][j] - soma;
			}
			else
            {
				u[i][j] = 0;
			}
			
			
			if(i>j)
            {
                soma=0;
				for(k=0; k<j; k++)
                {
					soma = soma + (l[i][k] * u[k][j]);
				}
				l[i][j] = (1/u[j][j]) * (a[i][j] - soma);
			}
			else
            {
				if(i==j)
                {
					l[i][j] = 1;	
				}
				else
                {
					l[i][j] = 0;
				}
			}
		}	
	}
}

void impvet(float *m,int ordem,char nome[10])
{
     int i;
     printf("\nImprimindo matriz %s\n",nome);
     for(i=0;i<ordem;i++)
     {
          printf("| %.2f |\n",m[i]);
     }

}

bool simetrica(float **m,float **t,int ordem)
{
     //funcao que verifica se e transposta e ja cria uma transposta
     int i,j;
     for (i=0;i<ordem;i++)
     {
         for (j=0;j<ordem;j++)
         {
             t[j][i] = m[i][j];
             if (m[i][j] != m[j][i])
             {
                  return false;
             }
         }
     }
     return true;
}

void imprime(float **m,int ordem,char nome[10])
{
     int i;
     int j;
     printf("\nImprimindo matriz %s\n",nome);
     for(i=0;i<ordem;i++)
	 {
        printf("|");
		for (j=0;j<ordem;j++)
		{
			printf(" %.2f ",m[i][j]);
		}
		printf("|\n");
	 }
}

int menu() //menu apenas para capturar a ordem da matriz
{
     int ordem;
     system("cls");
     printf("Programa para calculo MatrizInferior\nBy Felipe Franzes\n\n");
     printf("Digite a ordem da matriz:");
     scanf("%d",&ordem);
     return ordem;
}

int main()
{
    //declarando os ponteiros paras as matrizes
    float **a;
    float **at;
    float **u;
    float **l;
    float *x;
    float *y;
    float *b;
    float soma;
    //tamanho da ordem da matriz
    int tam,i,j;
    tam=menu();
    //alocando matriz na memoria
    a=criamatriz(tam);
    at=criamatriz(tam);
    u=criamatriz(tam);
    l=criamatriz(tam);
    x=alocarvetor(tam);
    y=alocarvetor(tam);
    b=alocarvetor(tam);
    
    cadmatriz(a,tam,"A");
    cadvet(b,tam,"B");

    if (simetrica(a,at,tam))
    {
          //matriz simetrica
          printf("Matriz A simetrica");
          
    }
    else
    {
        printf("Matriz nao simetrica impossivel metodo de cholesky");
    }


    liberamem(a,tam);
    liberamem(u,tam);
    liberamem(l,tam);
    free(x);
    free(y);
    free(b);
    getch();
}
    
