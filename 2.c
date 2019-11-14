#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int cost,time;
    int total = 0;
    for(int i = 0; i<n; i++)
    {
        scanf("%d %d",&cost,&time);
        total = total + cost * time;
    }
    printf("%d",total);
    return 0;
}
