#include <stdio.h>
#include <stdlib.h>

double Lagrange(int n, int k,double value);
double* fx;
double* x;
double Calculate(int n, double x);
 int main() {
	int size;
	double question;
	printf("Please enter function's point count:\n");
	scanf("%d", &size);

	fx = (double*)malloc(sizeof(double)*size);
	x = (double*)malloc(sizeof(double)*size);
	for (int i = 0; i < size; i++)
	{
		printf("Enter  x(%d):", i);
		scanf("%lf", &x[i]);		
		printf("Enter fx(%d):", i);
		scanf("%lf", &fx[i]);
		printf("------\n");
	}
	printf("Please enter point to calculate:\n");
	scanf("%lf", &question);
	printf("\n");
	printf("Result =====> f(%4.2lf) = %5.4lf\n",question, Calculate(size, question));
	printf("\n");
	system("PAUSE");
}

double Lagrange(int n, int k, double val)
{
	double result = 1;
	for (int i = 0; i < n; i++)
	{
		if (i!=k)		
			result = result * (double)((val - x[i]) / (x[k] - x[i]));		
	}
	return result;
}

double Calculate(int n,double x)
{
	double intPolasyon = 0;
	double *L = (double*)malloc(sizeof(double)*n);
	double *F = (double*)malloc(sizeof(double)*n);
	for (int i = 0; i < n; i++)s
	{
		L[i] = Lagrange(n, i, x);		
		intPolasyon += fx[i] * L[i];
		printf("L(%d) = %5.3lf\n", i, L[i]);
	}
	
	printf("\n");
	return intPolasyon;
}