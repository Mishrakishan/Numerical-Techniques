#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"linear.c"

void gaussjordan(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n;i++){
        //Partial Pivoting
        for(k=i+1;k<n;k++){
            //If the diagonal element (absolute value) is smaller than any of the terms below it
            if(fabs(A[i][i])<fabs(A[k][i])){
                //Swap the rows in the matrix
                for(j=0;j<=n;j++){                
                    double temp;
                    temp=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=temp;
                }
            }
        }

        //Begin the Gauss Jordan
        for (k=0;k<n;k++)
        {
            if (k!=i){   
                double term;
                term=A[k][i]/A[i][i];
                for (j=0;j<=n;j++)
                {
                    A[k][j]=A[k][j]-term*A[i][j];
                }
            }
        }        
    }
    
    if (A[n-1][n-1]==0){
        printf("\nSorry! No unique solution exists.");
    }
    else{
        printf("\nThe diagonal augmented matrix:\n");
        printmat(n,A);
        // getting the x array
        for (i=0;i<n;i++){
            x[i]=A[i][n]/A[i][i];
        }  
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++){
            printf(" x[%d]= %.2lf\n",i+1,x[i]);
        }  
    }       
}

int main()
{
    int i,n=4;  // no of equations
    //Declare a matrix to store the user given matrix
    double a[4][5]={
                        {1,-1,2,-1,-8},
                        {2,-2,3,-3,-20},
                        {1,1,1,0,-2},
                        {1,-1,4,3,4}
                    };
    //Declare an array to store the solution of equations
    double x[n];
    printf("The augmented matrix:\n");
    printmat(n,a);  // printing the augmented matrix
    gaussjordan(n,a,x);   // Perform Gauss jordan
}
