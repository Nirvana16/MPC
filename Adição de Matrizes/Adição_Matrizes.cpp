#include<stdio.h>
#include<conio.h>

int main()
{

	int i, j;
	int matrizA[2][2], matrizB[2][2], matrizC[2][2],  valor;

	printf("- - - - - Soma de Matrizes - - - - - \n\n");
	printf("Exercicio 1 \n");
	printf("Professor: Arialdo \n");
	printf("- - - - - - - - - - - - - - - - - - -\n\n");

 //- - - - - - - - - - - - - - - - - - - - - - - - - -

	printf(".... Insira dos dados  .... \n\n");

	//Preenchendo a Matriz A.
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("- Elemento %dx%d da Matriz A: ", i+1, j+1);
			scanf("%d", &valor);
			matrizA[i][j] = valor;
		}
	}
	printf("\n");

	//Preenchendo a Matriz B.
	for(i=0;i<2;i++)
	{
		for(j=0; j<2; j++)
		{
			printf("- Elemento %dx%d da Matriz B: ", i+1, j+1);
			scanf("%d", &valor);
			matrizB[i][j] = valor;
		}
	}
	printf("\n\n");

 //- - - - - - - - - - - - - - - - - - - - - - - - - -
 //- - - - - - - - - - Cálculo - - - - - - - - - - - -

	//Somando as duas matrizes.
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
		}
	}

 //- - - - - - - - - - - - - - - - - - - - - - - - - -
 //- - - - - - - - - Impressão - - - - - - - - - - - -

	printf(".... Resultado .... \n\n");

	printf("Matriz A:\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%|%d| ", matrizA[i][j]);
		}
		printf("\n"); //Pular de linha.
	}
	printf("\n");


	printf("Matriz B:\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%|%d| ", matrizB[i][j]);
		}
		printf("\n"); //Pular de linha.
	}
	printf("\n");


	printf("Matriz C:\n");
	for(i=0;i<2;i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%|%d| ", matrizC[i][j]);
		}
		printf("\n"); //Pular de linha.
	}


	getch();

}
