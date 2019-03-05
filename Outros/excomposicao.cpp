#include<stdio.h>

main(){
	int matA[3][3] = {3,2,4,1,1,2,4,3,-2};
	float matL[3][3], matU[3][3], maty[3], soma, somatorio, matX[3], result[3]; 
	int matB[3] = {1,2,3};
	int i,j,k;

	for(i = 0; i<3;i++)
	{
		for(j = 0; j<3 ; j++)
		{
			soma= 0;
				
			if(i<=j)
			{
				#Da diagonal principal para cima!
				for(k=0 ; k<=(i-1) ;k++){
					soma += matL[i][k] * matU[k][j];
				}
				matU[i][j] = matA[i][j] - soma;				
			}
			
			#- - - - - - - - - - - - - - - - - - - - - - - -
			
			if(i==j)
			{
				#Diagonal principal.
				matL[i][j] = 1;
			}

			if(i<j)
			{
				#Da diagonal principal para cima!
				matL[i][j] = 0;
			}

			if(i>j)
			{
				#Da diagonal principal para baixo!
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
		printf(" %1f", matL[i][j]);
		}	printf("\n");		
	}
	printf("Matriz U:\n");
	for(i = 0; i<3;i++){
		for(j = 0; j<3 ; j++){
			printf(" %1f", matU[i][j]);
		}		
	printf("\n");
	}
	
		
	maty[0]= matB[0]/ matL[0][0];
    /*printf("%.1f", maty[0]);*/
    
/* Matriz inferior, achar o valor de Y*/

 for(i=0;i<3;i++){
	somatorio = 0;
	for(j=0;j<=i-1;j++){
	somatorio += (matL[i][j]* maty[j]);
	}
	maty[i] = (matB[i] - somatorio)/ matL[i][i];
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
