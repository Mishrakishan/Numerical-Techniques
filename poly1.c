#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653

float funtion_( float x)
{
 
 
 float result = 0;
    result = (-sin(PI * x));
    return result;
}

int main()
{
    float A = 4.875;      //average of the digits of the identification card
                         //maximum and minimum values of the interval [a, b]
    float h = 0;
    float N;
    float Max, x;
    float sin_;

    float inf;
    printf("\n input the inf value: ");
    scanf("%f", &inf);
    printf("\ninput the N value: ");

    scanf("%f", &N);

    h = (b - a)/N;

    x = a - h;
    Max = -inf;

    do {
            x = x + h;
            sin_ = funtion_(A, x);
            if (sin_ >= Max) {
                    Max = sin_;
                printf("\n new Max: %f found at A: %f x: %f\n", Max, A, x);

            }
    } while (x < b);

    printf("Maximum value: %.5f\n", Max);
    return 0;
}