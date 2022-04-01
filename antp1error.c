#include<stdio.h>
#include<math.h>
#define pi 3.141592

double factorial(int n){
  int i;
  double fact=1;
  for(i=n;i>=1;i--){
    fact=fact*i;
  }
  return fact;
}
double 
int n
printf("Enter the limiting Error E: ")
scanf("%lf",&E)
printf("Enter the degree of Lagrange Polynomial n: ")
scanf("%d",&n)

//define derivative fucntion

double Fn(double x, int n){
 
 return 
}
// defining Largange Interpolating function
int n;
double Pn(int n,double X[],double Y[],double x)
{
    double sum=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        double prod=1;            //defining Li(x) product function
        for(j=0;j<n;j++)
        {
            if(j!=i)
            prod=prod*(x-X[j])/(X[i]-X[j]);
        }
        sum=sum+prod*Y[i];
    }
    return sum;
}

