#include<stdio.h>
#include<conio.h>


int main ()
{
    int i, j, r, soma = 0;
	int matrizA[3][3]={1,2,1,4,1,3,2,1,1};
    int matrizB[3][3]={4,1,2,2,2,1,1,1,2};
    int matrizC[3][3];

	printf(".... Produto de Matrizes .... \n\n");

//- - - - - - - - - - Cálculo somatório das as duas matrizes.
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			soma = 0;
			for (r=0; r<3; r++)
			{
				soma+=(matrizA[i][r] * matrizB[r][j]);
			}
			matrizC[i][j] = soma;
		}
	}
//- - - - Impressão - - - - - - - - - - - -

	printf("Resultado  \n\n");

	printf("Matriz A:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%|%d| ", matrizA[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	printf("Matriz B:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%|%d| ", matrizB[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	printf("Matriz C:\n");
	for(i=0;i<3;i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%|%d| ", matrizC[i][j]);
		}
		printf("\n");
	}


	getch();

}

