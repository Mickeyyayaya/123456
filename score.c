#include <stdio.h>

int main()
{
    int n ;
    scanf("%d",&n);
    int a[n][100];
    float b[n];
    float score[n];
    for(int i = 0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        b[i] = x;
        score[i] = 0;
        for(int j = 0;j<b[i];j++)
        {
            scanf("%d",&a[i][j]);
            score[i]+=a[i][j];
        }
    }

    for(int i = 0;i<n;i++)
    {
        score[i] = score[i] / b[i];
    }

    for(int i = 0;i<n;i++)
    {
        float con  =  0;
        for(int j = 0;j<b[i];j++)
            if(a[i][j]>score[i])
                con++;
        //printf("%d",con);
        score[i] = con / b[i] *100;
    }
    for(int i =0;i<n;i++)
        printf("%.3f\n",score[i]);
    return 0;
}
