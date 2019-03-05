#include<stdio.h>
#include<Conio.h>


void main (void) {

    int i/* linhas */, j/* colunas */, r /* limite inferior do somatorio */,soma=0;
    int ordemCL, ordemCC, ordemN, ordemAL, ordemAC, ordemBL, ordemBC;


    printf("Informe a Quantidade de LINHAS da Matriz A \n");
    scanf("%d", &ordemAL);
    printf("Informe a Quantidade de COLUNAS da Matriz A \n \n");
    scanf("%d", &ordemAC);

    printf("Informe a Quantidade de LINHAS da Matriz B \n");
    scanf("%d", &ordemBL);
    printf("Informe a Quantidade de COLUNAS da Matriz B \n \n");
    scanf("%d", &ordemBC);

    if (ordemAC != ordemBL) {
        printf("Para Multiplicacao de Matrizes o Numero de Colunas da MATRIZ A \n");
        printf("Tem de ser igual ao numero de linhas da MATRIZ B");
    }
    else {
        ordemN = ordemBL;
        ordemCC = ordemBC;
        ordemCL = ordemAL;
        float matrizA[ordemAL][ordemAC];
        float matrizB[ordemBL][ordemBC];
        float matrizC[ordemCL][ordemCC];

        printf("MATRIZ A: \n");
        for (i=0; i<ordemAL ;i++){
            for (j=0;j<ordemAC;j++){
                printf("INFORME O ELEMENTO %dx%d da matriz A ", i+1, j+1);
                scanf("%f",&matrizA[i][j]);
            }
            printf("\n");
        }
        printf("MATRIZ B: \n");
        for (i=0; i<ordemBL ;i++){
            for (j=0;j<ordemBC;j++){
                printf("INFORME O ELEMENTO %dx%d da matriz B ", i+1, j+1);
                scanf("%f",&matrizB[i][j]);
            }
            printf("\n");
        }

        for (i=0; i<ordemCL ;i++){
            for (j=0;j<ordemCC ;j++){
                soma=0;
                for (r=0; r<ordemN;r++){
                    soma+=(matrizA[i][r]*matrizB[r][j]);
                }
                matrizC[i][j]=soma;
            }
        }

// IMPRESSAO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        printf("MATRIZ A[%d]x[%d]:\n", ordemAL, ordemAC);
        for (i=0; i<ordemAL ;i++){
            for (j=0;j<ordemAC;j++){
                printf("%|%1.f| ", matrizA[i][j]);
            }
            printf("\n");
        }
        printf("MATRIZ B[%d]x[%d]:\n", ordemBL, ordemBC);
        for (i=0; i<ordemBL ;i++){
            for (j=0;j<ordemBC;j++){
                printf("%|%1.f| ", matrizB[i][j]);
            }
            printf("\n");
        }
        printf("MATRIZ C[%d]x[%d]:\n", ordemCL, ordemCC);
        for (i=0; i<ordemCL ;i++){
            for (j=0;j<ordemCC;j++){
                printf("%|%1.f| ", matrizC[i][j]);
            }
        printf("\n");
        }
    }

    getch();

}
