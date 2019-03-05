#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	
	int i, j, ordem = 3;
	int opcaoMenuNormas;
	float matrizUnica[3][3] = {1,2,3,4,5,6,7,8,9};
	float vetorUnico[3];
	float guardaMaior = 0, guarda_resultado = 0;
		
	
	printf(".... Opções de Normas .... \n\n");
	
	printf ("1- Norma Linha\n");
	printf ("2- Norma Coluna\n");
	printf ("3- Norma Euclidiana\n\n");
	printf ("Opção: ");
	scanf ("%i", &opcaoMenuNormas);
	
	
	switch(opcaoMenuNormas) 
	{
		case 1:
			
			for (i=0; i<ordem; i++)
			{
				for (j=0; j<ordem; j++)
				{
					guardaMaior += matrizUnica[i][j];
				}	
				vetorUnico[i] = guardaMaior;
				guardaMaior = 0;
			}
		
			printf("\nVetor Único:\n");
			for(i=0 ; i<ordem ; i++)
    		{
				printf("|%.1f| ", vetorUnico[i]);
			}
	
	
		break;
		
		//-   -   -   -   -   -   -
		
		case 2:
			
			for (i=0; i<ordem; i++)
			{
				for (j=0; j<ordem; j++)
				{
					guardaMaior += matrizUnica[j][i];
				}
				vetorUnico[i] = guardaMaior;
				guardaMaior = 0;
			}
			
			printf("\nVetor Único:\n");
			for(i=0 ; i<ordem ; i++)
    		{
				printf("|%.1f| ", vetorUnico[i]);
			}
			
			
		break;
		
		//-   -   -   -   -   -   -
		
		case 3:
			
			for(i=0 ; i<ordem ; i++) 
    		{
    			for(j=0 ; j<ordem ; j++) 
    			{    
					guardaMaior += pow(matrizUnica[i][j],2); 
				}   
				guarda_resultado += guardaMaior;
				guardaMaior = 0;
			}
	
	 		guardaMaior = sqrt(guarda_resultado);
			
			printf("Valor aproximado:\n");
			printf("%6.2f \n", guardaMaior);
			
			
		break;
					
	}
	
	
	getch();
		
}
