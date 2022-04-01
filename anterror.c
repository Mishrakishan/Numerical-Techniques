// finding root using Bisection Method
#include<stdio.h>
#include<math.h>
 
 /* defining interpolation function */

int n;
double Pn(int n,double X[],double Y[],double x)
{
    double sum=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        // initiating product part
        double Li=1;
        for(j=0;j<n;j++)
        {
            if(j!=i)
            Li=Li*(x-X[j])/(X[i]-X[j]);
        }
        sum=sum+Li*Y[i];
    }
    return sum;
}

// Error formula 
// E_n(x)=f^(n+1)(eta x)/)(n+1)!(x-x0)...(x-xn)
// defining the function
float f1(float x)
{
  return -sin(x);
}

float f2(float x)
{
    return (x-2)*(x-2.75)*(x-4)*1/6;
}
 
int main()
{
    int i;
    double x;
    FILE*fp=NULL;
    fp=fopen("anterror.txt","w");
    // initialing array
    double X[]={2,2.75,4};
    double Y[]={0.5,0.3637,0.25};

  for (x=2;x<=4;x+=0.01)
    {
    	fprintf(fp,"%lf\t%lf\t%lf\t%f\t%f\t\n",x,Pn(3,X,Y,x),1/x,f1(x),f2(x));
    }
}


