#include<stdio.h>
#include<conio.h>
#include<math.h>


int main(){

	int i,j,k,p,maiorLinha;
	float MatrizA[3][3]={1,2,3,3,1,0,0,3,4};
	float MatrizB[3]={3,4,3};
	float MatrizAB[3][4]={0};
	float MatrizX[3]={0};
	float maiorNumero, variavelegal, pivo,m,soma;

/*Imprimir Matriz*/
	printf("\n\n Imprimindo a MATRIZ A");
	for(i=0;i<3;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf( " %.f",MatrizA[i][j]);
		}
	}
/*Imprimir Matriz*/
	printf("\n\n Imprimindo a MATRIZ B");
	for(i=0;i<3;i++){
		printf( "\n %.f",MatrizB[i]);
	}
/*Unir Matriz*/
	for(i=0;i<3;i++){                   // É NECESSARIO UNIR AS MATRIZES pois o escalonamento é feita na matriz AB
        MatrizAB[i][3] = MatrizB[i];    // Contudo no final preciso desunir as mesmas.
		for(j=0;j<3;j++){
			MatrizAB[i][j] = MatrizA[i][j];
		}
	}
/*Imprimir Matriz*/
	printf("\n\n Imprimindo a MATRIZ AB");
	for(i=0;i<3;i++){
		printf("\n");
		for(j=0;j<4;j++){
			printf( " %.f",MatrizAB[i][j]);
		}
	}
/*Organizando a matriz e calculando gauss*/

    /* Esse bloco ira pegar o maior termo da primeira coluna e anotar qual linha possui esse termo*/
    for(i=0;i<2;i++){               //Use esse for para fazer a substituição no final, coloquei 2 pois sempre sera (ordem de i-1)
        maiorNumero = MatrizAB[i][i];           //Essa forma resolve para para estatica, contudo na dinamica precisa ser implementada mais
        for (j=i+1;j<3;j++){        // j tem de começar com i+1 para ele conseguir pular a linha e respeitar o loop
            if (MatrizAB[j][i]>maiorNumero){    // é importante usar I ou inves de ZERO, devido ao loop do primeiro for
                maiorNumero = MatrizAB[j][i];
                maiorLinha = (j);
            }
        }
    /* Já este ira organizara a matriz colocando o maior elemento da primeira coluna e toda sua linha como sendo a linha 1*/
        for(j=0;j<4;j++){                       // Mesmo que seja um opção usar ZERO no lugar de I
            variavelegal=MatrizAB[i][j];              // Ao programar essa codigo devo ter em mente o momento do LOOP
            MatrizAB[i][j] = MatrizAB[maiorLinha][j];       // Pois a regra diz que após escalonar a segunda linha, devo organizar a matriz
            MatrizAB[maiorLinha][j] = variavelegal;   // Outra vez para escalonar a 3 linha!
        }                                       // Isso é para ordem 3x4, nem quero pensar as de ordem superiores.
    /*Imprimindo a matriz AB após organização*/
        printf("\n\n Imprimindo a MATRIZ AB");
        for(p=0;p<3;p++){
            printf("\n");
            for(j=0;j<4;j++){
                printf( " %.f",MatrizAB[p][j]);
            }
        }
    /*Inicio dos calculos de Gauss*/
        pivo=MatrizAB[i][i];                  // No primeiro Loop o i irá valer ZERO, logo o AB[I][I] = L1x1 = 3
		for(j=i+1;j<3;j++){
			m=MatrizAB[j][i]/pivo;            // O M deve ficar dentro do FOR pois ele é calculado a cada nova linha.
			for (k=0;k<=4;k++){
                MatrizAB[j][k]= MatrizAB[j][k] - (MatrizAB[i][k] * m);
           }
		}
    /*Imprimir Matriz*/
        printf("\n\n MATRIZ AB EQUIVALENTE ");
        for(p=0;p<3;p++){
            printf("\n");
            for(j=0;j<4;j++){
                printf( " %.1f",MatrizAB[p][j]);
            }
        }
    printf("\n \nEscalonamento numero #%i \n", i+1);
   } // FECHA FOR PRINCIPAL

/*Separar Matriz A de B*/
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			MatrizA[i][j] = MatrizAB[i][j];

		}
	}
/* Gerando uma nova matriz B */
	for(i=0;i<3;i++){
		MatrizB[i] = MatrizAB[i][3];
	}

/* Calculando a matriz triangular */

	MatrizX[2]=MatrizB[2]/MatrizA[2][2];
	for(i=1;i>-1;i--){
		soma=0;
		for(j=i+1;j<3;j++){
			soma += (MatrizA[i][j]*MatrizX[j]);
		}
		MatrizX[i]=(MatrizB[i]-soma)/MatrizA[i][i];
	}
	printf("\n\n Vetor Resultante X =");
	for(i=0;i<3;i++){
		printf(" \n %.f",MatrizX[i]);

	}
	getchar();
}
