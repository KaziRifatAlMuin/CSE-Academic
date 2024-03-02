#include<stdio.h>
#include<stdarg.h>

float avg(int num, ...)
{
    int i = 0;
    float sum = 0;
    va_list v;
    va_start(v, num);
    for(; i < num; i++){
        sum += va_arg(v, int);
    }
    va_end(v);
    return sum/num;
}

int main()
{
    printf("%0.4f\n",avg(3,1,2,3));
    printf("%0.4f\n",avg(4,10,20,30,40));

}
