#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>


void linha (float Vet[3], float Mat[3][3], int ordem){
    int i,j;
    float soma = 0, maior=0;

    for (i=0;i<ordem;i++){
        for (j=0;j<ordem;j++){
            soma += abs(Mat[i][j]);
        }
        Vet[i]=soma = soma;
        soma = 0;
    }
    printf("Vetor Somado = \n");
    for(i=0 ; i<ordem ; i++){
		printf("|%.1f| ", Vet[i]);
	}
    printf("\n\n");
    for(i=0;i<ordem;i++){
        if (Vet[i]>maior){
            maior=Vet[i];
        }
    }
    printf("Maior = %.1f ",maior);
}

void coluna (float Vet[3], float Mat[3][3], int ordem){
    int i,j;
    float soma = 0, maior=0;

    for (i=0;i<ordem;i++){
        for (j=0;j<ordem;j++){
            soma += abs(Mat[j][i]);
        }
        Vet[i]=soma = soma;
        soma = 0;
    }
    printf("Vetor Somado = \n");
    for(i=0 ; i<ordem ; i++){
		printf("|%.1f| ", Vet[i]);
	}
    printf("\n\n");
    for(i=0;i<ordem;i++){
        if (Vet[i]>maior){
            maior=Vet[i];
        }
    }
    printf("Maior = %.1f ",maior);
}

void eucli ( float Mat[3][3], int ordem){
    int i, j;
    float soma=0, resultado=0;

    for (i=0;i<ordem;i++){
        for (i=0;i<ordem;i++){
            soma += pow(Mat[i][j],2);
        }
        resultado += soma;
        soma=0;
    }
    resultado = sqrt(resultado);
    printf("%6.2f \n", resultado);
}
int main(){

	int i, j, escolha=1, ordem=3;
	int opcaoMenuNormas;
	float matrizUnica[3][3]={3,2,5,1,1,2,4,3,-2};
	float vetorUnico[3];
	float valor;


//- - - - - - - - - - - - - - - - - - - - - - - - - -

while (escolha==1){
	printf("\n\n.... Opcoes de Normas .... \n\n");

	printf ("1- Norma Linha\n");
	printf ("2- Norma Coluna\n");
	printf ("3- Norma Euclidiana\n\n");
	printf ("Opcao: ");
	scanf ("%i", &opcaoMenuNormas);


	switch(opcaoMenuNormas){
		case 1:
			linha(vetorUnico, matrizUnica, ordem);
		break;
		case 2:
			coluna(vetorUnico, matrizUnica, ordem);
		break;
		case 3:
			eucli(matrizUnica, ordem);
		break;
	}
    printf ("\n\nDeseja executar de novo? 1 = SIM 2 = NAO :");
    scanf ("%i", &escolha);
}
	getch();
}
