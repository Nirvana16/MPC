#include<stdio.h>
#include <stdlib.h>

main(){
	float **matL, **matU, **matA, *result, *maty, *matX, preenche, soma=0, somatorio;
	int i, j, k, v, ordem;
	
	
	// alocar a matriz dinamicamente
	matA=(float**)malloc (ordem * sizeof(float*)); // ponteiro de ponteiro
	matL=(float**)malloc (ordem * sizeof(float*));
	matU=(float**)malloc (ordem * sizeof(float*));
	matX=(float*)malloc (ordem * sizeof(float));
	maty=(float*) malloc (ordem * sizeof(float));
	result=(float*) malloc (ordem * sizeof(float));
	
	//para fazer o vetor apontar para cada linha da matriz,alocando-a.
	for(i=0;i< ordem; i++){
		matA[i]= (float*)malloc (ordem * sizeof(float)); 
    }
    for(i=0;i< ordem; i++){
		matL[i]= (float*)malloc (ordem * sizeof(float)); 
    }
    for(i=0;i< ordem; i++){
		matU[i]= (float*)malloc (ordem * sizeof(float)); 
    }
    
    
    	//Preenche matriz a
	printf("\n*** Matriz A ***\n\n");
	for( i=0 ; i<ordem ; i++ ){
		for( j=0 ; j<ordem ; j++){
			printf("Posicao %d %d: ", i+1,j+1);
 			scanf("%f", &preenche);
 			matA[i][j] = preenche;
		}
	}
	
	//Preenche vetor b
	printf("\n*** Matriz b ***\n\n");
	for( i=0 ; i<ordem ; i++ ){
		printf("Posicao %d %d: ", i+1, 1);
		scanf("%f", &preenche);
		result[i] = preenche;
	}
	

	for(i = 0; i<3;i++)
	{
		for(j = 0; j<3 ; j++)
		{
			soma= 0;
				
			if(i<=j)
			{
				//Da diagonal principal para cima!
				for(k=0 ; k<=(i-1) ;k++){
					soma += matL[i][k] * matU[k][j];
				}
				matU[i][j] = matA[i][j] - soma;				
			}
			
			//- - - - - - - - - - - - - - - - - - - - - - - -
			
			if(i==j)
			{
				//Diagonal principal.
				matL[i][j] = 1;
			}

			if(i<j)
			{
				//Da diagonal principal para cima!
				matL[i][j] = 0;
			}

			if(i>j)
			{
				//Da diagonal principal para baixo!
				matU[i][j] = 0; 
				
				for(k=0; k<=(j-1); k++){                           
					soma+= matL[i][k] * matU[k][j];
				}
				matL[i][j] =  (matA[i][j] - soma)/(matU[j][j]);
			}
		}
	}
	printf("Matriz L:\n");
	for(i = 0; i<3;i++){
		for(j = 0; j<3 ; j++){			
		printf(" %.1f", matL[i][j]);
		}	printf("\n");		
	}
	printf("Matriz U:\n");
	for(i = 0; i<3;i++)
	{
		for(j = 0; j<3 ; j++){
			printf(" %.1f", matU[i][j]);
		}		
	printf("\n");
	}
	
		
	maty[0]= result[0]/ matL[0][0];
    /*printf("%.1f", maty[0]);*/
    
/* Matriz inferior, achar o valor de Y*/

 for(i=0;i<3;i++){
	somatorio = 0;
	for(j=0;j<=i-1;j++){
	somatorio += (matL[i][j]* maty[j]);
	}
	maty[i] = (result[i] - somatorio)/ matL[i][i];
}
  printf("\n%.1f %.1f %.1f\n", maty[0],maty[1],maty[2]);

/*Matriz superior, achar valor de X*/
  
  matX[2] = maty[2]/ matU[2][2];
/*  printf("%.1f",matC[2]);*/

for(i=1;i>=0;i--)
	{			
		somatorio = 0;
		for(j=(i+1);j<3;j++){		
				somatorio+=(matU[i][j]* matX[j]);			
		}
		matX[i]= (maty[i] - somatorio)/matU[i][i];			
	}	
	         printf("\n%.1f %.1f %.1f",matX[0],matX[1],matX[2]);

	getch();
   
}
