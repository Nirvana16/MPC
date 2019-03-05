#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 main(){
 	system("color b9");
    float matrizA[3][3]={1,2,1,4,1,3,2,1,1};
    float matrizB[3][3]={4,1,2,2,2,1,1,1,2};
    float AB[3][3];
    float soma;
    int i,j,r,n=3;
    for(i=0; i<3; i++){
      for(j=0; j<3; j++){
      		   soma= 0;
        for(r=0; r<n;r++){
     		   soma+= matrizA[i][r]*matrizB[r][j];
        }
     AB[i][j]= soma;
    }
}
   for(i=0; i<3; i++){
      for(j=0; j<3; j++){
      		   printf(" | %0.f  |", AB[i][j]);
      		   					}
      							    			  				
  			  			}
  getch();  
} 
