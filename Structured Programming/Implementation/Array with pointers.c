#include<stdio.h>

int main()
{
    int num[5]={1,2,3,4,5};
    int i = 0;
    for(i = 0; i < 5; i++){
        printf("%d %d %d %d\n",*(num+i),*(i+num),num[i],i[num]);
    }
    return 0;
}
