#include <stdio.h>
#define LIMITE 25

 int main(void)
   {
        int m, n, i, j,
           m1[LIMITE][LIMITE], m2[LIMITE][LIMITE], m3[LIMITE][LIMITE];
       scanf("%d", &m);
        scanf("%d", &n);
       if (m < LIMITE && n < LIMITE)
       {
           for (i = 0; i < m; i = i + 1)
               for (j = 0; j < n; j = j + 1) scanf("%d", &m1[i][j]);
           for (i = 0; i < m; i = i + 1)
               for (j = 0; j < n; j = j + 1) scanf("%d", &m2[i][j]);
           printf("\n");
           for (i = 0; i < m; i = i + 1)
           {
               for (j = 0; j < n; j = j + 1)
               {
                   m3[i][j] = m1[i][j] + m2[i][j];
                   printf("%3d", m3[i][j]);
               }
               printf("\n");
           }
       }
       else printf("Matriz excessivamente grande!\n");
       return 0;
   }
