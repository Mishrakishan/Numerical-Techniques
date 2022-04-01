
#include<stdio.h>
 
/*Function to evaluate Li(x)*/
 
double Li(int i, int n, double x[], double X)
{
    int j;
    double prod=1;
    for(j=0;j<=n;j++){
        if(j!=i)
            prod=prod*(X-x[j])/(x[i]-x[j]);
    }
        return prod;
}
 
/*Function to evaluate Pn(x) where Pn is the Lagrange interpolating polynomial of degree n*/
 
double Pn(int n, double x[], double y[], double X){
    double sum=0;
    int i;
    for(i=0;i<=n;i++){
        sum=sum+Li(i,n,x,X)*y[i];
    }
    return sum;
}
int main()
{
    int i;
    FILE*fp=NULL;
    fp=fopen("antp2.txt","w");
    // initialing array
	double x[]={2,2.75,4};
	double y[]={1/(int)2,1/(double)2.75,1/(int)4};

	double X=3;  //value of x for which interpolated value is required

    printf("Langrange interpolated value at x=3 is %lf",Pn(2,x,y,X));

    // for interval of 0.05 wwith initial and final values

    for (X=2;X<=4;X+=0.05)
    {
    	fprintf(fp,"%lf\t%lf\t%lf\t\n",X,Pn(2,x,y,X),1/X);
    }
}