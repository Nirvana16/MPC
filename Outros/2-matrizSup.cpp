#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

//exemplo em sala:
//int vet[3][3] = {3,1,0,0,2,-1,0,0,3};
//int b[3]={4,2,0};
//res x[3] = 1 , 1 , 0

void liberamem(float **p,int ordem)
{
     int i;
     for (i=0;i<ordem;i++)
     {
         free(p[i]);
     }
}

void cadmatrizb(float *b,int ordem)
{
    int i;
    system("cls");
    printf("Captura da matriz B[%d][1]\n",ordem); 
    for (i=0;i<ordem;i++)
    {
        printf("Digite o valor para B[%d][1]",i+1);
        scanf("%f",&b[i]);
    }
}

void cadmatriz(float **p,int ordem)
{
     int i,j;
     char test;
     bool teste;
     system("cls");
     printf("Iniciando captura da Matriz[%d][%d]\n",ordem,ordem);
     for (i=0;i<ordem;i++)
     {
         for(j=0;j<ordem;j++)
         {
               if (i <= j) //numeros acima e a propria diagonal principal
               {
                   printf("Digite o valor da matriz na posicao [%d][%d]:",i+1,j+1);
                   scanf("%f",&p[i][j]);
               }
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
               if (i>j) //valor abaixo da diagonal que são zeros
               {
                       p[i][j]=0;
               }
         }
     }
}

float *alocarvets(int ordem)
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

void calculo(float **v,float *b,float *x,int ordem)
{
     float soma;
     int i;
     int j;
     for(i=(ordem-1);i>=0;i--)
	 {
		soma=0;
		for (j=(ordem-1);j>i;j--)
		{
			soma+=((v[i][j])*x[j]);
		}
		x[i]=(((b[i])-soma)/v[i][i]);
	 }
}

void imprimeres(float **v,float *b,float *x,int ordem)
{
     int i;
     int j;
     system("cls");
     printf("Imprimindo resultados\n");
     printf("Matriz [%d][%d]    *     X[1][%d]    =      B[1][%d]\n",ordem,ordem,ordem,ordem);
     for(i=0;i<ordem;i++)
	 {
        printf("|");
		for (j=0;j<ordem;j++)
		{
			printf(" %.2f ",v[i][j]);
		}
		printf("| * | %.2f | = | %.2f |\n",x[i],b[i]);
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
    float **v;
    float *x;
    float *b;
    int tam,;
    tam=menu();
    x=alocarvets(tam);
    b=alocarvets(tam);
    v=criamatriz(tam);
    cadmatriz(v,tam);
    cadmatrizb(b,tam);
    calculo(v,b,x,tam);
    imprimeres(v,b,x,tam);
    liberamem(v,tam);
    getch();
}
    
