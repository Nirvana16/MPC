#include<stdio.h>
#define MX 20
#include<conio.h>


main()
{
    float a[MX] [MX+1],m,p;
    int i,j,k,n;

    puts("\n how many equations?:");
    scanf("%d",&n);


    for(i=0;i<=n-1;i++)
    {
        printf("Give the coefficients of the equation no: %d\n",i+1);
        for(j=0;j<=n;j++)
        scanf("%f",&a[i][j]);
    }

    for(k=0;k<=n-1;k++)
    {
        for(i=0;i<=n-1;i++)
        {
            m=a[i][k]/a[k][k];
            p=a[k][k];

            for(j=k;j<=n;j++)
            {
                if(i==k)
                a[i][j]=a[i][j]/p;

            else
                a[i][j]=a[i][j]-m*a[k][j];
            }
        }
    }

for(i=0;i<=n-1;i++)
printf("\n X[%2d]=%5.2f",i,a[i][n]);


getch();
}
