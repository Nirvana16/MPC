#include<conio.h>
#include<stdio.h>
#include<math.h>
// add #include<conio.h> if you are on windows
 
// function prototype
float norm(int [][10],int,int);
// main function
int main()
{
  // variable declaration
  int ar[10][10],i,j,n,m;
  float nrm;
 
  printf("Enter number of rows for matrix: ");
  // number of rows
  scanf("%d",&n);
 
  printf("Enter number of columns for matrix: ");
  // number of columns
  scanf("%d",&m);
 
  // scanning matrix
  printf("Enter matrix elements: \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      scanf("%d",&ar[i][j]);
    }
  }
 
  // displaying matrix
  printf("Matrix elements are: \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      printf("  %d",ar[i][j]);
    }
    printf("\n");
  }
 
  // function call by parameters
  nrm=norm(ar,n,m);
  printf("\nnorm of matrix is: %f\n",nrm);
 
}
 
/*
    function declaration with
    return type: "float"
*/
float norm(int ar[][10],int n,int m)
{
 
  int i,j;
  float sum,nrm;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      sum=sum+pow(ar[i][j],2);
    }
  }
  //sqrt(parameter) function for square root, declared in math.h
  nrm=sqrt(sum);
 
  // return float value to function call
  return nrm;
}
