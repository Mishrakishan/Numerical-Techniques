//C Program to Implement Gauss Elimination Method
#include<stdio.h>
#include <math.h>

int main(){
    int i,j,k,n;
    float A[10][10], ratio, x[10], sum=0.0;
    printf("Enter the order of matrix\n");
    scanf("%d", &n);
    printf("\nEnter the elements of Augumented matrix row-wise:\n\n");
    for (i=1; i<=n;i++){       //n =1  1 to 3
        for (j=1;j<=n+1;j++){    // 1 to 4
        printf("A[%d][%d]:", i, j);
        scanf("%f", &A[i][j]);
        }
    }

    printf("\nThe Augmented matrix is: \n");
    for (i=1; i<=n;i++){       //n =1  1 to 3
        for (j=1;j<=n+1;j++){
        printf("%.2lf\t", A[i][j]);
        }
        printf("\n\n");
    }
    

    //Gauss Elimnation Process
    for (j=1; j<=n; j++){
        for (i=1;i<=n; i++){
            if (i>j){
                ratio = A[i][j]/A[j][j];
                for (k=1; k<=n+1; k++){
                    A[i][k]=A[i][k]-ratio*A[j][k];
                }
            }
            printf("\n");
            printf("for j=%d and i=%d", j, i);
            printf("\n\n");
            for (int x=1;x<=n;x++){
                for (int y=1; y<=n+1; y++){
                    printf("%f\t",A[x][y]);

                } 
                printf("\n");
            }
        }
        
    }

    //The Upper triangular matrix is obtained!
    //Backward substitution is initiated.

    if (A[n][n]==0){
        printf("\nSorry! No unique solution exists.");
    }
    
    else{

    

    x[n]=A[n][n+1]/A[n][n];
    for (i=n-1;i>=1;i--){
        sum=0.0;
        for (j=i+1;j<=n;j++){
            sum = sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("THe solution is : \n");
    for (i=1; i<=n; i++){
        printf("\nx[%d]=%f\t",i,x[i]);
    }
    return(0);
}
}