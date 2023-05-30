#include<stdio.h>

int main()
{
    #define radius 5
    // int radius = 5; error
    int r = radius;
    double A, PI = 0;
         #define   PI     3.1416
    A = r * r * PI;
    printf("%0.10lf\n",A);

    return 0;
}



