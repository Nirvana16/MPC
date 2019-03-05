#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");


	int i, j, ordem;
	float **l, preenche, *x, *b, somatorio=0;


//- - - - - - - - - - - - - - - - - - - - - - - - - -


	printf("Ordem da matriz principal: ");
	scanf("%d", &ordem);
	

	//Vetor de ponteiros para as linhas da matriz.
	l = (float **) malloc(ordem * sizeof(float *));
    x = (float *) malloc(ordem * sizeof(float));     
    b = (float *) malloc(ordem * sizeof(float));
 

	//Aponta para cada linha.
	for( i=0 ; i<ordem ; i++ )
    {
		l[i] = (float *) malloc(ordem * sizeof(float));	
	}


//- - - - - - - - - - - - - - - - - - - - - - - - - -


	printf("\n\n******** Matriz 1 ********\n\n");
    for(i=0 ; i<ordem ; i++)
    {
        for(j=0 ; j<ordem ; j++)
        {
            //"If" para ignorar as posições que valem 0.
			if(i<=j)
            {
                //Somando sempre +1, pois na matriz começa por [0][0].
				printf("Pos. %d|%d: ", i+1, j+1);
				scanf("%f", &preenche);
				l[i][j] = preenche;
			}
			
            else
            {//Automaticamente o valor na matriz é substituído por 0.
				l[i][j] = 0;
            }
		}
	}


	printf("\n\n******** Matriz 3 ********\n\n");
	for(i=0 ; i<ordem ; i++)
    {
		printf("Pos. %d|%d: ", i+1,1);	
		scanf("%f", &preenche);
		b[i] = preenche;
	}
	printf("\n\n");
	

//- - - - - - - - - - - - - - - - - - - - - - - - - -


	//Calculando o "x3".
	x[ordem-1] = b[ordem-1]/(l[ordem-1][ordem-1]);
		

	//Calculando "x2/x1".
	for( i=(ordem-2) ; i>=0 ; i--)
    {
		
		for(j=(ordem-1) ; j>=i ; j--)
        {
				somatorio += (l[i][j] * x[j]);			
		}
		x[i] = (b[i] - somatorio)/l[i][i];
		somatorio = 0;
	}	
	

//- - - - - - - - - - - - - - - - - - - - - - - - - -


	//Imprime a matriz na tela.
	printf("******** Resultado ********\n\n");
	for(i=0 ; i<ordem ; i++)
    {
		printf("|%.1f|\n", x[i]);
	}

	//for(i=0 ; i<ordem ; i++)
    //{
		//free(x[i]);
	//}

	free(l);

	getch();

}
