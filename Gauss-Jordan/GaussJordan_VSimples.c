#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
	float matrizA[3][3];
	float matrizAB[3][4] = {{3,2,4,1},{1,1,2,2},{4,3,-2,3}};
	float vetorX[3];
	float pivo = 0, m = 0;
	int i, j, k; 
	int ordem = 3;
	
	
	for(i=0; i<ordem; i++)
	{
        pivo = matrizAB[i][i]; 

        for(j=0; j<=ordem; j++) 
		{                         
            matrizAB[i][j] = matrizAB[i][j] / pivo; 
        }                                                 

        for(k=0; k<ordem; k++)
        {
            if (i != k) 
            {
            	m = matrizAB[k][i]; 
                for(j=0; j<=ordem; j++)
                {
                    matrizAB[k][j] = matrizAB[k][j] - (matrizAB[i][j] * m);
                }										
                
            }

        }

    }
    
    
    for (i=0; i<ordem; i++)
	{
			for(j=0; j<=ordem; j++)
			{
				if (j==ordem)
				   vetorX[i] = matrizAB[i][j]; 
	               
	            else
	               matrizA[i][j] = matrizAB[i][j]; 
	        }
	}
	
	
	printf("A Matriz AB é:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		for(j=0 ; j<=ordem ; j++ )
		{
			printf("|%.1f| ", matrizAB[i][j]);
		}
		printf("\n");
	}   
	
	
	printf("\nA Matriz multiplicadora é:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		printf("|%.1f| ", vetorX[i]);
	}
	
	
	
	getch();
	
}
