#include <math.h>
#include <stdio.h>


// defining Augumented Matrix 

void printmat(int n,double mat[n][n+1]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%.2lf\t",mat[i][j]);
        }
        printf("\n");
    } 
}
// declaration of matrix is done.

//Gauss Elimination pivot check

void gausselim(int n, double A[n][n+1], double x[]) {
    int i, j, k;
    for (i=0; i<n-1; i++){
        if (A[i][i] == 0){
            for (k=i+1; k<n; k++)
            {
                   if (A[k][i]!=0){
                       for (j=0;j<=n;j++){
                           double temp;
                           temp= A[i][j];
                           A[i][j]=A[k][j];
                           A[k][j]=temp;
                       }
                   }
            }
        }

        for (k=i+1;k<n;k++)
        {
            double ratio;
            ratio = A[k][i]/A[i][i];
            for (j=0;j<=n;j++){
                A[k][j]=A[k][j]-ratio*A[i][j];
            }
        }

        printf("\n");
        printf("for k=%d and j= %d", k,j);
        printf("\n\n");
        for (int x=0; x<=n-1;x++){
            for (int y=0; y<=n; y++){
                printf("%.2lf\t", A[i][j]);
            }
            printf("\n");
        }

    }

    printf("\nThe uppter triangular matrix is: \n");
    printmat(n,A);
    if (A[n-1][n-1] == 0){
        printf("\n No Unique solutions exist.");
    }
    else{
        // start back-substitution
        for (i=n-1; i>=0; i--){
            x[i]=A[i][n];
            for (j=i+1;j<n;j++){
                x[i]= x[i]-A[i][j]*x[j];
            }
            x[i]=x[i]/A[i][i];
        }
        printf("\nThe solution of linear equation is:\n");
        for(i=0;i<n;i++){
            printf(" x[%d]=%.2lf\n", i+1, x[i]);
        }

    }
}


int main (){
    int i, n=4;    // no of equations
    // string matrix values

    double a[4][5] = {
                       {1,-1,2,-1,-8},
                        {2,-2,3,-3,-20},
                        {1,1,1,0,-2},
                        {1,-1,4,3,4}

    };
double x[n];
printf("The Augumented matrix is: \n");
printmat(n,a);
gausselim(n,a,x);
}