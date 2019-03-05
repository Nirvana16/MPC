#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <locale.h> //Não funciona em Windows XP para baixo... Err...
				   //Serve para por acentos! \o/

int main()
{
    setlocale(LC_ALL, "Portuguese");

	//Declarando...
	int i, j, ordem;
	float **matrizL, *vetorX, *vetorB;
	float valor, somatorio=0;
	
	printf("- - - - - Matriz Triangular Superior - - - - -\n\n");
	printf("Por: Matheus Manhães Tavares \n");
	printf("Professor: Arialdo \n");
	printf("Instituto Federal Fluminense - IFF \n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - -\n\n");

//- - - - - - - - - - - - - - - - - - - - - - - - - -


	printf("-> Ordem da Matriz L: ");
	scanf("%d", &ordem);
	printf("\n\n");
	

	//Vetor de ponteiros para as linhas da matriz.
	matrizL = (float **) malloc(ordem * sizeof(float *));
    vetorX = (float *) malloc(ordem * sizeof(float));     
    vetorB = (float *) malloc(ordem * sizeof(float));
 

	//Aponta para cada linha.
	for(i=0 ; i<ordem ; i++)
    {
		matrizL[i] = (float *) malloc(ordem * sizeof(float));	
	}


//- - - - - - - - - - - - - - - - - - - - - - - - - -

	printf(".... Preenchendo .... \n\n");

	printf(": Matriz 1 :\n\n");
    for(i=0 ; i<ordem ; i++)
    {
        for(j=0 ; j<ordem ; j++)
        {
            //"If" para ignorar as posições que valem 0.
			if(i<=j)
            {
                //Somando sempre +1, pois na matriz começa por [0][0].
				printf("- Pos. %dx%d: ", i+1, j+1);
				scanf("%f", &valor);
				matrizL[i][j] = valor;
			}
			
            else
            {//Automaticamente o valor na matriz é substituído por 0.
				matrizL[i][j] = 0;
            }
		}
	}


	printf("\n\n: Matriz 2 :\n\n");
	for(i=0 ; i<ordem ; i++)
    {
		printf("- Pos. %dx%d: ", i+1,1);	
		scanf("%f", &valor);
		vetorB[i] = valor;
	}
	printf("\n\n");
	

//- - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - Cálculo - - - - - - - - - - - - 


	//Calculando o "x3".
	vetorX[ordem-1] = vetorB[ordem-1]/(matrizL[ordem-1][ordem-1]);
	//Começa por baixo!
		

	//Calculando "x2/x1".
	//De baixo para cima!
	for( i=(ordem-2) ; i>=0 ; i--)
    {
		
		for(j=(ordem-1) ; j>=i ; j--)
        {
				somatorio += (matrizL[i][j] * vetorX[j]);			
		}
		vetorX[i] = (vetorB[i] - somatorio)/matrizL[i][i];
		somatorio = 0;
	}	
	

//- - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - Impressão - - - - - - - - - - - -

	printf(".... Resultado .... \n\n");

	//Imprime a matriz na tela.
	printf("Vetor X:\n");
	for(i=0 ; i<ordem ; i++)
    {
		printf("|%.1f|\n", vetorX[i]);
	}


	free(matrizL);


	getch();

}
