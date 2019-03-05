#include <stdio.h>
#include<stdlib.h>
#include<conio.h>


int main()
{
	int ordem;
	int i, j, k;
	float preenche, soma1=0, soma2=0, result=0;
	float **l, **u, **a, *b, *x,*y;


//- - - - - - - - - - - - - - - - - - - - - - - - - -


	printf("Ordem da matriz principal: ");
	scanf("%d", &ordem);
	

	//Vetor de ponteiros para as linhas da matriz.
	l = (float **) malloc(ordem * sizeof(float *));
    u = (float **) malloc(ordem * sizeof(float *));  
    a = (float **) malloc(ordem * sizeof(float *));
    
    b =(float*) malloc(ordem * sizeof(float));
    x =(float*) malloc(ordem * sizeof(float));
    y =(float*) malloc(ordem * sizeof(float));
 

	//Aponta para cada linha.
	for( i=0 ; i<ordem ; i++ )
    {
		l[i] = (float *) malloc(ordem * sizeof(float));	
		u[i] = (float *) malloc(ordem * sizeof(float));
		a[i] = (float *) malloc(ordem * sizeof(float));
	}


//- - - - - - - - - - - - - - - - - - - - - - - - - -


	printf("\n\n******** Matriz 1 ********\n\n");
    for(i=0 ; i<ordem ; i++)
    {
        for(j=0 ; j<ordem ; j++)
        {
                //Somando sempre +1, pois na matriz começa por [0][0].
				printf("Pos. %d|%d: ", i+1, j+1);
				scanf("%f", &preenche);
				a[i][j] = preenche;
		}
	}
	printf("\n\n");
	
	
	
		 printf("******** Matriz 2 ********");	
     for( i=0 ; i<ordem ; i++ )
     {
		printf("\nDigite o valor da posicao %d|%d do vetor: ", i+1,1);	
		scanf("%f", &preenche);
		b[i] = preenche;
    }


//- - - - - - - - - - - - - - - - - - - - - - - - - -

	
    for(i=0;i<ordem;i++)
    {
        for(j=0;j<ordem;j++)
        {          
            if (i<=j)
            {
                for (k=0; k <= i-1; k++)
                {//Linha de U
                    soma1 += (l[i][k]*u[k][j]);
                }
                u[i][j]= a[i][j]- soma1;
                soma1 = 0;
            }

            else
                //Zero embaixo!
                u[i][j]=0;
                    
                if (i>j)
                {
                    for (k=0; k <= j-1; k++)
                    {//Coluna de L
                        soma2 += (l[i][k])*(u[k][j]);
                    }
                    l[i][j]=(a[i][j]-soma2)/u[j][j];
                    soma2 = 0;
                }
                else                   
                     if (i==j)
                     {
                              //Diagonal principal!
                              l[i][j]=1;
                     }
                     else                  
                               //Zero em cima!!                       
                               l[i][j]=0; 
           }
     }
	


//- - - - - - - - - - - - - - - - - - - - - - - - - -


    //Y
    y[0] = b[0]/(l[0][0]);	
	for(i=1 ; i<ordem ; i++)
	{
        for(j=0 ; j<i ; j++)
        {	  
            result += (l[i][j]*y[j]);		
		}

		y[i] = (b[i] - result)/l[i][i];
		result = 0;
	}
	
	
	//X
     x[ordem-1] = y[ordem-1]/(u[ordem-1][ordem-1]);

     for(i=ordem-2 ; i>=0 ; i--)
     {  
		for(j=i ; j<ordem ; j++)
        {
            result += ((u[i][j])* (x[j]));			 
		}
		
		x[i] = (y[i] - result)/u[i][i];
		result = 0;
	 }	
	 
	 
	  printf("\n\n******** Resultado X ********\n");
	 for(i=0 ; i<ordem ; i++)
     {
		printf("|%.1f| ", x[i]);
     }

     
      printf("\n\n******** Resultado Y ********\n");
	 for(i=0 ; i<ordem ; i++)
     {
		printf("|%.1f| ", y[i]);
     }
     
	
	free(l);
	free(u);
	free(a);

	getch();

}
