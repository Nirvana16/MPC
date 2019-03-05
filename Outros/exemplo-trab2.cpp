// Ler uma matriz quadrada de ordem 4 e a seguir verificar se a matriz informada
// e uma matriz triangular superior. Na matriz triangular superior todos os
// elementos abaixo da diagonal principal sao iguais a zero:
// para todo i > j, Ai,j == 0.

#include <stdio.h>

int main() {
  #define n 4 // ordem da matriz quadrada
  int i, j, m[n][n]; // matriz quadrada

// entrada de dados
  for (i=0; i<n; i++) {
    printf("Informe os elementos da %da. linha:\n", (i+1));
    for (j=0; j<n; j++) {
      printf("m[%d][%d] = ", i, j);
      scanf("%d", &m[i][j]);
    }
    printf("\n");
  }

// processamento: verificando se a matriz informada eh uma matriz triangular superior
  int ehsuperior = 1;
  for (i=0; (i<n)&&(ehsuperior==1); i++) {
// percorrendo os elementos abaixo da diagonal principal
    for (j=0; (j<i)&&(ehsuperior==1); j++) {
// verificando se os elementos abaixo da diagonal principal sao iguais a zero
      if (m[i][j] != 0)
         ehsuperior = 0;
    }
  }

// saida: exibindo a matriz informada e indicando se ela eh uma matriz triangular superior
  printf("\n");
  for (i=0; i<n; i++) {
    printf("%da. linha: ", (i+1));
    for (j=0; j<n; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  if (ehsuperior == 1)
     printf("\nA matriz informada eh uma matriz triangular superior.\n");
  else printf("\nA matriz informada \"nao\" eh uma matriz triangular superior.\n");
}
