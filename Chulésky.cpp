#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	int i, j, k;
	float A[3][3] = {1,1,0,1,2,-1,0,-1,3}, soma, U[3][3], Ut[3][3], b[3] = {2,1,5}, x[3], y[3];

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			soma = 0;
			if(i==j){
				for(k=0; k<i; k++){
					soma+= U[k][i] * U[k][i];
				}
				U[i][i] = sqrt(A[i][i] - soma);
			}
			else if(i<j){
				for(k=0; k<i; k++){
					soma+= U[k][i] * U[k][j];
				}
				U[i][j] = (A[i][j] - soma) / U[i][i];
			}
			else if(i>j){
				U[i][j] = 0;
			}
		}
	}

	printf("U \n\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%.2f   ", U[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			Ut[i][j] = U[j][i];
		}
	}
	printf("\n\n");

	printf("Ut \n\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%.2f   ", Ut[i][j]);
		}
		printf("\n");
	}
	y[0] = b[0] / Ut[0][0];

	for(i=0; i<3; i++){
		soma=0;
		for(j=0; j<i; j++){
			soma+= Ut[i][j] * y[j];
		}
		y[i] = (b[i] - soma) / Ut[i][i];
	}
	printf("\n\n");

	printf("y \n\n");
	for(i=0; i<3; i++){
			printf("%.2f \n", y[i]);
	}
	x[2] = y[2] / U[2][2];

	for(i=1; i>=0; i--){
		soma=0;
		for(j=i+1; j<3; j++)
			soma+= U[i][j] * x[j];
		x[i] = (y[i] - soma) / U[i][i];
	}
	printf("\n\n");

	printf("x \n\n");
	for(i=0; i<3; i++){
			printf("%.2f \n", x[i]);
	}
	getch();
}
