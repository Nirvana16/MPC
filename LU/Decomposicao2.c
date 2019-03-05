// Importacao de bibliotecas
#include<stdio.h>
#include<conio.h>


// Comeco da Funcao principal
int main (){
// Variaveis locais de Apoio

    int i, j, k;// I,J e K são variaveis de apoio do FOR, como usamos 3 FOR, um dentro do outro
                // Necessitamos de 3 variavies

	float Soma; // Dado a formula matematica "somatorio" utilizaremos uma varaivel Soma para armazenar
                // esse resultado

	int ordem;  // Ordem das Matrizes

//Coleta da ordem da matriz
    printf("-> Informe a Ordem da Matriz (Quadrada): ");
	scanf("%d", &ordem);
	printf("\n\n");

//Variaveis locais para matrizes, recebendo a ordem
    float MatA[ordem][ordem], MatB[ordem], MatU[ordem][ordem], MatL[ordem][ordem];
    float MatY[ordem],MatX[ordem];

// Para alocação Estatica da Matriz usar os valores abaixo, descomentando este bloco
{
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


//Alimentacao automatica da Matriz L preenchendo com ZERO e 1 na diagonal
    for (i=0; i<ordem; i++){
        for(j=0 ; j<ordem; j++){
            if (i==j){ // Quando a coluna for igual a linha MatL Ira receber valor 1
                MatL[i][j]=1;
            }
            else {
                MatL[i][j]=0;
            }//fecha else
        }// fecha for 2
    }//fecha for 1

//Alimentacao automatica da Matriz U preenchendo com ZERO
    for (i=0; i<ordem; i++){
        for(j=0 ; j<ordem ; j++){
            MatU[i][j]=0;
        }
    }

// Coleta de dados para matriz A
    printf("Matriz A :\n");
    for(i=0 ; i<ordem ; i++){
        for(j=0 ; j<ordem ; j++){
            printf("Informe a Posicao [%d][%d]: \n", i+1, j+1);
			scanf("%f", &MatA[i][j]);
			system("cls");

        }
        for(i=0;i<ordem;i++){
            for(j=0;j<ordem;j++){
                printf("%.2f ",MatA[i][j]);
                if(j==2){
                printf("\n");
                }
            }
        }
    }
// Coleta para matriz B
    printf("Matriz B :\n");
    for(i=0 ; i<ordem ; i++){
        printf("Informe a Posicao [%d][1]: ", i+1);
		scanf("%f", &MatB[i]);
    }

// Inicio dos calculos:::::::::::::::::::::::::::::::
	for (i=0;i<ordem;i++){
        for (j=0;j<ordem;j++){
            Soma=0;
// Cálculo do termo genérico de U
			if (i<=j){
				for (k=0;k<i;k++){
					Soma+=MatL[i][k]*MatU[k][j];
				}
                MatU[i][j]=MatA[i][j]-Soma;
			}
// Cálculo do termo genérico de L
			else{
				for (k=0;k<j;k++){
					Soma+=MatL[i][k]*MatU[k][j];
				}
				MatL[i][j]=(MatA[i][j]-Soma)/MatU[j][j];
			} // Fecha Else
		} // Fecha segundo for
	} // Fecha primeiro for



//Impressao da Matriz L ::::::::::::::::::::::
    printf("\n\n Matriz  L \n");
	for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            printf("%.2f ",MatL[i][j]);
            if(j==2) {
                printf("\n");
            }
        }
    }

// Impressao da Matriz U :::::::::::::::::::::::
	printf("\n Matriz U\n");
    for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            printf("%.2f ",MatU[i][j]);
            if(j==2){
                printf("\n");
            }
        }
    }


// Continuaçao dos calculos ::::::::::::::::
// L*U*x=b >>>> L*y=b Baseado na matriz inferior "L"
	MatY[0]=MatB[0]/MatL[0][0];
	for(i=0;i<ordem;i++){
		Soma=0;
		for(j=0;j<i;j++){
            Soma+=MatL[i][j]*MatY[j];
		}
		MatY[i]=(MatB[i]-Soma)/MatL[i][i];

	}
// Impressao da matriz Y
	printf("\n Matriz Y\n");
	for(i=0;i<ordem;i++){
    	printf(" %.2f",MatY[i]);
		printf("\n");
    }

// Continuaçao dos calculos ::::::::::::::::
// U*x=y Baseado na matriz superior "U"
	MatX[2]=MatY[2]/MatU[2][2];
	for(i=1;i>=0;i--){
		Soma=0;

		for(j=i+1;j<ordem;j++)
			Soma+=MatU[i][j]*MatX[j];

		MatX[i]=(MatY[i]-Soma)/MatU[i][i];
	}
// Impressao da matriz x
	printf("Matriz X\n");
	for(i=0;i<ordem;i++){
        printf(" %.2f \n",MatX[i]);
    }
    getch();
}
