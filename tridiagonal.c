#include<stdio.h>
#include<math.h>

int main(){
    //defining matrix
    float A[10][10], x[10], ratio;
    int i, j, k, n;
    printf("Enter the order of matrix:\n");
    scanf("%d", &n);
    printf("Enter the elements of Augumented matrix row-wise:\n\n");
    for (i=1; i<=n; i++){
        for (j=1; j<=n+1; j++){
            printf("A[%d][%d]:", i, j);
            scanf("%f", &A[i][j]);   
        }
    }

    printf("\nThe Augumented matrix is: \n");
    for (i=1;i<=n; i++){
        for (j=1;j<=n+1;j++){
            printf("%.2lf\t", A[i][j]);
        }
        printf("\n\n");
    }

    //Begin Gauss Eliminaion

    for (k=i+1; k<=n;k++){
        ratio =  A[k][i]/A[i][i];
        for (j=1; j<=n; j++){
            A[k][j]=A[k][j]-ratio*A[i][j];
        }
        A[k][n-1]=A[k][n-1]-ratio*A[i][n-1];
    }

    //Back substitution
    for (i=n; i>=1; i--){
        x[i]=A[i][n];
        j=i+1;
        x[i]=x[i]-A[i][j]*x[j];
        x[i]=x[i]/A[i][i];
    }

    for (i=1;i<=n; i++){
        for(j=1; j<=n; j++){
            printf("%lf\t", A[i][j]);
        }

        printf("\n");
    }
    
}