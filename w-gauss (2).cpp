#include<stdio.h>
#include<conio.h>
#include<math.h>


int main(){
	
	int i,j,k;
	float A[3][3]={3,0,1,3,2,1,-3,1,3};
	float B[3]={1,1,3};
	float AB[3][4]={0};
	float X[3]={0};
	float pivo,m,soma;
	
	//IMPRIMINDO A
	printf("\n\n MATRIZ A");
	for(i=0;i<3;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf( " %.f",A[i][j]);
			
		}
	}
	//IMPRIMINDO B
	printf("\n\n MATRIZ B");

	for(i=0;i<3;i++){
		printf( "\n %.f",B[i]);
			
	}
	
	//JUNTANDO AS MATRIZES
	for(i=0;i<3;i++){
		AB[i][3] = B[i];//coloco o valor de B[i] na ultima coluna(3) e na linha i
		for(j=0;j<3;j++){
			AB[i][j] = A[i][j];
		}
	}

	//IMPRIMINDO MATRIZ AB
	printf("\n\n MATRIZ AB");
	for(i=0;i<3;i++){
		printf("\n");
		for(j=0;j<4;j++){
			printf( " %.f",AB[i][j]);
			
		}
	}
	
	//ESCALONAMENTO GAUSS
	for(i=0;i<3;i++){
		pivo=AB[i][i];
		for(j=i+1;j<3;j++){
			m=AB[j][i]/pivo;
			for (k=0;k<=3;k++){
				//if(AB[j][k]!= 0){//PRA NÃO CALCULAR O VALOR QUE FOI ZERADO ATERIORMENTE, mas acho q não é necessário
					AB[j][k]= AB[j][k] - (AB[i][k] * m);
				//}
			}
	
		}
	}
	
	printf("\n\n MATRIZ AB NOVA");
	for(i=0;i<3;i++){
		printf("\n");
		for(j=0;j<4;j++){
			printf( " %.f",AB[i][j]);
		
		}
	}
	
	//CALCULO DE X USANDO O CALCULO DE SISTEMA TRIANGULAR SUPERIOR
	//CONTRA C, CONTRA V
	
	X[2]=B[2]/A[2][2];
	for(i=1;i>-1;i--){
		soma=0;
		for(j=i+1;j<3;j++){
			soma += (A[i][j]*X[j]);
		}
		X[i]=(B[i]-soma)/A[i][i];
	}
	printf("\n\n X");
	for(i=0;i<3;i++){
		printf(" \n %.f",X[i]);
	}  
	
	
}
