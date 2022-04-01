#include<stdio.h>
#include<math.h>


double derive(double (*f)(double), double x0)
{
    const double delta = 1.0e-6; // or similar
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

// call it as follows: 
#include <math.h>

int main() {


double der = derive(sin, 0.0);
printf("%lf\n", der); // should be around 1.0


}

/* typedef double (*TFunc)(double);

// general approximation of derivative using central difference
double diff(TFunc f, double x, double dx=1e-10)
{
  double dy = f(x+dx)-f(x-dx);
  return dy/(2.*dx);
}

// more or less arbitrary function from double to double:
double f(double x)
{
   return x*x;
}

// and here is how you get the derivative of f at specified location
double fp = diff(f, 5.); */



// nth derivtaive

/* double func(double x)
{
    // a mathematical expression representing a smooth curve 
    //returns the value of the function at x      
}
double nthderive(double (*f)(double),double x0,int n)
{   
   const double delta=1.0e-8;
   double x1=x0 - delta;
   double x2=x0 + delta;
   if(n==0) {
       return f(x0);
   }
   else {
       return (nthderive(f,x2,n-1)-nthderive(f,x1,n-1))/(2*delta);
   }
}  */