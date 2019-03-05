#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main(){

	int   i, j, k, cont=0, ordem;
	float valor_elemento, ordem_matriz1, somatorio=0, **matrizu, *matrizb, *matrizx, **matrizl, **matriza, somatorio1=0, somatorio2=0, *matrizy;
	
	
	printf("Calculo da matriz X, onde: A . X = B\n\n");
	printf("Insira a ordem da matriz A:");
	scanf("%f", &ordem_matriz1);
	
	//aloco os ponteiros de matrizes dinâmicamente na memória
	matriza = (float **) malloc(ordem_matriz1 * sizeof(float*)); 
	matrizu = (float **) malloc(ordem_matriz1 * sizeof(float*));
	matrizl = (float **) malloc(ordem_matriz1 * sizeof(float*));
	matrizx = (float *) malloc(ordem_matriz1 * sizeof(float));
	matrizy = (float *) malloc(ordem_matriz1 * sizeof(float));
	matrizb = (float *) malloc(ordem_matriz1 * sizeof(float));
	
	//ponteiros que apontam para floats. Linhas das matrizes
	for( i=0 ; i<ordem_matriz1 ; i++ ){
		matriza[i] = (float *) malloc(ordem_matriz1 * sizeof(float));	
	}
	
	for( i=0 ; i<ordem_matriz1 ; i++ ){
		matrizu[i] = (float *) malloc(ordem_matriz1 * sizeof(float));	
	}
	
	for( i=0 ; i<ordem_matriz1 ; i++ ){
		matrizl[i] = (float *) malloc(ordem_matriz1 * sizeof(float));	
	}
	

	// adiciona os elementos da matriza:
	for(i=0; i<ordem_matriz1; i++){
		for(j=0; j<ordem_matriz1; j++){
				printf("Insira o elemento %dx%d da matriz A:", i+1, j+1);
				scanf("%f",&valor_elemento);
				matriza[i][j] = valor_elemento;
		}
	}
	
	// adiciona os elementos da matrizb :
		printf("\n");
		for(i=0; i<ordem_matriz1; i++){
				printf("Insira o elemento %dx1 da matriz B:", i+1);
				scanf("%f",&valor_elemento);
				matrizb[i] = valor_elemento;
		}
		
	// calcula a primeira linha da matrizu,  que será igual a primeira linha da matriza:
	 for(i=0; i< ordem_matriz1; i++){
		 matrizu[0][i] = matriza[0][i];
	 }
	 
	 
	// calcula a primeira coluna da matrizl:
	 for(j=0; j< ordem_matriz1; j++){
		 matrizl[j][0] = matriza[j][0]/matrizu[0][0];
	 }
	 
     
	 //calcula a matrizu e a matrizl pela decomposição:
	for(i=0; i< ordem_matriz1; i++){
		for(j=1; j< ordem_matriz1; j++){
			if(i<=j){
				for(k=0; k<=(i-1); k++){	
					somatorio1 = somatorio1 + (matrizl[i][k] * matrizu[k][j]);
				}
				matrizu[i][j] = matriza[i][j] - somatorio1;
				somatorio1 = 0;
			}
			else{
				matrizu[i][j] = 0;
			}
			
			
			if(i>j){
				for(k=0; k<=(j-1); k++){
					somatorio2 = somatorio2 + (matrizl[i][k] * matrizu[k][j]);
				}
				matrizl[i][j] = (1/matrizu[j][j]) * (matriza[i][j] - somatorio2);
				somatorio2 = 0;
			}
		
			else{
				if(i==j){
					matrizl[i][j] = 1;	
				}
				else{
					matrizl[i][j] = 0;
				}
				cont++;
			}
		}	
	}
	
	// imprime a matriza:
	printf("Matriz A:\n");
	for(i=0; i<ordem_matriz1; i++){
		for(j=0; j<ordem_matriz1; j++){
			printf(" %.2f ", matriza[i][j]);
		}
		printf("\n\n");
	}
	
	// imprime a matrizb:
	printf("Matriz B:\n");
	for(i=0; i<ordem_matriz1; i++){
			printf(" %.2f ", matrizb[i]);
		printf("\n");
	}
	ordem = ordem_matriz1 - 1;
		
	// imprme a matrizu :
	printf("Matriz U:\n");
	for(i=0; i<ordem_matriz1; i++){
		for(j=0; j<ordem_matriz1; j++){
			printf(" %.2f ", matrizu[i][j]);
		}
		printf("\n\n");
	}
	
	// imprme a matrizl :
	printf("Matriz L:\n");
	for(i=0; i<ordem_matriz1; i++){
		for(j=0; j<ordem_matriz1; j++){
			printf(" %.2f ", matrizl[i][j]);
		}
		printf("\n\n");
	}
	
	
	// calcula a matrizy
	matrizy[0] = matrizb[0]/matrizl[0][0];
	for(i=1; i<ordem_matriz1; i++){
		for(j=0; j<i; j++){
			somatorio =  somatorio + matrizl[i][j] * matrizy[j];
		}
		matrizy[i] = (matrizb[i] - somatorio)/matrizl[i][i];
		somatorio = 0;
	}
	
	// imprime a matrizy
	printf("Matriz Y:\n");
	for(i=0; i<ordem_matriz1; i++){
			printf("%.2f", matrizy[i]);
		printf("\n\n");
	}
	
	//calcula a marizx: 
	ordem = ordem_matriz1 -1;
	matrizx[ordem] = matrizy[ordem]/matrizu[ordem][ordem];                                      //****//
	for (i = ordem_matriz1 - 2; i >= 0; i--){                                              
		for(j=i; j < ordem_matriz1; j++){
		   
			somatorio = somatorio + (matrizu[i][j] * matrizx[j]);
		   //exit(EXIT_FAILURE);
		}
		matrizx[i] = (matrizy[i] - somatorio)/matrizu[i][i];
		somatorio = 0;
		/*if(matrizx[i] == 5.0){
			matrizx[i] = 0.0;	
		}*/
	}
	
	// imprime a matrizx
	printf("A matriz X e:\n");
	for(i=0; i<ordem_matriz1; i++){
			printf("%.2f", matrizx[i]);
		printf("\n\n");
	}
		
	getch()	;
}
