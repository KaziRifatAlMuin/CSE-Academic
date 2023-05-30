#include<stdio.h>

int main()
{
    int a = 016;
    int b = 0x10;
    int c = 0XA;
    //scanf("%x",&a); //All Calculation in calculator
    printf("%o %d %x\n",a,a,a); //16 14 e
    printf("%05o %5d %#5X\n",b,b,b); //00020    16  0X10
    printf("%#o %#04d %#06x\n",c,c,c);//012 0010 0x000a
}


