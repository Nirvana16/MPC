#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
        float **a,*temp,app,sum,mult;
        int i,j,k,n,p;
//take no of terms
        printf("Enter n : ");scanf("%d",&n);
//memory allocation
        a = (float**)malloc(n*sizeof(float*));
        for(i = 0; i < n; i++)
            a[i] = (float*)malloc(n*sizeof(float));
        temp = (float*)malloc(n*sizeof(float));
//take input from user
        printf("Enter the elements of augmended matrix rowwise\n");
        for(i=0;i<n;i++)
            for(j=0;j<=n;j++)
                scanf("%f",&a[i][j]);
//generation of scalar matrix
       for(i=0;i<(n);i++){
            app = a[i][i];
//initialization of p
            p = i;
//find largest no of the columns and row no. of largest no.
            for(k = i+1; k < n; k++)
            if(fabs(app) < fabs(a[k][i])){
               app = a[k][i] ;
               p = k;
            }
//swaping the elements of diagonal row and row containing largest no
            for(j = 0; j <= n; j++)
            {
                temp[j] = a[p][j];
                a[p][j] = a[i][j];
                a[i][j] = temp[j];
            }
//calculating triangular matrix
            for(j=i+1;j<n;j++){
                mult = a[j][i]/a[i][i];
                for(k=0;k<=n;k++)
                    a[j][k] -= mult*a[i][k];
            }
       }
//for calculating value of z,y,x via backward substitution method
        for(i=n-1;i>=0;i--)
        {
            sum = 0;
            for(j=i+1;j<n;j++)
                sum += a[i][j]*temp[j];
            temp[i] = (a[i][n]-sum)/a[i][i];
        }
        printf("****The matrix is : ***\n");
        for(i=0;i<n;i++){
            for(j=0;j<=n;j++)
                printf("%.2f\t",a[i][j]);
            printf("\n");
        }
//display solution
        printf("-------------The solution is ----------\n");
        for(i=0;i<n;i++)
        printf("X[%d] = %.2f\n",i+1,temp[i]);
//free allocated memory
        for(i = 0; i < n; i++)
            free(a[i]);
        free(a);
        free(temp);
    return 0;
}
