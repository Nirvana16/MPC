#include<conio.h> // Para poder usaar o Getch
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void main(void){
// Variaveis
	float  m, soma=0;
	int ordem, n;
	int i, j, k;

// Firula ::::
    printf(" \n\n\n");
    printf(" ........:: MATEMATICA PARA COMPUCAO ::........ \n");
    printf(" ........::       Metodo Gauss       ::........ \n");
    printf(" ........::      Danilo Azevedo      ::........ \n\n");

	printf("Insira a ordem da matriz principal: ");
	scanf("%d", &ordem);
	printf("\n\n");

    // Continua��o das Variavies, recebendo a ordem informada pelo usuario como ordem da matriz
	float matrizA[ordem][ordem];
	float Matriz_superior[ordem][ordem+1]; // Essa sera a matriz depois de feita o metodo de gauss
	float matriz_AB[ordem][ordem+1];       //Perceba que a matriz AB � a uni�o da Mat A com Mat Resultante
                                           // Desse momdo Mat AB tera sempre uma coluna ma mais que Mat A
                                           // Por isso usei Ordem + 1
    float vetX[ordem], matrizResultante[ordem];



//Preencher MatrizA - - - - - - - - - - - - - - - - - - - - - - - - - -
	for(i=0; i<ordem; i++) {
        for (j=0; j<ordem; j++){
			printf("Informe elemento %dx%d da Matriz Principal: ",i+1,j+1);
			scanf("%f", &matrizA[i][j]);
        }
    }
    printf("\n");

//Preencher Vetor B - - - - - - - - - - - - - - - - - - - - - - - - - -
    for(i=0; i<ordem; i++)
	{
		printf("Elemento %dx%d da Matriz Resultante: ",i+1,1);
		scanf("%f", &matrizResultante[i]);
    }

//- - - - - - - - - - - - - - - - - - - - - - - - - -
// Unindo Matriz A com Resultante para obtermos a Matriz AB

    for (i=0; i<ordem; i++)	{
		for(j=0; j<=ordem; j++)		{
			if (j==ordem)                               // Quando J(coluna) for igual a ordem
               matriz_AB[i][j] = matrizResultante[i];   // O elemento IJ da Matriz AB recebe o elemento I da Matriz Resultante
            else                                        // Quando a condi��o acima n�o for atendida
               matriz_AB[i][j] = matrizA[i][j];         // o Programa ira clonar os valores da matriz A
        }                                               // Para as Demais colunas e linhas
   }

// Clonando a matriz -------------------------------------------------
	for(i=0; i<ordem; i++){                              // Como n�o � uma matriz quadrada i tem de ser igual a ordem
        for(j=0; j<ordem+1;j++){                         // por�m J tem de ser igual a ordem+1, uma vez que matriz superior
    		Matriz_superior[i][j] = matriz_AB[i][j];    // tamb�m recebe uma coluna extra referente a matriz resultante
        }
	}


// Calculando Gauss - - - - - - - - - - - - - - - - - - - - - - - - - -



   for(i=0; i<=(ordem-1); i++) //Dado na f�rmula.
   {
      for(j=0; j<(ordem+1); j++) //Dado na f�rmula.
	  {
		  for(k=(i+1); k<ordem; k++) //Dado na f�rmula.
		  {
	          m = matrizA[k][i]/matrizA[i][i]; //Dado na f�rmula.
              matriz_AB[k][j] = matriz_AB[k][j] - (matriz_AB[i][j] * m); //Dado na f�rmula.
		 }
	 }
  }



	for (i=0; i<ordem; i++)
	{
			for(j=0; j<=ordem; j++)
			{
				if (j==ordem)
				   matrizResultante[i] = matriz_AB[i][j]; //Pegar a �ltima coluna e criar o Vetor!

	            else
	               matrizA[i][j] = matriz_AB[i][j]; //Resto, sem a �ltima coluna.
	        }
	}


	vetX[ordem-1] = matrizResultante[ordem-1]/(matrizA[ordem-1][ordem-1]);
	//Pega o �ltimo elemento do Vetor!

	for(i= ordem-2 ; i>=0 ; i--)
	{ //Agora a partir da pen�ltima linha....
		for(j=(ordem -1) ; j>=i ; j--)
		{
			soma += (matrizA[i][j] * vetX[j]);
		}
		vetX[i] = (matrizResultante[i] - soma)/matrizA[i][i];
		soma = 0;

		if(vetX[i] = -0)
		{//Tratamento de erro ao final, por sair 0 negativo!
			vetX[i] = 0;
		}
	}
// Imprimindo resultados

//Printar a Matriz AB --------------------------------------------------
	printf("\nMatriz AB\n");
	for(i=0; i<ordem; i++){
		for(j=0; j<ordem+1; j++)	{
			printf("|%.1f |",matriz_AB[i][j]);
		}
		printf("\n");
	}

//Printar a Trangular Superior --------------------------------------------------
	printf("\n Matriz Triangular Superior\n");
	for(i=0; i<ordem; i++){
		for(j=0; j<ordem+1; j++){
			printf("|%.1f |",Matriz_superior[i][j]);
		}
		printf("\n");
	}

// Printar Matriz Resultante -----------------------------------------------------
	printf("\nA Matriz Resultante �:\n");
	for(i=0 ; i<ordem ; i++ ){
		printf("|%.1f| \n ", matrizResultante[i]);
	}

// Printar Matriz multiplicadora -----------------------------------------------------
	printf("\nA Matriz multiplicadora �:\n");
	for(i=0 ; i<ordem ; i++ ){
		printf("|%.1f| \n ", vetX[i]);
	}

getch();

}

