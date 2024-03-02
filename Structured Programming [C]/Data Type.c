#include<stdio.h>
#include<limits.h>
#include<math.h>

int main()
{
    int n1 = INT_MIN; // -2^31
    unsigned int n2 = UINT_MAX; // 2^32 - 1
    int n3 = 15; //Octal = 17, Hexa = f or F
    short int n4 = -32770; //Min : -32768 ( -2^15)
    unsigned short int n5 = 65537; //MAX : 2^16-1 = 65535
    long n6 = LONG_MIN; //int = long, -2^31
    unsigned long n7 = ULONG_MAX; // 2^32 - 1
    long long n8 = LLONG_MIN; // -2^63
    unsigned long long n9 = ULLONG_MAX; // 2^64 - 1
    char c1 = CHAR_MIN; // -2^7 = -128 = @
    unsigned char c2 = UCHAR_MAX; // 2^8 - 1 = 255 = @
    float f1 = 1.0/921;
    float f2 = pow(3.2,1000000);
    double d1 = 1.0/289837845;
    long double d2 = -1.0/273823726372637263;

    printf("%d %i\n",n1, n1);
    printf("%u\n",n2);
    printf("%o %x %X\n",n3, n3, n3);
    printf("%hd %hi %hu\n",n4, n4, n5);
    printf("%ld %li %lu\n",n6, n6, n7);
    printf("%lld %lli %llu\n",n8, n8, n9);
    printf("%f %e %E %g %G\n", f1,f1,f1,f1,f1);
    printf("%f %e %E %g %G\n", d1,d1,d1,d1,d1);
    printf("%Lf %Le %LE %Lg %LG\n", d2,d2,d2,d2,d2);
    printf("%d = %c\n",c1);
    printf("%d = %c\n",c2);
    printf("%f\n",f2);
}



