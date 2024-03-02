#include<stdio.h>

int main()
{
    int mat[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int i, j, *pint;
    int (*ptr)[4];
    printf("Type 1 :\n\n");
    for(i = 0; i < 3; i++){
        ptr = mat[i];
        for(j = 0; j < 4; j++){
            printf("%3d ",*(*ptr+j));
        }
        printf("\n");
    }
    printf("\nType 2 :\n\n");
    for(i = 0; i < 3; i++){
        ptr = mat[i];
        pint = ptr;
        for(j = 0; j < 4; j++){
            printf("%3d ",*(pint+j));
        }
        printf("\n");
    }
    return 0;
}


