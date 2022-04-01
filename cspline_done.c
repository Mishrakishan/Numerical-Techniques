#include <math.h>
#include<stdio.h>

//Lagrange Interpolation
double lagrange(int n, double X[], double Y[], double x){
    // n = no of points (n-1 order of polynomial)
    double sum=0;
    int i, j;
    for (i=1; i<=n; i++){
        //initiating product part
        double prod =1;
        for (j=1; j<=n; j++){
            if (j!=i)
            prod = prod*(x-X[j])/(X[i]-X[j]);
        }
        sum = sum + prod*Y[i];
    }
    return sum;
}


// Cubic Spine
double csplines(int n, double x[], double a[], double X){

    double h[n], alpha[n], l[n+1], u[n+1], z[n+1], c[n+1], b[n], d[n];
    double sum;
    int i, j;

    for (i=0; i<=n-1; ++i)
        h[i]=x[i+1]-x[i];

    for (i=1; i<=n-1; i++)
         alpha[i]=(3/h[i])*(a[i+1]-a[i])-(3/h[i-1])*(a[i]-a[i-1]);

        l[0]=1;
        u[0]=0;
        z[0]=0;

    for (i=1; i<=n-1; i++)
    {
        l[i]=2*(x[i+1]-x[i-1])-(h[i-1]*u[i-1]);
        u[i]=h[i]/l[i];
        z[i]=(alpha[i]-h[i-1]*z[i-1])/l[i];
    }

        l[n]=1;
        c[n]=0;
        z[n]=0;

    for (j= n-1; j>=0; j--)
    {
        c[j]=z[j]-u[j]*c[j+1];
        b[j]=(a[j+1]-a[j])/h[j]-(h[j]*(c[j+1]+2*c[j]))/3;
        d[j]=(c[j+1]-c[j])/(3*h[j]);
    }
    for (j=0; j<=n-1; j++){
        if (X>x[j] && X<x[j+1])
        {
        sum= a[j]+b[j]*(X-x[j])+c[j]*pow((X-x[j]),2)+d[j]*pow((X-x[j]),3);
        }
    }

    return sum;
}

// Simpson's 1/3 method
double simpson(double, f(double x), double a, double b){
    int i, n=2;
    double integral,answer,x,h,sum,accuracy=0.0001;
    do{
        integral = answer;
        h = fabs(b-a)/2;
        sum=0;
        for (i=1; i<n; i++){
            x=a+i*h;
            if (i%2==0){
                sum=sum+2*f(x);
            }
            else{
                sum=sum+4*f(x);
            }
        }
        answer = h/3*(f(a)+f(b)+sum);
        n=n+2;
        while (fabs(answer-integral)>=accuracy);
    }
    return answer;
}


// problem 1 and 2
// make sure "csplines.c" file is in the same directory
#include<stdio.h>
#include<math.h>
// include"csplines.c"

// main program to do our job
int main()
{
	double X;
	double x[]={0,1,2,3};
	double y[]={exp(0),exp(1),exp(2),exp(3)};
	FILE*fp=NULL;
	fp=fopen("csp.txt","w");
	for (X=0;X<=3;X+=0.01)
	{
		fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",X,csplines(4,x,y,X),exp(X),lagrange(4,x,y,X));
	}
    
}
