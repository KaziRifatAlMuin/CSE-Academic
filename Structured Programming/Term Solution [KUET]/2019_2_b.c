#include<stdio.h>

int main()
{
    int x = 2147483647, y = 3, z = 10;
    int i, ii, iii;
    i = ~x + z % y;
    ii = !z ^ !!y ? 0 : 1;
    iii = z >>= y + (7 & 8);
    printf("%d %d %d", i, ii, iii); //-2147483647 0 1
    return 0;
}
