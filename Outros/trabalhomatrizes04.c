#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
	float **matrizA,*matrizResultante,**matrizR_TRans,**matrizR,*vetorX,*vetorY,m, valor, soma1=0,soma2=0,elemento,soma;
    int i,j,k,n; 
	
	printf("Digite a ordem da matriz Principal, de modo ela ser quadrada:");
	scanf("%f", &m);
	
	// alocar a matriz dinamicamente
	matrizA= (float**)malloc (m * sizeof(float*)); // ponteiro de ponteiro
	matrizR_TRans=(float**)malloc (m * sizeof(float*));
	matrizR=(float**)malloc (m * sizeof(float*));
	vetorX= (float*) malloc (m * sizeof(float));
	vetorY=(float*) malloc (m * sizeof(float));
	matrizResultante= (float*) malloc (m * sizeof(float));
	
	//para fazer o vetor apontar para cada linha da matriz,alocando-a.
	for(i=0;i< m; i++){
		matrizA[i]= (float*)malloc (m * sizeof(float)); 
    }
    for(i=0;i< m; i++){
		matrizR_TRans[i]= (float*)malloc (m * sizeof(float)); 
    }
    for(i=0;i< m; i++){
		matrizR[i]= (float*)malloc (m * sizeof(float)); 
    }
    
	// usuario preenchendo a matriz A. 
	for(i=0;i<m; i++){
        for (j=0;j<m;j++){
			printf("Digite o valor para o elemento %dx%d da matriz Principal:",i+1,j+1);
			scanf("%f", &elemento);
			matrizA[i][j]= elemento;
        }
    }
    for(i=0;i<m; i++){ // preenchendo a matriz resultante (B)
		printf("Digite o valor para o elemento %dx%d da matriz Resultante:",i+1,1);	
		scanf("%f",&valor);	
		matrizResultante[i]=valor; 
    }
       
		   					
   for(i=0;i<m;i++){
	  for(j=1;j<m;j++){
         
	         if(i==j){
	            for(k=0;k<=(i-1);k++){
                   soma1+= (matrizR[k][i])*(matrizR[k][i]);
                }
                matrizR[i][i]= sqrt(matrizA[i][j]- soma1);
			 }
			 
			 
			 if(i<j){	  
			   for(k=0;k<=(i-1);k++){
                  soma2+= (matrizR[k][i])*(matrizR[k][j]);
               }
               matrizR[i][j]=((matrizA[i][j])-soma2)/(matrizR[i][i]);
	         }
			 else  
		       matrizR[i][j]=0;
		    
       }
    }
    // para achar a transposta de R
	for(i=0;i<m; i++){
        for (j=0;j<m;j++){
			matrizR_TRans[i][j]= matrizR[j][i];
        }
    }
    
    
    
    // para achar o y
	vetorY[0] = matrizResultante[0]/(matrizR_TRans[0][0]);
		
	for( i=1 ; i<m ; i++ ){
		for(  j=0 ; j<i ; j++){
			if(i>=j){
				soma += ((matrizR_TRans[i][j])*(vetorY[j]));			
			}
		}
		vetorY[i] = (matrizResultante[i] - soma)/matrizR_TRans[i][i];
		soma = 0;
	}	
	
	for(  i=0 ; i<m ; i++ ){
		printf("|%.1f| ", vetorY[i]);
	}    
	
//para achar x
	n=m-1; // a posiçao na matriz começa com zero,então tem q diminuir um para verifica a posição desejada.
	// de acordo com a formula, para achar o ultimo elemento do vetor multiplicador
	vetorX[n] = vetorY[n]/(matrizR[n][n]); 
		
	for( i= m-2 ; i>=0 ; i-- ){ // para percorrer as linhas,como o ultimo elemento foi calculado acima,começa-se pela penultima linha 
		for(  j=i ; j<m ; j++){ // percorre a coluna,então tem q se basear pela ordem,qtd de colunas.
			if(i<=j){
				soma += ((matrizR[i][j])*(vetorX[j]));			
			}
		}
		vetorX[i] = (vetorY[i] - soma)/matrizR[i][i];
		soma = 0;
	}	
	printf("\nA Matriz multiplicadora eh:\n");
	for(  i=0 ; i<m ; i++ ){
		printf("|%.1f| ", vetorX[i]);
	}
	

    
    
free(matrizA);	
free(matrizR_TRans);
free(matrizR);
getch();	
}
