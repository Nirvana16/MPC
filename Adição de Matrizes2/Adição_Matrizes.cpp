#include<stdio.h>
#include<conio.h>
#include <locale.h>//N�o funciona em Windows XP para baixo... Err...
				   //Serve para por acentos! \o/

main()
{	
	setlocale(LC_ALL, "Portuguese");
	
	//Declarando...
	int i, j;
	int matrizA[2][2], matrizB[2][2], matrizC[2][2],  valor;
	
	printf("- - - - - Soma de Matrizes - - - - - \n\n");
	printf("Por: Matheus Manh�es Tavares \n");
	printf("Professor: Arialdo \n");
	printf("Instituto Federal Fluminense - IFF \n\n");
	printf("- - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - -\n\n");
	
 //- - - - - - - - - - - - - - - - - - - - - - - - - -
	
	printf(".... Preenchendo .... \n\n");
	
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
 //- - - - - - - - - - C�lculo - - - - - - - - - - - - 
 
	//Somando as duas matrizes.
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)	
		{
			matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
		}
	}
	
 //- - - - - - - - - - - - - - - - - - - - - - - - - -
 //- - - - - - - - - Impress�o - - - - - - - - - - - -
	
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
