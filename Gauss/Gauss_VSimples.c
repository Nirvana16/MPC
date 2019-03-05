#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{

	float matrizA[3][3] = {3,0,1,3,2,1,-3,1,3};
	float matrizAB[3][4] = {{3,0,1,1},{3,2,1,1},{-3,1,3,3}};
	float vetorB[3];
	float vetorX[3];
	float soma = 0;
	int i, j, k;
	int m = 0, ordem = 3;
	
	
	for(i=0; i<=(ordem-1); i++)
	{
		for(j=0; j<=ordem; j++)
		{
			for(k=(i+1); k<=(ordem-1); k++)
			{
				m = matrizA[k][i]/matrizA[i][i];
                matrizAB[k][j] = matrizAB[k][j] - (matrizAB[i][j] * m); 
			}
		}
	}
	
	
	for (i=0; i<ordem; i++)
	{
		for(j=0; j<(ordem+1); j++)
		{
			if (j==ordem)
				vetorB[i] = matrizAB[i][j];
				
			else
				matrizA[i][j] = matrizAB[i][j];
		}
	}
	
	
	vetorX[ordem-1] = vetorB[ordem-1]/(matrizA[ordem-1][ordem-1]); 
	
	for(i=ordem-2 ; i>=0 ; i--)
	{
		for(j=(ordem-1) ; j>=i ; j--)
		{
			soma += (matrizA[i][j] * vetorX[j]);			
		}
		vetorX[i] = (vetorB[i] - soma)/matrizA[i][i];
		soma = 0;
	}	
	
	
	printf("Matriz multiplicadora:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		printf("|%.1f| ", vetorX[i]);
	}


	getch();		

}
