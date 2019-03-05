#include<conio.h> // Para poder usaar o Getch
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void main(void){
// Variaveis
	float  m, soma=0;
	int ordem;
	int i, j, k;

// Firula ::::
    printf(" \n\n\n");
    printf(" ........:: MATEMATICA PARA COMPUCAO ::........ \n");
    printf(" ........::       Metodo Gauss       ::........ \n");
    printf(" ........::      Danilo Azevedo      ::........ \n\n");

	printf("\n\nInsira a ordem da matriz principal: ");
	scanf("%d", &ordem);
	printf("\n\n");

// Continuação das Variavies, recebendo a ordem informada pelo usuario como ordem da matriz
	float matrizA[ordem][ordem];
	float Matriz_superior[ordem][ordem+1];      // Essa sera a matriz depois de feita o metodo de gauss
	float matriz_AB[ordem][ordem+1];            //Perceba que a matriz AB é a união da Mat A com Mat Resultante
                                                // Desse momdo Mat AB tera sempre uma coluna ma mais que Mat A
                                                // Por isso usei Ordem + 1
    float vetX[ordem], matrizResultante[ordem], matrizResultanteGauss[ordem];



//Preencher MatrizA - - - - - - - - - - - - - - - - - - - - - - - - - -
	for(i=0; i<ordem; i++) {
        for (j=0; j<ordem; j++){
			printf("Informe elemento %dx%d da Matriz Principal: ",i+1,j+1);
			scanf("%f", &matrizA[i][j]);
        }
    }
    printf("\n");

//Preencher Vetor B - - - - - - - - - - - - - - - - - - - - - - - - - -
    for(i=0; i<ordem; i++){
		printf("Elemento %dx%d da Matriz Resultante: ",i+1,1);
		scanf("%f", &matrizResultante[i]);
    }

// Unindo Matriz A com Resultante para obtermos a Matriz AB - - - - - - - - - - - - - - - - - - - -

    for (i=0; i<ordem; i++){
		for(j=0; j<=ordem; j++){
			if (j==ordem)                               // Quando J(coluna) for igual a ordem
               matriz_AB[i][j] = matrizResultante[i];   // O elemento IJ da Matriz AB recebe o elemento I da Matriz Resultante
            else                                        // Quando a condição acima não for atendida
               matriz_AB[i][j] = matrizA[i][j];         // o Programa ira clonar os valores da matriz A
        }                                               // Para as Demais colunas e linhas
   }

// Clonando a matriz -------------------------------------------------
	for(i=0; i<ordem; i++){                              // Como não é uma matriz quadrada i tem de ser igual a ordem
        for(j=0; j<ordem+1;j++){                         // porém J tem de ser igual a ordem+1, uma vez que matriz superior
    		Matriz_superior[i][j] = matriz_AB[i][j];     // também recebe uma coluna extra referente a matriz resultante
        }
	}

// Calculando Gauss - - - - - - - - - - - - - - - - - - - - - - - - - -
    for(i=0; i<ordem; i++){                           //
        for(j=i+1; j<ordem; j++){                         //
            m=(Matriz_superior[j][i]/matriz_AB[i][i]);    // matriz_AB[i][i] exerce a função do pivo
            for(k=0; k<ordem+1; k++){                     //
                Matriz_superior[j][k]= (Matriz_superior[j][k] - (Matriz_superior[i][k]*m));
            }
        }
    }

// Passar os valores escalonados da  Matriz Resultantes para outra indivudualmente
    for (i=0; i< ordem; i++){
        matrizResultanteGauss[i] = Matriz_superior[i][ordem];
    }



// Calculando SISTEMA TRIANGULAR --------------------------------------------
    vetX[ordem-1]=matrizResultanteGauss[ordem-1]/Matriz_superior[ordem-1][ordem-1]; // Veja que essa parte do codigo
    for(i=(ordem);i>0;i--){                                                      // eh a mesma do utilizando no sistema triangular
        soma=0;                                                                     //
        for (j=(ordem-1);j>i;j--){                                                  //
            soma+=((Matriz_superior[i][j])*vetX[j]);
		}
		vetX[i]=(((matrizResultanteGauss[i])-soma)/Matriz_superior[i][i]);
	 }


// Imprimindo resultados --------------------------------------------------
//Printar a Matriz A --------------------------------------------------
	printf("\nMatriz A\n");
	for(i=0; i<ordem; i++){
		for(j=0; j<ordem; j++)	{
			printf("|%.1f |",matrizA[i][j]);
		}
		printf("\n");
	}
// Printar Matriz Resultante -----------------------------------------------------
	printf("\nA Matriz Resultante Inicial e:\n");
	for(i=0 ; i<ordem ; i++ ){
		printf("|%.1f| \n", matrizResultante[i]);
	}

//Printar a Matriz AB --------------------------------------------------
	printf("\nMatriz AB\n");
	for(i=0; i<ordem; i++){
		for(j=0; j<ordem+1; j++)	{
			printf("|%.1f |",matriz_AB[i][j]);
		}
		printf("\n");
	}

//Printar a Trangular Superior --------------------------------------------------
	printf("\nMatriz Triangular Superior Equivalente a Matriz AB\n");
	for(i=0; i<ordem; i++){
		for(j=0; j<ordem+1; j++){
			printf("|%.1f |",Matriz_superior[i][j]);
		}
		printf("\n");
	}

// Printar Matriz Resultante -----------------------------------------------------
	printf("\nA Matriz Resultante Escalonada e:\n");
	for(i=0 ; i<ordem ; i++ ){
		printf("|%.1f| \n", matrizResultanteGauss[i]);
	}

// Printar Matriz multiplicadora -----------------------------------------------------
	printf("\nA Matriz multiplicadora e:\n");
	for(i=0 ; i<ordem ; i++ ){
		printf("|%.1f| \n", vetX[i]);
	}

getch();

}

