#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main()
{



	float matrizB[3][3];
	float matrizAB[3][6] = {{2,1,3,1,0,0},{0,-1,1,0,1,0},{1,0,3,0,0,1}};
	float pivo = 0, m = 0;
	int i, j, k; 
	int ordem = 3;
	
	
	for(i=0; i<ordem; i++)
	{
        pivo = matrizAB[i][i]; 

        for(j=0; j<=(ordem*2); j++) 
		{                         
            matrizAB[i][j] = matrizAB[i][j] / pivo; 
        }                                                 

        for(k=0; k<ordem; k++)
        {
            if (i != k) 
            {
            	m = matrizAB[k][i]; 
                for(j=0; j<(ordem*2); j++)
                {
                    matrizAB[k][j] = matrizAB[k][j] - (matrizAB[i][j] * m);
                }										
                
            }

        }

    }
    
	
	
	for(i=0 ; i<ordem ; i++)
	{
	   for(j=0 ; j<(ordem*2) ; j++)
	   {
			if(j >= ordem)
				matrizB[i][j-ordem] = matrizAB[i][j];
		}
	}
	
	
	printf("A Matriz B é:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		for(j=0 ; j<ordem ; j++ )
		{
			printf("|%.1f| ", matrizB[i][j]);
		}
		printf("\n");
	}   
	
	printf("\n");
	
	printf("A Matriz AB é:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		for(j=0 ; j<(ordem*2) ; j++ )
		{
			printf("|%.1f| ", matrizAB[i][j]);
		}
		printf("\n");
	} 
	
	
	getch();
	
	
	
	
}
