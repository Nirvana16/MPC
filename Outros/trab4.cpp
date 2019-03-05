#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int ordem; 
    int i, j, k;
    float preenche;
    float matriz_A**, matriz_R**, matriz_R_Trans**;
    float *b, *x,*y;
    float soma1=0, soma2=0;
    
    printf("Ordem da matriz principal: ");
	scanf("%d", &ordem);
	

	//Vetor de ponteiros para as linhas da matriz.
	matriz_A = (float **) malloc(ordem * sizeof(float *));
    matriz_R = (float **) malloc(ordem * sizeof(float *));  
    matriz_R_Trans = (float **) malloc(ordem * sizeof(float *));
    
    b =(float*) malloc(ordem * sizeof(float));
    x =(float*) malloc(ordem * sizeof(float));
    y =(float*) malloc(ordem * sizeof(float));
    
    
    //Aponta para cada linha.
	for( i=0 ; i<ordem ; i++ )
    {
		matriz_A[i] = (float *) malloc(ordem * sizeof(float));	
		matriz_R[i] = (float *) malloc(ordem * sizeof(float));
		matriz_R_Trans[i] = (float *) malloc(ordem * sizeof(float));
	}
    
 //- - - - - - - - - - - - - - - - - - - - - - - - - -
 
 
    printf("\n\n******** Matriz A ********\n\n");
    for(i=0 ; i<ordem ; i++)
    {
        for(j=0 ; j<ordem ; j++)
        {
                //Somando sempre +1, pois na matriz começa por [0][0].
				printf("Pos. %d|%d: ", i+1, j+1);
				scanf("%f", &preenche);
				matriz_A[i][j] = preenche;
		}
	}
	printf("\n\n");
	
	
	//Pedindo os elementos do Vetor!
     printf("******** Vetor B ********");	
     for( i=0 ; i<ordem ; i++ )
     {
		printf("\nDigite o valor da posicao %d|%d do vetor: ", i+1,1);	
		scanf("%f", &preenche);
		b[i] = preenche;
    }
    
//- - - - - - - - - - - - - - - - - - - - - - - - - -
    
    for(i=0 ; i<ordem ; i++)
    {
		for(j=i+1 ; j<ordem ; j++)
        {
            for (k=0; k <= i-1; k++)
            {
            //Achar os elementos da diagonal principal... R^2!
            soma1 += matriz_R[k][i] * matriz_R[k][i]
            soma2 += matriz_R[k][i] * matriz_R[k][j]
            }
        matriz_R[i][i] = ((sqrt(matriz_A[i][i])) - soma1;
        matriz_R[i][j] = (matriz_A[i][j] - soma2) / matriz_R[i][j];
        } 
    }
    
    
    
    for(i=0 ; i<ordem ; i++)
    {
		for(j=0 ; j<ordem ; j++)
		{
            matriz_R_Trans[i][j] = matriz_R[j][i];
            
            if (matriz_R_Trans[i][j] = matriz_R[i][j])
            {
            exit(0);
            }
        }
    }
    
    
    
    
    
    
    
    
}//Fim do main!
