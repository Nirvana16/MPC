#include<stdio.h>
#include<conio.h>

main(){
	int i, j, matriza[2][2], matrizb[2][2], matrizc[2][2],  valor;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++)	{
			printf("insira o elemento %dx%d da matriz A \n", i+1, j+1);
			scanf("%d",&valor);
			matriza[i][j]=valor;
		}
	}
	
		for(i=0;i<2;i++){
		for(j=0;j<2;j++)	{
			printf("insira o elemento %dx%d da matriz B \n", i+1, j+1);
			scanf("%d",&valor);
			matrizb[i][j]=valor;
		}
	}
	
		for(i=0;i<2;i++){
		for(j=0;j<2;j++)	{
			int r = 0;
			matrizc[i][j] = matriza[i][r] * matrizb[r][j] + matriza[i][1+r] * matrizb[1+r][j];
			r++;
		}
	}
	
	
	
	printf("Matriz A:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++)	{
			printf("%d  ", matriza[i][j]);
		}
		printf("\n");
	}
	
	printf("Matriz B:\n");
		for(i=0;i<2;i++){
		for(j=0;j<2;j++)	{
			printf("%d  ", matrizb[i][j]);
		}
		printf("\n");
	}

	printf("Matriz C:\n");
		for(i=0;i<2;i++){
		for(j=0;j<2;j++)	{
			printf("%d  ", matrizc[i][j]);
		}
		printf("\n");
	}

	
	getch();
	
}
