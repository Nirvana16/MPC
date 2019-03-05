#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	printf("MATRIZ TRIAGULAR SUPERIOR\n");

//	int i,j,somatorio=0,ordem=3;
//	float MatA[3][3]={3,1,0,0,2,-1,0,0,3};
//	float VetB[3]={4,2,0};
//	float X[3];

// [PARA EXECUÇÃO SEM ALOCAÇAO DINAMICA DESCOMENTAR ACIMA E COMENTAR TODO O BLOCO ABAIXO]
	int i,j,somatorio, ordem;

	printf("-> Informe a Ordem da Matriz L (Quadrada): "); // Solicitamos a Ordem ao usuario para que seja possivel colocar na matriz
	scanf("%d", &ordem);
	printf("\n\n");

    float MatA[ordem][ordem]; //Variavel matriz e vetor recebem a ordem digitada acima
	float VetB[ordem];
	float X[ordem];

//Coletando a Matriz A ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	printf("Matriz A :\n");
    for(i=0 ; i<ordem ; i++){
        for(j=0 ; j<ordem ; j++){
			if(j>=i){ //Usado para que haja o a matriz inferior = 0 automaticamente
				printf("Informe a Posicao [%d][%d]: ", i+1, j+1);
				scanf("%f", &MatA[i][j]);

			}
            else{
                MatA[i][j] = 0; //Usado para que haja o a matriz inferior = 0 automaticamente
            }
		}
	}

//Coletando o VetorB ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    printf("Matriz 2 \n");
	for(i=0 ; i<ordem ; i++){
		printf("Informe a Posicao: [%d][%d] ", i+1,1);
		scanf("%f", &VetB[i]);

	}
	printf("\n\n");

// Imprimindo a Matriz A ::::::::::::::::::::::::::::::::::::::
	printf("MATRIZ A:\n\n");
	for(i=0;i<ordem;i++){
		for(j=0;j<3;j++){
			printf(" %0.f "   , MatA[i][j]);
		}
		printf("\n"); //Para pular uma linha e exibir a matriz esteticamente melhor
	}

// [PARA EXECUÇÃO SEM ALOCAÇAO DINAMICA COMENTAR O BLOCO ACIMA ]
// Imprimindo o Vetor B :::::::::::::::::::::::::::::::::::::::::
	printf("VETOR B:\n\n");
	for(i=0;i<ordem;i++){
		printf(" %0.f \n", VetB[i]);
	}
	printf("\n");

// Calculo ::::::::::::::::::::::::::::::::::::::::::::::::::::::

    X[ordem-1] = VetB[ordem-1]/(MatA[ordem-1][ordem-1]); //Calculo de X3
    for(i=(ordem-1);i>=0;i--){
        somatorio=0;
		for (j=(ordem-1);j>i;j--){
            somatorio+=((MatA[i][j])*X[j]);
		}
		X[i]=(((VetB[i])-somatorio)/MatA[i][i]);
	 }

// Imprimindo o Vetor  ::::::::::::::::::::::::::::::::::::::::

	printf("VETOR X:\n");
	for(i=0;i<ordem;i++){
		printf("%0.f\n", X[i]);
	}


getch();
}
