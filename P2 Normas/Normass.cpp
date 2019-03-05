#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>
//#include <locale.h> //Faz aceitar acentos \o/
					//N�o funciona no Windows XP!


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


//Fun��o para calcular a norma Euclidiana.
void normaEuclidiana(float **matUnic, int ordem)
{
	int i, j;	
	float soma_Euclidiana = 0, guarda_result = 0;
	
	
	for(i=0 ; i<ordem ; i++) 
    {
    	
    	for(j=0 ; j<ordem ; j++) 
    	{    
			soma_Euclidiana += pow(matUnic[i][j],2); //Elevar ao quadrado.
		}   
		        
		guarda_result += soma_Euclidiana;
		soma_Euclidiana = 0;
	}
	
	 guarda_result = sqrt(guarda_result); //Raiz quadrada.
	 
	 //Pega os elelmentos da matriz, eleva tdo ao quadrado, soma e faz a raiz.


	printf("\n\n.... Resultado .... \n\n");
	
	printf("Valor aproximado:\n");
		printf("%6.2f \n", guarda_result);


} //Fim da fun��o void "normaEuclidiana".


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


//Fun��o para calcular a soma de cada coluna da Matriz.
void normaColuna(float *vetUnic, float **matUnic, int ordem)
{
	int i, j;
	float soma_coluna = 0, guarda_maior = 0;
	
	//Somat�rio
	for(i=0 ; i<ordem ; i++) 
    {
    	
    	for(j=0 ; j<ordem ; j++) 
    	{                       
    		soma_coluna += matUnic[j][i]; //O "j" vem primeiro aqui para assim...
		}                                 //... trocar de linha rapidamente...
		                                  //... portanto somar a coluna toda.
		vetUnic[i] = soma_coluna;
		soma_coluna = 0; 
	}
	
	
	printf("\n\n.... Resultado .... \n\n");
	
	printf("Vetor �nico:\n");
	for(i=0 ; i<ordem ; i++)
    {
		printf("|%.1f| ", vetUnic[i]);
	}
	
	printf("\n\n");
		
		
	for(i=0 ; i<ordem ; i++)
	{
		if (vetUnic[i] > guarda_maior)
		{
			guarda_maior = vetUnic[i];
		}
	}
	
	
	printf("O maior n�mero �: %.1f", guarda_maior);
	
	
} //Fim da fun��o void "normaColuna".


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


//Fun��o para calcular a soma de cada linha da Matriz.
void normaLinha(float *vetUnic, float **matUnic, int ordem)
{
	int i, j;
	float soma_linha = 0, guarda_maior = 0;
	
	//Somat�rio
	for(i=0 ; i<ordem ; i++) //Pula de linha.
    {
    	
    	for(j=0 ; j<ordem ; j++) //O "j" fica em segundo plano para trocar de...
    	{                        //... coluna.
    		soma_linha += matUnic[i][j];
		}
		
		vetUnic[i] = soma_linha;
		soma_linha = 0; //Zera depois que troca de linha.
	}
	
	
	printf("\n\n.... Resultado .... \n\n");
	
	printf("Vetor �nico:\n");
	for(i=0 ; i<ordem ; i++)
    {
		printf("|%.1f| ", vetUnic[i]);
	}
	
	printf("\n\n");
	
	
	//Compara o primeiro n�mero do vetor com "0". Se for maior ir� guardar numa...
	//... vair�vel. A partir disso a compara��o ser� feita em cima deste n�mero.
	for(i=0 ; i<ordem ; i++)
	{
		if (vetUnic[i] > guarda_maior)
		{
			guarda_maior = vetUnic[i];
		}
	}
	
	
	printf("O maior n�mero �: %.1f", guarda_maior);
	
	
} //Fim da fun��o void "normaLinha".


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


int main()
{	
	//Faz aceitar acentos \o/
	//setlocale(LC_ALL, "Portuguese");
	
	//Declarando...
	int i, j, ordem;
	int opcaoMenuNormas;
	float **matrizUnica;
	float *vetorUnico;
	float valor;
	
	
//- - - - - - - - - - - - - - - - - - - - - - - - - -

	printf("- - - - - - - - - Exerc�cio - - - - - - - - -\n\n");
	printf("- - - - - - - - - - Normas - - - - - - - - - -\n\n");
	printf("Por: Matheus Manh�es Tavares \n");
	printf("Professor: Arialdo \n");
	printf("Instituto Federal Fluminense - IFF \n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n\n");


	printf("Ordem da Matriz: ");
	scanf("%d", &ordem);
	printf("\n\n");
	
	
//- - - - - - - - - - - - - - - - - - - - - - - - - -
	
	
	//Vetor de ponteiros para as linhas da matriz.
	matrizUnica = (float **) malloc(ordem * sizeof(float *));
	vetorUnico = (float *) malloc(ordem * sizeof(float)); 
	
	//Aponta para cada linha.
	for(i=0 ; i<ordem ; i++)
    {
		matrizUnica[i] = (float *) malloc(ordem * sizeof(float));	
	}
	
	
//- - - - - - - - - - - - - - - - - - - - - - - - - -


	printf(".... Preenchendo .... \n\n");

	for(i=0 ; i<ordem ; i++)
    {
    	for(j=0 ; j<ordem ; j++)
    	{
    		printf("- Pos. %dx%d: ", i+1, j+1);
			scanf("%f", &valor);
			matrizUnica[i][j] = valor;
    	}//Fim do for "j" de preencher a matriz.
    	
    }//Fim do for "i" de preencher a matriz.
    
    
//- - - - - - - - - - - - - - - - - - - - - - - - - -

	
	printf("\n\n.... Op��es de Normas .... \n\n");
	
	printf ("1- Norma Linha\n");
	printf ("2- Norma Coluna\n");
	printf ("3- Norma Euclidiana\n\n");
	printf ("Op��o: ");
	scanf ("%i", &opcaoMenuNormas);
	

	switch(opcaoMenuNormas) 
	{
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
	
    
//- - - - - - - - - - - - - - - - - - - - - - - - - -
	

	free(matrizUnica); //Desalocar...

	getch();
	

} //Fim da chave "main".
