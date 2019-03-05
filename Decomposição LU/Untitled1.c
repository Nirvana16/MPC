#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int main(){
	printf("MATRIZ TRIANGULAR INFERIOR\n");

	int i,j,Somatorio, ordem;

	printf("-> Informe a Ordem da Matriz L (Quadrada): ");
	scanf("%d", &ordem);
	printf("\n\n");

    float MatA[ordem][ordem];
	float VetB[ordem];
	float VetX[ordem];

	printf("Matriz 1 :\n");
    for(i=0 ; i<ordem ; i++){
        for(j=0 ; j<ordem ; j++){
			if(i>=j){
				printf("Informe a Posicao [%d][%d]: ", i+1, j+1);
				scanf("%f", &MatA[i][j]);

			}
            else{
                MatA[i][j] = 0;
            }
		}
	}

    printf("Matriz 2 \n");
	for(i=0 ; i<ordem ; i++){
		printf("Informe a Posicao: [%d][%d] ", i+1,1);
		scanf("%f", &VetB[i]);

	}
	printf("\n\n");

//Imprimindo a Matriz A :::::::::::::::::::::::::::::::::::::::::
	printf("MATRIZ A:\n\n");
	for(i=0;i<ordem;i++){
		for(j=0;j<ordem;j++){
			printf("%0.f ", MatA[i][j]);
		}
		printf("\n");
	}
	printf("\n");

// Imprimindo o Vetor B :::::::::::::::::::::::::::::::::::::::::
	printf("VETOR B:\n\n");
	for(i=0;i<3;i++){
		printf("%0.f\n", VetB[i]);
    }

	printf("\n");
// Calculo ::::::::::::::::::::::::::::::::::::::::::::::::::::::
	VetX[0] = VetB[0] / (MatA[0][0]);
	for(i=1;i<ordem;i++){
		for(j=1;j<ordem;j++){
            Somatorio=0;
            if(i>j){
			Somatorio+= (MatA[i][j] * VetB[j]);
            }
		}
	VetX[i] = (VetB[i] - Somatorio)  / MatA[i][i]; //VetX começa no 1 porque a posição 0 ja foi usado.
	}
	printf("\n");
// Imprimindo o Vetor  ::::::::::::::::::::::::::::::::::::::::

	printf("VETOR X:\n\n");
	for(i=0;i<ordem;i++){
		printf("%0.f\n", VetX[i]);
	}


 getch();
}
