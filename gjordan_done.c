#include<stdio.h>
#include<math.h>

//Gauss Jordan with partial pivoting
// Parameters: (n) of the eq/row, mat[n][n+1], x[n]

int main(){

    int i,j,k,n;
    float A[10][10],ratio,x[10],sum=0.0;
    printf("Enter the order of the matrix\n");
    scanf("%d", &n);
    printf("\nEnter the element of augumented matrix row-wise:\n\n");
    for (i=1;i<=n;i++){
        for (j=1;j<=n+1;j++){
            printf("A[%d][%d]:", i,j);
            scanf("%f", &A[i][j]);         
        }
    } 

    printf("\n The Augmented Matrix is:\n");
    for (i=1; i<=n; i++){
        for (j=1; j<=n+1; j++){
            printf("%.2lf\t", A[i][j]);
        }
        printf("\n\n");
    }

    //gauss jordan 

    //partial pivoting method 

    for (i=1; i<=n; i++){
        //row checking 
        for (k=i+1; k<=n; k++){
            if (fabs(A[i][i])<A[k][i]){
                //swap the rows
                for (j=1; j<=n+1; j++){
                    double temp;
                    temp=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=temp;
                }
            }
        }


        //Begin Gauss Jordan

        for (k=1; k<=n; k++){
            if (k!=i){
                float ratio;
                ratio = A[k][i]/A[i][i];
                for (j=1; j<=n+1; j++){
                    A[k][j]=A[k][j]-ratio*A[i][j];

                    //printf("\n");
                    //printf("for j=%d and k=%d", j, k);
                    //printf("\n\n");
                    //for (int x=1;x<=n;x++){
                    //for (int y=1; y<=n+1; y++){
                    //printf("%f\t",A[x][y]);

                } 
                printf("\n");
        }
                }
            
            }
            
    

    if (A[n-1][n-1] == 0){
       printf("\n No unique Solution exits.");
    }

    else{

        printf("The diagonal matrix is:\n");
        for (int x=1; x<=n; x++){
            for (int y=1; y<=n+1; y++){
                printf("%.2lf\t", A[x][y]);

            }
            printf("\n\n");
        }

        for (i=1; i<=n; i++){
            x[i]=A[i][n+1]/A[i][i];
        }
        printf("The solution of the linear equation is: \n");
        for (i=1; i<=n; i++){
            printf("\nx[%d] = %.2lf\t", i, x[i]);
        }
        return(0);
    }
}