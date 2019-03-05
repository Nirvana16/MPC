#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


void main(){
	float matrizA[3][3], MatAB[3][4] ={{2,3,-1,-7},{1,1,1,4},{-1,-2,3,15}};
	float matrizAB[3][4] = {{2,3,-1,-7},{1,1,1,4},{-1,-2,3,15}};
	float vetorX[3];
	float pivo = 0, m = 0;
	int i, j, k;
	int ordem = 3;


//calculo de gauss jordam
	for(i=0;i<ordem; i++){
        pivo = matrizAB[i][i]; // elemento pivo sempre recebendo o primeiro elemento da diagonal principal
        for(j=0; j<=ordem; j++){
            matrizAB[i][j] = matrizAB[i][j] / pivo; // eliminação de cada elemento abaixo da diagonal principal
        }
        for(k=0; k<ordem; k++){
            if (i != k){ // para zerar os elementos da matriz A que estão acima da diagonal
            	m = matrizAB[k][i];
                for(j=0; j<=ordem; j++){
                    matrizAB[k][j] = matrizAB[k][j] - (matrizAB[i][j] * m);
                }
            }
        }
    }
//
////separando a matriz resultante.
//    for (i=0; i<ordem; i++){ //separando as matrizes
//        for(j=0; j<=ordem; j++){
//            if (j==ordem){
//                vetorX[i] = matrizAB[i][j];
//            }
//            else
//                matrizA[i][j] = matrizAB[i][j];
//        }
//	}
//
////imprimindo resultados
//	printf("A Matriz AB, antes era:\n"); //MATRIZ AB antiga
//	for(i=0 ; i<ordem ; i++ ){
//		for(j=0 ; j<=ordem ; j++ ){
//			printf("|%.1f| ", MatAB[i][j]);
//		}
//		printf("\n");
//	}

	printf("\nA nova Matriz AB é:\n"); //MATRIZ AB
	for(i=0 ; i<ordem ; i++ ){
		for(j=0 ; j<=ordem ; j++ ){
			printf("|%.1f| ", matrizAB[i][j]);
		}
		printf("\n");
	}
//	printf("\nA Matriz multiplicadora é:\n"); //MATRIZ MULTIPLICADORA
//	for(i=0 ; i<ordem ; i++ ){
//		printf("|%.1f| \n", vetorX[i]);
//	}
	getch();
}
