#include<stdio.h>
#include<stdarg.h>

double summation(int num, ...)
{
    int i;
    double sum = 0;
    va_list v;
    va_start(v, num);
    for(i = 1; i <= num; i++){
        if(i%2==1) sum += va_arg(v, int);
        else sum += va_arg(v, double);
    }
    va_end(v);
    return sum;
}

int main()
{
    printf("%0.4f\n",summation(3,1,2.6,3));
    printf("%0.4f\n",summation(6,1,2.2,3,4.5,5,6.4));
    return 0;
}

