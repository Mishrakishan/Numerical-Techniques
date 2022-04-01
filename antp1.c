#include<stdio.h>
#include<math.h>

// Lagrange Interpolation


//defining variable: 
//for given data points X[] is x-array, Y[] is y-array, x is point where to calculate value, n is order of langrange polynomial

/*float(float x)
{
    return 1/X;
}*/

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

/*defining the given points */

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

    printf("Langrage interpolated value at x=3 is %lf",Pn(3,X,Y,x));


    // for interval of 0.05 wwith initial and final values

    for (x=2;x<=4;x+=0.01)
    {
    	fprintf(fp,"%lf\t%lf\t%lf\t\n",x,Pn(3,X,Y,x),1/x);
    }


                  // Absolute Error Evaluation 

{
	int i, n=3;   // for n data points
 	double x[]={2,2.75,4};
 	double y[n], X=3;

 	printf("\n\n Given function f(x)=1/x");
 	for(i=0;i<n;i++)
 	{
 		y[i]=1/x[i];
 	}
 	printf("\n P2(x)=%f\n",Pn(n,x,y,X));
 	printf("Absolute Error:%f\n",fabs(Pn(n,x,y,X)-1/X));
}
/*do{
    h=(x[1]-x[n])/n;
    for (i=0;i<n;i++)
    {
        x[i]=a+h*i;
        y[i]=f(x[i]);
        printf("%f\t%f\n", x[i],y[i]);
    }
    absErr=fabs(f(n)-Pn(n,x,y,X))
}
*/
}