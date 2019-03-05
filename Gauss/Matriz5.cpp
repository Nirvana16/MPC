#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	float **matrizA, **matriz_AB;
	float *vetX, *matrizResultante;
	float  m, valor, elemento, soma=0;
	int ordem, n; 
	int i, j, k; 
	
	
	printf("Ordem da matriz principal: ");
	scanf("%d", &ordem);
	printf("\n\n");
	
	
	//Vetor de ponteiros para as linhas da matriz.
	matrizA= (float**)malloc (ordem* sizeof(float*));
	matriz_AB= (float**)malloc (ordem* sizeof(float*));
	vetX= (float*) malloc (ordem * sizeof(float));
	matrizResultante= (float*) malloc (ordem * sizeof(float));
	
	//Aponta para cada linha.
	for(i=0; i<ordem; i++)
	{
		matrizA[i]= (float*)malloc (ordem* sizeof(float)); 
   		matriz_AB[i]= (float*)malloc ((ordem+1) *sizeof(float)); 
    	 
    }
    
 //- - - - - - - - - - - - - - - - - - - - - - - - - -
    
    //Preencher MatrizA
	for(i=0; i<ordem; i++)
	{
        for (j=0; j<ordem; j++)
		{
			printf("Elemento %dx%d da Matriz Principal: ",i+1,j+1);
			scanf("%f", &elemento);
			matrizA[i][j] = elemento;
        }
    }
    printf("\n");
    
    //Preencher Vetor B
    for(i=0; i<ordem; i++)
	{
		printf("Elemento %dx%d da Matriz Resultante: ",i+1,1);	
		scanf("%f", &valor);	
		matrizResultante[i] = valor; 
    }
    
//- - - - - - - - - - - - - - - - - - - - - - - - - -
   
    
    for (i=0; i<ordem; i++)
	{
		for(j=0; j<=ordem; j++)
		{
			if (j==ordem)
               matriz_AB[i][j] = matrizResultante[i];
               
            else //Quando passar do valor "normal" da coluna, aqui ir� acrescentar outra coluna a partir do vetor!
               matriz_AB[i][j] = matrizA[i][j];  
        }
   }

	//Printar a Matriz AB
	printf("\nMatriz AB\n");
	for(i=0; i<ordem; i++)
	{
		for(j=0; j<=ordem; j++)
		{ 
			printf("|%.1f |",matriz_AB[i][j]);
		}
		printf("\n");
	}
	
//- - - - - - - - - - - - - - - - - - - - - - - - - -
   
   
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
	
	
	printf("\nA Matriz multiplicadora �:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		printf("|%.1f| ", vetX[i]);
	}



free(matrizA);	
free(matriz_AB);
free(matrizResultante);
free(vetX);


getch();

}
