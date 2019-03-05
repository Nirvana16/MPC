#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void normaLinha(float vetorUnico[3], float matrizUnica[3][3], int ordem){
    int i, j;
    float guardaMaior;

    for (i=0; i<ordem; i++){
        for (j=0; j<ordem; j++){
            guardaMaior += matrizUnica[i][j];
        }
        vetorUnico[i] = guardaMaior;
        guardaMaior = 0;
    }
    printf("\nVetor Unico:\n");
    for(i=0 ; i<ordem ; i++){
        printf("|%.1f| ", vetorUnico[i]);
    }

}


int main(){
	int escolha=1,opcaoMenuNormas, i, j, ordem;
	float guardaMaior = 0, guarda_resultado = 0;


// MENU INICIAL -----------------------------------------------------
	while (escolha==1){
        printf("informe a ORDEM :");
        scanf("%i", &ordem);
        float matrizUnica[3][3];
        float vetorUnico[3];
        for(i=0;i<ordem;i++){
            for(j=0;j<ordem;j++){
                printf("\n Informe o elemento %ix%i :",i+1,j+1);
                scanf("%f", &matrizUnica[i][j]);
            }
        }

        printf("\n..::Selecione uma das opcoes de Normas ::.. \n\n");
        printf ("1- Norma Linha\n");
        printf ("2- Norma Coluna\n");
        printf ("3- Norma Euclidiana\n\n");
        printf ("Opcao: ");
        scanf ("%i", &opcaoMenuNormas);

        switch(opcaoMenuNormas) { //Switch para escolha da opção
            case 1:
                normaLinha(vetorUnico, matrizUnica, ordem);
            break;
        // Fim do primeiro escolha :::::::::::::::

            case 2:
                for (i=0; i<ordem; i++){
                    for (j=0; j<ordem; j++){
                        guardaMaior += matrizUnica[j][i];
                    }
                    vetorUnico[i] = guardaMaior;
                    guardaMaior = 0;
                }
                printf("\nVetor Unico:\n");
                for(i=0 ; i<ordem ; i++)
                {
                    printf("|%.1f| ", vetorUnico[i]);
                }
            break;
        // Fim do segundo  escolha :::::::::::::::
            case 3:
                for(i=0 ; i<ordem ; i++) {
                    for(j=0 ; j<ordem ; j++){
                        guardaMaior += pow(matrizUnica[i][j],2);
                    }
                    guarda_resultado += guardaMaior;
                    guardaMaior = 0;
                }
                guardaMaior = sqrt(guarda_resultado);
                printf("Valor aproximado:\n");
                printf("%6.2f \n", guardaMaior);
            break;
        }
        // Fim do terceiro e ultimo escolha :::::::::::::::
        printf ("\n\nDeseja executar de novo? 1 = SIM 2 = NAO :");
        scanf ("%i", &escolha);
        }// fecha while
	printf("\n\n:::::FIM:::::");
	getch();
}
