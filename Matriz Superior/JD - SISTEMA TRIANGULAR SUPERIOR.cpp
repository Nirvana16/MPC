#include <stdio.h>
#include <stdlib.h> // Para Alocação dinamica!
#include<conio.h>

int main() {

	int i, j, ordem;
	float **MatL, *VetX, *VetB;
	float valor, somatorio=0;

// Coleta de Dados:::::

	printf("-> Informe a Ordem da Matriz L (Quadrada): ");
	scanf("%d", &ordem);
	printf("\n\n");

//Vetor de ponteiros para as linhas da matriz, utilizando alocação dinamica ::::::
	MatL = (float **) malloc(ordem * sizeof(float *));
    VetX = (float *) malloc(ordem * sizeof(float));
    VetB = (float *) malloc(ordem * sizeof(float));


	for(i=0 ; i<ordem ; i++)
    {
		MatL[i] = (float *) malloc(ordem * sizeof(float));
	}


//- - - - - - - - - - - - - - - - - - - - - - - - - -

	printf(".... Preenchendo .... \n\n");

	printf(": Matriz 1 :\n\n");
    for(i=0 ; i<ordem ; i++){
        for(j=0 ; j<ordem ; j++){
            if(i<=j) {
               	printf("- Pos. %dx%d: ", i+1, j+1);
				scanf("%f", &valor);
				MatL[i][j] = valor;
			}

            else{//Automaticamente o valor na matriz é substituído por 0.
				MatL[i][j] = 0;
            }
		}
	}


	printf("\n\n: Matriz 2 :\n\n");
	for(i=0 ; i<ordem ; i++) {
		printf("- Pos. %dx%d: ", i+1,1);
		scanf("%f", &valor);
		VetB[i] = valor;
	}
	printf("\n\n");



//- - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - Cálculo - - - - - - - - - - - -


	//Calculando o "x3".
	VetX[ordem-1] = VetB[ordem-1]/(MatL[ordem-1][ordem-1]);
	//Começa por baixo!


	//Calculando "x2/x1".
	//De baixo para cima!
	for( i=(ordem-2) ; i>=0 ; i--){
		for(j=(ordem-1) ; j>=i ; j--){
            somatorio += (MatL[i][j] * VetX[j]);
		}
		VetX[i] = (VetB[i] - somatorio)/MatL[i][i];
		somatorio = 0;
	}


//- - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - Impressão - - - - - - - - - - - -

	printf(".... Resultado .... \n\n");

	//Imprime a matriz na tela.
	printf("Vetor X:\n");
	for(i=0 ; i<ordem ; i++){
		printf("|%.1f|\n", VetX[i]);
	}
	free(MatL);
	getch();

}
