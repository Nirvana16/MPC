#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void main(){
    float pivo=0, m, Mab[3][4]={{2,3,-1,-7},{1,1,1,4},{-1,-2,3,15}};
    int i,j,k,ordem=3;

    for (i=0; i<ordem;i++){
        pivo = Mab[i][i];
        for (j=0; j<ordem+1;j++){
            Mab[i][j]= Mab[i][j]/pivo;
        }
        for (k=0; k<ordem; k++){
            if (i != k){
                m = Mab[k][i];
                for(j=0;j<ordem+1;j++){
                    Mab[k][j]=Mab[k][j] - (Mab[i][j]*m);
                } //x4
            }
        }
    }
    printf("Matriz AB = ");
    for (i=0;i<ordem;i++){
        printf("\n");
        for (j=0;j<ordem+1;j++){
            printf("|%.1f| ",Mab[i][j]);
        }
    }
    getch();
}
