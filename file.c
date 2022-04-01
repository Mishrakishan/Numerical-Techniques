#include<stdio.h>
#include<math.h>
int main(){
int i, j;
int n;
double X; //X will be used to approximate f(X).
double x[25]; //The input x values.
double y[25]; //The corresponding y or f(x) values.
double Q[25][25]; //The output table.

// takes the number of input points
printf("how many points are there:");
scanf("%d", &n);

//initializes the Q matrix to zero
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        Q[i][j] = 0.0;

for (i = 0; i<n; i++){
       printf("enter x[%d] and y[%d]:", i,i);
       scanf("%lf %lf",&x[i],&y[i]);
       Q[i][0] = y[i];
    }

//X will be used to approximate f(X).

printf("Enter the x value for which you want to know the f(x) for:" );
scanf("%lf", &X);

//Neville's method.

for (i = 1; i < n; i++) {
    for (j = 1; j <= i; j++) {
        Q[i][j] = ((X - x[i - j])*(Q[i][j - 1]) 
                        - (X - x[i])*(Q[i - 1][j - 1]))/(x[i] - x[i - j]);
    }
}

printf("The final Q matrix:\n");
for(i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        printf("%9f ", Q[i][j]);
    }
    printf("\n");
}
}