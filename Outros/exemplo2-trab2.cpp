#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
int ele[9][9],i=0,j=0,ordem;
int somts=0, somti=0,somdp=0;
printf ("digite a ordem da matriz: ");
scanf ("%d", &ordem);
ordem=ordem-1;
//preenchendo a matriz
for (i=0; i<=ordem; i++){
for (j=0; j<=ordem; j++){
printf ("digite o elemento %dX%d: ",i+1,j+1);
scanf ("%d",&ele[i][j]);
}
}
//imprimindo a matriz
for (i=0; i<=ordem; i++){
for (j=0; j<=ordem; j++){
printf ("%d ",ele[i][j]);
}
printf ("\n");
}
//teste triangular superior
for (i=0; i<=ordem-1; i++){
if (ele[i+1][i]!=0)
somts=somts+1;
}
//teste triangular inferior
for (i=0; i<=ordem-1; i++){
if (ele[i][i+1]!=0)
somti=somti+1;
}
//teste diagonal principal
for (i=0; i<=ordem; i++){
if (ele[i][i]!=0)
somdp=somdp+1;
}
if ((somdp==0)&&(somti==0)&&(somts==0))
printf ("\ntodos os elementos sao zero");
else
if ((somts!=0)&&(somti==0))
printf ("\neh uma matriz triangular inferior");
else
if ((somts==0)&&(somti!=0))
printf ("\neh uma matriz triangular superior");
else
if ((somts==0)&&(somti==0)&&
(somdp==ordem+1))
printf ("\neh uma matriz diagonal");
else
printf ("eh uma matriz comum");

system ("pause");
}
