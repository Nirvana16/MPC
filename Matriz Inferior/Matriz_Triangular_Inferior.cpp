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
	float valor, somatorio=0;
	float **matrizL;
	float *vetorX, *vetorB;
	
	printf("- - - - - Matriz Triangular Inferior - - - - - \n\n");
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
			if(i>=j)
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


	//Calculando o "x1".
	vetorX[0] = vetorB[0]/(matrizL[0][0]);
		

	//Calculando do "x2" adiante.
	for(i=1 ; i<ordem ; i++) //Começa no i=1 porque a primeira posição do vetor já foi!
    {
		for(j=0 ; j<i ; j++)
        {
			if(i>j) //Para que calcular as posições com i<j já que elas valem 0?
            {
				somatorio += (matrizL[i][j] * vetorX[j]);		
			}
		}
		vetorX[i] = (vetorB[i] - somatorio)/matrizL[i][i]; //OBS: Só tem "i".
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
