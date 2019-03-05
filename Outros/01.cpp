#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("digite a ordem da matriz:");
	scanf("%d",&i);
	int j=0;
	int lmax=3;
	int jmax=3;
	int soma=0;
	int b[3]={2,-3,1};
	int vet[3][3] = {2,0,0,1,4,0,1,1,1};
	int x[3]= {0,0,0};
	
	for(i=0;i<=lmax;i++)
	{
		soma=0;
		for (j=0;j<i;j++)
		{
			soma+=((vet[i][j])*x[j]);
		}
		if(vet[i][i])
		{
			printf("E impossivel de calcular pois o item posicao [%d][%d] e igual a zero.",i,j);
			getch();
			break;
		}
		x[i]=(((b[i])-soma)/vet[i][i]);
	}
	for (i=0;i<3;i++)
	{
		printf("%d,",x[i]);
	}
	getch();
}
