#include<stdio.h>
#include<conio.h>


int main (){

	int i, j, k;
	float soma;
	float A[3][3] = {3,2,4,1,1,2,4,3,-2};
	float L[3][3] = {1,0,0,0,1,0,0,0,1};
	float U[3][3] = {0,0,0,0,0,0,0,0,0};
	float b[3] = {1,2,3};
	float y[3];
	float x[3];



	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			soma=0;
			/* Cálculo do termo genérico de U */
			if (i<=j){
				for (k=0;k<i;k++)
					soma+=L[i][k]*U[k][j];

				U[i][j]=A[i][j]-soma;
			}
			/* Cálculo do termo genérico de L */
			else{
				for (k=0;k<j;k++)
					soma+=L[i][k]*U[k][j];

				L[i][j]=(A[i][j]-soma)/U[j][j];
			}
		}
	}
/* Printa L */
	printf("Matriz L\n");
	for(i=0;i<3;i++){
             for(j=0;j<3;j++){
                      printf("%.2f ",L[i][j]);
                      if(j==2)
                             printf("\n");
            }
    }
    printf("\n");
/* Printa U */
	printf("Matriz U\n");
    for(i=0;i<3;i++){
             for(j=0;j<3;j++){
                      printf("%.2f ",U[i][j]);
                      if(j==2)
                             printf("\n");
            }
    }
    printf("\n");
/* L*U*x=b --> L*y=b Baseado na matriz inferior "L"*/
	y[0]=b[0]/L[0][0];
	for(i=0;i<3;i++){
		soma=0;

		for(j=0;j<i;j++){
			soma+=L[i][j]*y[j];
		}
		y[i]=(b[i]-soma)/L[i][i];

	}
/* Printa Y */
	printf("Matriz Y\n");
	for(i=0;i<3;i++){
    	printf(" %.2f",y[i]);
		printf("\n");
    }
	printf("\n");
/* U*x=y Baseado na matriz superior "U" */
	x[2]=y[2]/U[2][2];
	for(i=1;i>=0;i--){
		soma=0;

		for(j=i+1;j<3;j++)
			soma+=U[i][j]*x[j];

		x[i]=(y[i]-soma)/U[i][i];
	}
/* Printa X */
	printf("Matriz X\n");
	for(i=0;i<3;i++){
    	printf(" %.2f",x[i]);
		printf("\n");
    }
    getch();
}
