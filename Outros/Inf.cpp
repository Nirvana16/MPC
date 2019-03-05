#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	printf("MATRIZ TRIANGULAR INFERIOR\n");
	float MatA[3][3]={2,0,0,1,4,0,1,1,1};
	float B[3]={2,-3,1};
	float X[3];
	int i,j,soma;


	printf("MATRIZ A:\n\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%0.f ", MatA[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("VETOR B:\n\n");
	for(i=0;i<3;i++){
		printf("%0.f\n", B[i]);
    }

	printf("\n");

	X[0] = B[0] / (MatA[0][0]);
	for(i=1;i<3;i++){
		for(j=1;j<3;j++){
            if(i>j){
			soma+= (MatA[i][j] * X[j]);
            }
		}
	X[i] = (B[i] - soma)  / MatA[i][i];
	}
	printf("\n");
	printf("VETOR X:\n\n");
	for(i=0;i<3;i++){
		printf("%0.f\n", X[i]);
	}


 getch();
}
