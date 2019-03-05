#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	printf("MATRIZ TRIANGULAR INFERIOR\n");
	float MatA[3][3]={3,0,0,4,5,0,6,7,8};
	float MatB[3]={5,-5,5};
	float VetX[3];
	int i,j,Somatorio;

// Imprimindo a Matriz A :::::::::::::::::::::::::::::::::::::::::
	printf("MATRIZ A:\n\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%0.f ", MatA[i][j]);
		}
		printf("\n");
	}
	printf("\n");

// Imprimindo o Vetor B :::::::::::::::::::::::::::::::::::::::::
	printf("VETOR B:\n\n");
	for(i=0;i<3;i++){
		printf("%0.f\n", MatB[i]);
    }

	printf("\n");
// Calculo ::::::::::::::::::::::::::::::::::::::::::::::::::::::
	VetX[0] = MatB[0] / (MatA[0][0]);
	for(i=1;i<3;i++){
		for(j=1;j<3;j++){
            Somatorio=0;
            if(i>j){
			Somatorio+= (MatA[i][j] * VetX[j]);
            }
		}
	VetX[i] = (MatB[i] - Somatorio)  / MatA[i][i]; //VetX começa no 1 porque a posição 0 ja foi usado.
	}
	printf("\n");
// Imprimindo o Vetor  ::::::::::::::::::::::::::::::::::::::::

	printf("VETOR X:\n\n");
	for(i=0;i<3;i++){
		printf("%0.f\n", VetX[i]);
	}


 getch();
}
