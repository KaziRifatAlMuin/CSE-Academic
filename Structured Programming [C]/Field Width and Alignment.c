#include<stdio.h>

int main()
{
    int a[5] ={10, 1020, 234, 2323, 232343};
    double b[5] = {1.202023, 334.238382382, 343.344, 23.3, 232443.9933};
    int i = 0, p1, p2, p3, p4;
    for(i = 0; i < 5; i++){
        p1 = printf("%010d %15f\n",a[i],b[i]); //right, right
    }
    printf("\n%d\n\n", p1);
    for(i = 0; i < 5; i++){
        p2 = printf("%-10d %-10.2f\n",a[i],b[i]); //left, left
    }
    printf("\n%d\n\n", p2);
    for(i = 0; i < 5; i++){
        p3 = printf("%-020d %015.5f\n",a[i],b[i]); //left, right, 0 for right padding with zero
    }
    printf("\n%d\n\n", p3);
    for(i = 0; i < 5; i++){
        p4 = printf("%10d %-20.8f\n",a[i],b[i]); //right, left
    }
    printf("\n%d\n\n", p4);

    return 0;
}
