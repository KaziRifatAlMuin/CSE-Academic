#include<stdio.h>

int main()
{
    unsigned char a = 251;
    char b = a;
    printf("%d = %c\n\n",b,b);
/*
    0 = 0
    127 = 127
    128 = -128
    129 = -127
    130 = -126
    (128+2) = -(128-2) // 2^8
    (128+n) = -(128-n) // 2^8
    251 = 128 + n; => n = 251 - 128 = 123
    So, Signed : -(128-n) = -(128-123) = -5
*/
    int i;
    for(i=-128; i<=127; i++){
        printf("%d = %c\n", i, i);
    }
    for(i=0; i<=255; i++){
        printf("%d = %c\n", i, i);
    }
}


