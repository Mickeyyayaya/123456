#include <stdio.h>
int calc_cycle_len(int num)
{
    int cycle_length=1;

    while(num!=1)
    {
        cycle_length++;
        if(num%2==1)
            num=num*3+1;
        else
            num/=2;
    }
    printf("%d\n",cycle_length);
    return cycle_length;
}
int main(void)
{
    int temp,i,num,cycle_length;
    scanf("%d",&num);
    while(num != -1)
    {
        cycle_length = calc_cycle_len(num);
        scanf("%d",&num);
    }
    return 0;
}
