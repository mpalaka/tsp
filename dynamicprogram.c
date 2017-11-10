#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int n,cost,connected[100];
double array[100][100];

//function prototypes
void matrixgen();
void matrixdisplay();
void traveller(int current);
int closest(int current);


//functions used
 void matrixgen()
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

void matrixdisplay()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%lf\t",array[i][j]);
    printf("\n");
  }

}

void traveller(int current)
{
  int i,next;
  connected[current]=1;
  printf("%d\t",current);
  next=closest(current);

  if(next==-1)
  {
    next=0;
    printf("%d\n",next);
    cost+=array[current][next];
  }
  else
  {
    traveller(next);
  }
}

int closest(int current)
{
  int i,next=-1;
  float min=9999,mincost;

  for(i=0;i<n;i++)
  {
    if(((array[current][i]!=0)&&(connected[i]==0))&&(array[current][i]+array[i][current]<min))
    {
        min=array[i][0]+array[current][i];
        mincost=array[current][i];
        next=i;
    }
  }

  if(min!=9999)
    cost+=mincost;

  return next;
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
    n=atoi(argv[1]);
    int i;
    for(i=0;i<n;i++)
      connected[i]=0;
    //printf("%d\n",N);
    matrixgen();
    printf("\nThe generated matrix:\n");
    matrixdisplay();
    printf("\n The order followed is\n");
    traveller(0);
    return 0;
  }
}
