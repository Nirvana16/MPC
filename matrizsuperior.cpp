#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	system("color b9");
	printf("IFF - SISTEMA DE INFORMACAO - NOITE\n");
	printf("MATEMATICA PARA COMPUTACAO\n");
	printf("PROFESSOR: ARIALDO\n");
	printf("ALUNO:SEBASTIAO ALVES\n");
	printf("MATRIZ TRIAGULAR SUPERIOR\n");
	float A[3][3]={3,1,0,0,2,-1,0,0,3};
	float B[3]={4,2,0};
	float X[3];
	int i,j,soma,n=3;
	printf("MATRIZ A: \n\n");
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			printf(" %0.f "   , A[i][j]);
		}
		printf("\n");
		printf("\n");
	}
	printf("VETOR B:\n\n");
	for(i=0;i<n;i++){
		printf(" %0.f \n", B[i]);
	}
	printf("\n");
	X[n]=B[n] / A[n][n];
	for(i=(n-2);i>=0;i--){
		soma=0;
		  for(j=(n-1);j>=i;j--){
		  	soma +=(i+1) * A[i][j] * X[j];
	     	}
	X[i]=(B[i] - soma) / A[i][i];    	
	
	}
	printf("VETOR X:\n");
	for(i=0;i<n;i++){
		printf("%0.f\n", X[i]);
	}
	

getch();
}
