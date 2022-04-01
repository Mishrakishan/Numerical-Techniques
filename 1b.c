// problem 1b
// make sure "linear.c" file is in the same directory
#include<stdio.h>
#include<math.h>
// #include"linear.c"

void printmat(int n,double mat[n][n+1])
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%.2lf\t",mat[i][j]);
        }
        printf("\n");
    }
}
//Gaussian Elimination

void gausselim(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        if (A[i][i]==0){
            for(k=i+1;k<n;k++)
            {
                if (A[k][i]!=0){
                    for(j=0;j<=n;j++){
                        double temp;
                        temp=A[i][j];
                        A[i][j]=A[k][j];
                        A[k][j]=temp;
                    }
                }
            }
        }
        // Gauss Elimination
        for(k=i+1;k<n;k++)
        {
            double term;
            term=A[k][i]/A[i][i];
            for(j=0;j<=n;j++){
                A[k][j]=A[k][j]-term*A[i][j];
            }
        }        
    }

    printf("\nThe upper triangular matrix:\n");
     printmat(n,A);
    if (A[n-1][n-1]==0){
        printf("\nSorry! No unique solution exists.");
    }
    
    else{
        //Start with the back-substitution
        for(i=n-1;i>=0;i--){
            x[i]=A[i][n];
            for(j=i+1;j<n;j++){
                x[i]=x[i]-A[i][j]*x[j];
            }
            x[i]=x[i]/A[i][i];
        } 
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++){
            printf(" x[%d]= %.2lf\n",i+1,x[i]);
        }
    }          
}

int main()
{
    int i,n=5;  // no of equations
    //Declare a matrix to store the user given matrix
    double a[5][6]={
                        {2,1,-1,1,-3,7},
                        {1,0,2,-1,1,2},
                        {0,-2,-1,1,-1,-5},
                        {3,1,-4,0,5,6},
                        {1,-1,-1,-1,1,3}
                    };
    //Declare an array to store the solution of equations
    double x[n];
    printf("The augmented matrix:\n");
   // printmat(n,a);  // printing the augmented matrix
    gausselim(n,a,x);   // Perform Gauss Elimination 
}