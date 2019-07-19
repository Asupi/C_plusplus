#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
int main()
{
    long long der[21] = { 0,0,1 }, fun[21] = { 0,1,2 };
    int i, n;
    for (i = 3; i < 21; i++)
    {
        der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
        fun[i] = i*fun[i - 1];
    }
    while (~scanf("%d", &n))
    {
        printf("%.2f%c\n", 1.0*der[n] /fun[n] * 100, '%');
    }
    return 0;
}