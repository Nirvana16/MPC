#include <stdio.h>
#include <stdlib.h>


main()
{
	 float A[3][4] = {{3,0,1,1},{3,2,1,1},{-3,1,3,3}};
	 float B[3];
	 float M[3][3];
	 float L[3][4];
	 int i,j,k;
	 float x[3],soma;
//B ir√° receber os ultimos elementos de cada linha de A[3][4]


//digo que todos os valores de A s„o L
	for(i=0;i<3;i++)
        for(j=0;j<4;j++)
    	{
    		L[i][j] = A[i][j];
        }
        
	
		
//resolucao para as linhas aplicando gauss pivotamento diagonal
	 for(i=0;i<2;i++)
	 {
     	for(k=(i+1);k<3;k++)
	 	{
            M[k][i] = A[k][i]/A[i][i];	
 
            for(j=0;j<4;j++)
	 		{
                L[k][j] = L[k][j] - (L[i][j] * M[k][i]);
            }			
	 	}
	 }

//atribuindo valores para B
    for(i=0;i<3;i++)
    {
        B[i] = L[i][3];
    }
    
//resolver a matriz Superior

    x[2] = B[2]/L[2][2];
    for(i=2;i>0;i--)
    {
        soma = 0;
        for(j=0;j<i;j++)
        {
            soma += L[i][j] * x[j];
        }
        x[i] = (B[i] - soma)/L[i][i];
    }
     	

//para imprimir

		
		printf("\n Matriz A \n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf(" %6.1f ",A[i][j]);
			}
		    printf("\n");
		}
		
		printf("\n Vetor B \n");
		for(i=0;i<3;i++)
		{
			printf(" %6.1f ",B[i]);
		    printf("\n");
		}
		
		printf("\n Matriz L \n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf(" %6.1f ",L[i][j]);
			}
		    printf("\n");
		}
		
		printf("\n     X \n");
		for(i=0;i<3;i++)
		{
			printf(" %6.1f ",x[i]);
		    printf("\n");
		}
		
		
    system("pause");
}
		
		
		
	 					
