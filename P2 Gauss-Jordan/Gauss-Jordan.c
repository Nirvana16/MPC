#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	float **matrizA, **matriz_AB;
	float *vetX, *vetB;
	float valor, elemento;
    float pivo, m, soma = 0;
	int ordem;
	int i, j, k; 
	
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
	
	
	printf("Ordem da Matriz A: ");
	scanf("%d", &ordem);
	printf("\n\n");
	

	matrizA = (float**)malloc (ordem* sizeof(float*));
	matriz_AB = (float**)malloc (ordem* sizeof(float*));
	vetX = (float*) malloc (ordem * sizeof(float));
	vetB = (float*) malloc (ordem * sizeof(float));
	

	for(i=0; i<ordem; i++)
	{
		matrizA[i]= (float*)malloc (ordem* sizeof(float)); 
   		matriz_AB[i]= (float*)malloc ((ordem+1) *sizeof(float)); 
    	 
    }
    
    
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
    
    
    //Preencher Matriz A.
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
    
    //Preencher Vetor b.
    for(i=0; i<ordem; i++)
	{
		printf("Elemento %dx%d da Matriz B: ",i+1,1);	
		scanf("%f", &valor);	
		vetB[i] = valor; 
    }
    
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -


	for (i=0; i<ordem; i++)
	{
		for(j=0; j<=ordem; j++)
		{
			if (j == ordem) //Igual porque no for é <=, portanto pegará mais
			{               //... um elemento após o último da coluna.
			    matriz_AB[i][j] = vetB[i];
			}
               
            else
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


//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -


    for(i=0; i<ordem; i++)
	{
        pivo = matriz_AB[i][i]; //Diagonal.

        for(j=0; j<=ordem+1; j++) //Porque tem mais uma coluna.
		{                         //Pulando de coluna
            matriz_AB[i][j] = (matriz_AB[i][j] / (pivo)); //Divide a linha toda 
        }                                                 //... pelo pivô.

        for(k=0; k<ordem; k++)
        {
            if (i != k) //Para não pegar a linha do pivô.
            {
            	m = matriz_AB[k][i]; //Amarra pelo "i".
                for(j=0; j<=ordem+1; j++)
                {
                    matriz_AB[k][j] = matriz_AB[k][j] - (matriz_AB[i][j] * m);
                }										 //Linha do Pivô.
                
            }

        }

    }
    
    
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
    

	for (i=0; i<ordem; i++)
	{
			for(j=0; j<=ordem; j++)
			{
				if (j==ordem)
				   vetX[i] = matriz_AB[i][j]; //Pegar a última coluna e criar o Vetor!
	               
	            else
	               matrizA[i][j] = matriz_AB[i][j]; //Resto, sem a última coluna.
	        }
	}	
    
 
//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -


	printf("\nA Matriz AB é:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		for(j=0 ; j<=ordem ; j++ )
		{
			printf("|%.1f| ", matriz_AB[i][j]);
		}
		printf("\n");
	}   
	
	
	printf("\nA Matriz multiplicadora é:\n");
	for(i=0 ; i<ordem ; i++ )
	{
		printf("|%.1f| ", vetX[i]);
	}


//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
	
	
free(matrizA);	
free(matriz_AB);
free(vetX);
free(vetB);


getch();

}
