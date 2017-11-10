#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//function prototypes
void matrixgen(int n, double array[n][n]);
void matrixdisplay(int n,double array[n][n]);

//functions used
 void matrixgen(int n,double array[n][n])
{
  int i,j;
  srand48(time(NULL));
  for(i=0;i<n;i++)
  {
    for(j=0;j<i;j++)
    {
      array[j][i]=array[i][j]=1000*(drand48());
    }
    array[i][i]=0;
  }
}

void matrixdisplay(int n,double array[n][n])
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%lf\t",array[i][j]);
    printf("\n");
  }

}

//main
int main(int argc,char **argv)
{
  if(argc!=2)
  {  printf("\nWrong number of arguments\n");
    return 1;
  }
  else
  {
    int N=atoi(argv[1]);
    double nodematrix[N][N];
    //printf("%d\n",N);
    matrixgen(N,nodematrix);
    matrixdisplay(N,nodematrix);
    return 0;
  }
}
