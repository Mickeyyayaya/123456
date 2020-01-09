#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main ()
{
    int N;
    scanf("%d",&N);
    for(int i = 1;i<=N;i+=2)
    {
        for(int j = 0;j<i;j++)
            printf("*");
        printf("\n");
    }
    for(int i = N-2;i>0;i-=2)
    {
        for(int j = 0;j<i;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
