#include <stdio.h>

int max(int a,int b,int c)
{
    int max = a;
    if(max<b)
        max = b;
    if(max<c)
        max =c;
    return max;
}
int main()
{
    int count = 0;
    int correct = 0;
    int a=0,b=0,c=0;
    scanf("%d %d %d",&a,&b,&c);
    while(1)
    {
        int maxx = max(a,b,c);
    //    printf("%d\n",maxx);
        if(maxx == a)
        {
            if( b+c > a)
            {
                correct++;
                count++;
                scanf("%d",&a);
                if(a==-1)
                    break;
                scanf("%d %d",&b,&c);
                //continue;
            }
            else
            {
                count++;
                scanf("%d",&a);
                if(a==-1)
                    break;
                scanf("%d %d",&b,&c);
            }
        }
        else if(maxx == b)
        {
            if(a+c > b)
            {
                correct++;
                count++;
                scanf("%d",&a);
                if(a==-1)
                    break;
                scanf("%d %d",&b,&c);
                //continue;
            }
            else
            {
                count++;
                scanf("%d",&a);
                if(a==-1)
                    break;
                scanf("%d %d",&b,&c);
            }
        }
        else if(maxx == c)
        {
            if(b+a > c)
            {
                correct++;
                count++;
                scanf("%d",&a);
                if(a==-1)
                    break;
                scanf("%d %d",&b,&c);
                //continue;
            }
            else
            {
                count++;
                scanf("%d",&a);
                if(a==-1)
                    break;
                scanf("%d %d",&b,&c);
            }
        }
    }

    printf("總共帶了%d天\n",count);
    printf("其中有%d組可以構成三角形",correct);
    return 0;
}
