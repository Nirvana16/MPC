#include<stdio.h>
#include<conio.h>


int main ()
{
    int i, j, r, soma = 0;
	int matrizA[3][3], matrizB[3][3], matrizC[3][3],  valor;

	printf(".... Produto de Matrizes .... \n\n");

// Matriz A.

	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("- Informe Elemento %dx%d da Matriz A: ", i+1, j+1);
			scanf("%d", &valor);
			matrizA[i][j] = valor;
		}
	}
	printf("\n");

// Matriz B
	for (i=0; i < 3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("- Informe Elemento %dx%d da Matriz B: ", i+1, j+1);
			scanf("%d", &valor);
			matrizB[i][j] = valor;
        }
    }
    printf("\n\n");


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

