#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>

//Função para calcular a norma Euclidiana.
void normaEuclidiana(float matUnic[3][3], int ordem){
	int i, j;
	float soma_Euclidiana = 0, guarda_result = 0;


	for(i=0 ; i<ordem ; i++){
    	for(j=0 ; j<ordem ; j++){
			soma_Euclidiana += pow(matUnic[i][j],2); //Elevar ao quadrado.
		}
		guarda_result += soma_Euclidiana;
		soma_Euclidiana = 0;
	}
	 guarda_result = sqrt(guarda_result); //Raiz quadrada.

	 //Pega os elelmentos da matriz, eleva tdo ao quadrado, soma e faz a raiz.


	printf("\n\n.... Resultado .... \n\n");
	printf("Valor aproximado eh de:\n");
    printf("%6.2f \n", guarda_result);
} //Fim da função void "normaEuclidiana".

//Função para calcular a soma de cada coluna da Matriz.
void normaColuna(float vetUnic[3], float matUnic[3][3], int ordem){
	int i, j;
	float soma_coluna = 0, guarda_maior = 0;

	//Somatório
	for(i=0 ; i<ordem ; i++){
    	for(j=0 ; j<ordem ; j++){
    		soma_coluna += abs(matUnic[j][i]); //O "j" vem primeiro aqui para assim...
		}                                 //... trocar de linha rapidamente...
		                                  //... portanto somar a coluna toda.
		vetUnic[i] = soma_coluna;
		soma_coluna = 0;
	}


	printf("\n\n.... Resultado .... \n\n");
	printf("Vetor Único:\n");
	for(i=0 ; i<ordem ; i++)
    {
		printf("|%.1f| ", vetUnic[i]);
	}
	printf("\n\n");


	for(i=0 ; i<ordem ; i++){
		if (vetUnic[i] > guarda_maior){
			guarda_maior = vetUnic[i];
		}
	}
	printf("O maior número é: %.1f", guarda_maior);
} //Fim da função void "normaColuna".


//Função para calcular a soma de cada linha da Matriz.
void normaLinha(float vetUnic[3], float matUnic[3][3], int ordem){
	int i, j;
	float soma_linha = 0, guarda_maior = 0;


	for(i=0 ; i<ordem ; i++){ //Pula de linha.
        for(j=0 ; j<ordem ; j++){ //O "j" fica em segundo plano para trocar de...
    		soma_linha += abs(matUnic[i][j]);//... coluna.
		}
        vetUnic[i] = soma_linha;
		soma_linha = 0; //Zera depois que troca de linha.
	}
	printf("\n\n.... Resultado .... \n\n");
	printf("Vetor Unico:\n");
	for(i=0 ; i<ordem ; i++){
		printf("|%.1f| ", vetUnic[i]);
	}
	printf("\n\n");


//Compara o primeiro número do vetor com "0". Se for maior irá guardar numa...
//.. vairável. A partir disso a comparação será feita em cima deste número.
	for(i=0 ; i<ordem ; i++){
		if (vetUnic[i] > guarda_maior){
			guarda_maior = vetUnic[i];
		}
	}
    printf("O maior numero eh: %.1f", guarda_maior);


} //Fim da função void "normaLinha".


int main(){

	int i, j, ordem=3;
	int opcaoMenuNormas;
	float matrizUnica[3][3]={3,2,5,1,1,2,4,3,-2};
	float vetorUnico[3];
	float valor;


//- - - - - - - - - - - - - - - - - - - - - - - - - -


	printf("\n\n.... Opcoes de Normas .... \n\n");

	printf ("1- Norma Linha\n");
	printf ("2- Norma Coluna\n");
	printf ("3- Norma Euclidiana\n\n");
	printf ("Opcao: ");
	scanf ("%i", &opcaoMenuNormas);


	switch(opcaoMenuNormas){
		case 1:
			normaLinha(vetorUnico, matrizUnica, ordem);
		break;
		case 2:
			normaColuna(vetorUnico, matrizUnica, ordem);
		break;
		case 3:
			normaEuclidiana(matrizUnica, ordem);
		break;
	}
	getch();
}
