// Importacao de bibliotecas
#include<stdio.h>
#include<conio.h>

void cola (void) {
//	float MatA[3][3] = {3,2,4},
//                     {1,1,2},
//                     {4,3,-2};
//	float MatL[3][3] = {1,0,0},
//                     {0,1,0},
//                     {0,0,1};
//	float MatU[3][3] = {0,0,0},
//                     {0,0,0},
//                     {0,0,0};
//	float MatB[3] = {1,2,3};
//	float MatY[3];
//	float MatX[3];}
}





int main (void){
// Variaveis locais de Apoio

    int i, j, k;// I,J e K são variaveis de apoio do FOR, como usamos 3 FOR, um dentro do outro
                // Necessitamos de 3 variavies
	float Soma; // Dado a formula matematica "somatorio" utilizaremos uma varaivel Soma para armazenar
                // esse resultado
	int ordem;  // Ordem das Matrizes

// Firula ::::
    printf(" \n\n\n");
    printf(" ........:: MATEMATICA PARA COMPUCAO ::........ \n");
    printf(" ........::    Decomposicao em LU    ::........ \n");
    printf(" ........::      Danilo Azevedo      ::........ \n\n");



//Coleta da ordem da matriz
    printf("-> Informe a Ordem da Matriz (Quadrada): ");
	scanf("%d", &ordem);
	printf("\n\n");

//Variaveis locais para matrizes, recebendo a ordem
    float MatA[ordem][ordem], MatB[ordem], MatU[ordem][ordem], MatL[ordem][ordem];
    float MatY[ordem],MatX[ordem];



    printf("Matriz A :\n");// Coleta de dados para matriz A
    for(i=0 ; i<ordem ; i++){
        for(j=0 ; j<ordem ; j++){
            printf("Informe a Posicao [%d][%d]: ", i+1, j+1);
			scanf("%f", &MatA[i][j]);
        }
    }
    printf("Matriz B :\n");// Coleta para matriz B
    for(i=0 ; i<ordem ; i++){
        printf("Informe a Posicao [%d][1]: ", i+1);
		scanf("%f", &MatB[i]);
    }

//Alimentacao automatica da Matriz L preenchendo com ZERO e 1 na diagonal
    for (i=0; i<ordem; i++){
        for(j=0 ; j<ordem; j++){
            if (i==j){ // Quando a coluna for igual a linha MatL Ira receber valor 1
                MatL[i][j]=1;
            }
            else {
                MatL[i][j]=0;
            }
        }
    }
//Alimentacao automatica da Matriz U preenchendo com ZERO
    for (i=0; i<ordem; i++){
        for(j=0 ; j<ordem ; j++){
            MatU[i][j]=0;
        }
    }
//Calculos Termo generico de U e L:::::::::::::::::::::::::::::::
	for (i=0;i<ordem;i++){
        for (j=0;j<ordem;j++){
            Soma=0;
			if (i<=j){ //termo genérico de U
				for (k=0;k<i;k++){
					Soma+=MatL[i][k]*MatU[k][j];
				}
                MatU[i][j]=MatA[i][j]-Soma;
			}
			else{ // termo genérico de L
				for (k=0;k<j;k++){
					Soma+=MatL[i][k]*MatU[k][j];
				}
				MatL[i][j]=(MatA[i][j]-Soma)/MatU[j][j];
			}
		}
	}
//  calculos L*U*x=b >>>> L*y=b  na matriz inferior L
	MatY[0]=MatB[0]/MatL[0][0];
	for(i=0;i<ordem;i++){
		Soma=0;
		for(j=0;j<i;j++){
            Soma+=MatL[i][j]*MatY[j];
		}
		MatY[i]=(MatB[i]-Soma)/MatL[i][i];
	}
//  calculos,  U*x=y  na matriz superior U
	MatX[2]=MatY[2]/MatU[2][2];
	for(i=1;i>=0;i--){
		Soma=0;
		for(j=i+1;j<ordem;j++) {
			Soma+=MatU[i][j]*MatX[j];
		}
		MatX[i]=(MatY[i]-Soma)/MatU[i][i];
	}

// Impressao das matrizes finais:::::::::::::::::
    printf("\n Matriz A \n");
    for (i=0; i<ordem; i++){
        for (j=0; j<ordem; j++){
            printf("%.2f ",MatA[i][j]);
            if (j==(ordem-1)){ //usado para dar forma visual a matriz
               printf("\n");
            }
        }
    }
    printf("\n\n Matriz  L \n"); //Impressao da Matriz L
	for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            printf("%.2f ",MatL[i][j]);
            if(j==(ordem-1)) {
                printf("\n");
            }
        }
    }
	printf("\n Matriz U\n"); // Impressao da Matriz U
    for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            printf("%.2f ",MatU[i][j]);
            if(j==(ordem-1)){
                printf("\n");
            }
        }
    }
	printf("\n Matriz Y\n"); // Impressao da matriz Y
	for(i=0;i<ordem;i++){
    	printf(" %.2f \n",MatY[i]);
    }
	printf("Matriz X \n"); // Impressao da matriz x
	for(i=0;i<ordem;i++){
        printf(" %.2f \n",MatX[i]);
    }
    getch();
}
