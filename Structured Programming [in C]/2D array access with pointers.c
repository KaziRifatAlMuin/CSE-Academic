#include<stdio.h>

int main()
{
    int mat[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int i,j;
    printf("Type 1 :\n\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            printf("%3d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\nType 2 :\n\n");
    for(i = 0; i < 3; i = -~i){
        for(j = 0; j < 4; j = -~j){
            printf("%3d ",*(mat[i]+j));
        }
        printf("\n");
    }
    printf("\n\nType 3 :\n\n");
    for(i = 0; i < 3; i = -~i){
        for(j = 0; j < 4; j = -~j){
            printf("%3d ",*(*(mat+i)+j));
        }
        printf("\n");
    }

    return 0;
}

