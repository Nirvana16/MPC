#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

main(){
	float **matriza, *vetorb, *vetorx, *vetorx0, *vetorx2, norma=0, somatorio1=0, somatorio2=0, precisao;
	unsigned ordem; 
	bool pare = false;
	int i, j, t;
	
	printf("Insira a ordem da matriz A:");
	scanf("%u",&ordem);
	
	vetorx = (float*) malloc(ordem * sizeof(float));
	vetorx0 = (float*) malloc(ordem * sizeof(float));
	vetorx2 = (float*) malloc(ordem * sizeof(float));
	vetorb = (float*) malloc(ordem * sizeof(float));
	matriza = (float**) malloc(ordem * sizeof(float*));
	for(i=0; i<ordem; i++)
	{
		matriza[i] = (float*) malloc(ordem * sizeof(float));
	}
	
	//recebe valores da matriz A
	printf("Matriz A: \n");
	for(i=0; i<ordem; i++)
	{
		for(j=0; j<ordem; j++)
		{
			printf("Insira o valor do elemento %dx%d:", i+1, j+1);
			scanf("%f",&matriza[i][j]);		
		}
	}
	
	//recebe valores do vetor B
	printf("Matriz B: \n");
	for(i=0; i<ordem; i++)
	{
		printf("Insira o elemento %dx1: ", i+1);
		scanf("%f",&vetorb[i]);
	}
	
	//recebe valores do vetor X0 inicial
	printf("Matriz X0: \n");
	for(i=0; i<ordem; i++)
	{
		printf("Inisra o elemento %dx%1:", i+1);
		scanf("%f", &vetorx0[i]);
	}
	
	//recebe a precisão
	printf("Insira a precisao:");
	scanf("%f", &precisao);
	
	
	//imprime a matriz A
	printf("Matriz A\n");
	for(i=0; i<ordem; i++)
	{
		for(j=0; j<ordem; j++)
		{
			printf("%.2f ", matriza[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//imprime o vetor B
	printf("Vetor B\n");
	for(i=0; i<ordem; i++)
	{
			printf("%.2f ", vetorb[i]);
			printf("\n");
	}
	
	//imprime o vetor X0
	printf("Vetor X0\n");
	for(i=0; i<ordem; i++)
	{
			printf("%.2f ", vetorx0[i]);
			printf("\n");
	}
	
	while(!(pare)){
	
		for(i=0; i<ordem; i++)
		{
		
			for(j=0; j<i; j++)
			{
				somatorio1 = somatorio1 + (matriza[i][j] * vetorx0[j]);
			}
		
			for(j=i+1; j<ordem; j++)
			{
				somatorio2 = somatorio2 + (matriza[i][j] * vetorx0[j]);
			}
		
			vetorx[i] = (vetorb[i] - somatorio1 - somatorio2)/matriza[i][i];
			somatorio1 = 0;
			somatorio2 = 0;
		
		}
		
		for(t=0; t<ordem; t++)
		{
			vetorx2[t] = vetorx[t] - vetorx0[t];
		}	
		
		//calcula a norma
		for(i=0; i<ordem; i++)
		{
			somatorio1 = somatorio1 + (vetorx2[i] * vetorx2[i]);
			somatorio2 = somatorio2 + (vetorx[i] * vetorx[i]);
		}
		norma = sqrt(somatorio1)/sqrt(somatorio2);
		somatorio1 = 0;
		somatorio2 = 0;
			
		printf("Norma = %f", norma);
		
		//verifica a convergência
		if(norma <= precisao)
		{
			pare = true;
		}
		else{
			for(t=0; t<ordem; t++)
			{
				vetorx0[t] = vetorx[t];
			}
		}
	}
		
getch();
}
