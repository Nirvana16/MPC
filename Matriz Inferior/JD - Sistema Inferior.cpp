#include <stdio.h>
#include <stdlib.h> // Para Alocação dinamica!
#include<conio.h>


int main(){

	int i, j, ordem;
	float valor, somatorio=0;
	float **MatL;
	float *VetX, *VetB;

// Coleta de Dados:::::

	printf("-> Informe a Ordem da Matriz L (Quadrada): ");
	scanf("%d", &ordem);
	printf("\n\n");


//Vetor de ponteiros para as linhas da matriz, utilizando alocação dinamica ::::::

	MatL = (float **) malloc(ordem * sizeof(float *));
    VetX = (float *) malloc(ordem * sizeof(float));
    VetB = (float *) malloc(ordem * sizeof(float));


//Aponta para cada linha :::::::::::::::::::::
	for(i=0 ; i<ordem ; i++){
		MatL[i] = (float *) malloc(ordem * sizeof(float));
	}


	printf("Matriz 1 :\n");
    for(i=0 ; i<ordem ; i++){
        for(j=0 ; j<ordem ; j++){
			if(i>=j){
				printf("Informe a Posicao [%d][%d]: ", i+1, j+1);
				scanf("%f", &valor);
				MatL[i][j] = valor;
			}
            else{
                MatL[i][j] = 0;
            }
		}
	}


	printf("Matriz 2 \n");
	for(i=0 ; i<ordem ; i++){
		printf("Informe a Posicao: [%d][%d] ", i+1,1);
		scanf("%f", &valor);
		VetB[i] = valor;
	}
	printf("\n\n");

// Já foi a cabeça

//X1 = essa é mole! SEM O FOR MESMO,.
	VetX[0] = VetB[0]/(MatL[0][0]);


// X2 (Igual ao que foi posto no quadro) Ja foi usado a posicao 0 do vetor! iniciar com 1 se nao da merda:::::

	for(i=1 ; i<ordem ; i++){
		for(j=0 ; j<i ; j++){
			if(i>j){
				somatorio += (MatL[i][j] * VetX[j]);
			}
		}
		VetX[i] = (VetB[i] - somatorio)/MatL[i][i];
		somatorio = 0;
	}

//- - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - Acabou a pior  parte - - - - - - - - - - - -

	printf(".:: Resultado ::.\n");


	printf("\n VETOR X eh igual ::: \n");
	for(i=0 ; i<ordem ; i++){
		printf(".::|%.1f|::.\n", VetX[i]);
	}

	free(MatL);


	getch();

}
