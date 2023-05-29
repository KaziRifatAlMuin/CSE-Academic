#include<stdio.h>

int main()
{
    float a = 1.3;
    double b = 1.3;
    int c = 50;
    while(c--){
        printf("%f %f\n", a, b);
        a = a*a*-1;
        b = b*b;
    }
}
