#include<stdio.h>
#include<math.h>

double factorial(int n){
  int i;
  double fact=1;
  for(i=n;i>=1;i--){
    fact=fact*i;
  }
  return fact;
}

//function is: log(x)
//f'=1/x; f''=-1/x^2; fn=(-1)^{n-1}* (n-1)!/x^n 

float poly(float x, int n)
{
    //return ((-1)^(n+1)*factorial(n)/x^(n+1));
    return ((pow(n+1,-1))*factorial(n)/(pow(n+1,x)));
}
//for 3 data points
float g(float x)
{
    return ((x-2)*(x-2.75)*(x-4));
}

float f(float x)
{
    return (3*x*x-17.5*x+24.5);
}

// Lagrange Interpolation Error

//Error Formula for Pn (n order polynomial)

/* E_n(x,f)=|f^(n+1)(eta(x)/(n+1)!)||(x-x0)(x-x1).....(x-xn)| */
/*

int n;
double fn(int n, double x, double X[], double Y[])
{
    double Error=log(x);
    int i,j;
    for (i=0;i<n;i++)
    {
        double Pn=1;
        for(j=0;j<n;j++)
        {
            Pn=(x-X[j]);
        }
        Error=Error*Pn;
    }
    return Error;
}*/



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

//Largange Interpolation

int main() {


    int i;
    double x;
    FILE*fp=NULL;
    fp=fopen("antp1.txt","w");
    // initialing array
	double X[]={2,2.75,4};
	double Y[]={0.5,0.3637,0.25};

    printf("Enter the value of x at which the function is to be calculated: \n");
    scanf("%lf",&x); 

    printf("Langrage interpolated value at x=3 is %lf\n",Pn(3,X,Y,x));


    // for interval of 0.05 wwith initial and final values

    for (x=2;x<=4;x+=0.01)
    {
    	fprintf(fp,"%lf\t%lf\t%lf\t\n",x,Pn(3,X,Y,x),1/x);
    }
    
    printf("Enter the order of polynomial \n");
    scanf("%d",&n); 
    //printf("%lf",fn(n,x,X,Y));

//bisection method for roots and maximum value of polynomial

  {
    float x, xm, xl, xr, acc=0.00001, xinc = 0.5, z, a, b, x1, x2;
    int n, i;
    float f(float x);
    printf ("Enter the minimumm value of x \n");
    scanf ("%f", &a);
    printf("Enter the maximum value of x \n"); 
    scanf ("%f", &b);

    for ( x=a ; x<=b ; x=x+0.1)
{
    printf( "%f \t %f \n" , x , f(x)) ;
}

    printf("intput no of roots");
    scanf("%d", &n);

    for (i=1;i<=n;i+=1)
    {
        printf("\ninput x1,x2");
        scanf("%f,%f",&x1,&x2);
        for(x=x1;x<=x2;x+=xinc)
        {
            if (f(x)*f(x+xinc)<0)
            {
                x1=x; xr=x+xinc;

            
            do
            {
                xm=(x1+xr)/2.0;  
                if (f(xm)*f(x1)>0)
                {x1=xm;}
                if (f(xm)* f(x1)<0)
                {xr=xm;}
                z=fabs ((x1-xr)/(x1+xr));
                printf ("xm=%f  f(xm)= %f  z=%f acc=%f\n", xm, f(xm), z, acc);
            } while (z>acc   /* condition */);
            printf("\nroots=%f  f(xm)=%f  z=%f  g(xm)=%f  acc= %f\n\n", xm, f(xm),z, g(xm), acc);
            } 

            
        }
    } 
    
//calculation of Error
float Error, k;
 printf ("Enter the obtained maximum value of abs(g(xm))\n: ");
 scanf ("%f", &k);

 
 Error= fabs(poly(x,n))*fabs(g(xm));
 printf("fabs(poly(x,n) ====>%f\n ", poly(2,n));
 printf("Evaluated error in Lagrange Interpolation is====> %f\n", Error);

  }
}