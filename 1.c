#include <stdio.h>


int main()
{
    int price = 8;
    int gram;
    scanf("%d",&gram);
    if(gram > 1000)
    {
        gram = gram % 1000 ;
        if(gram % 500 != 0)
            gram = gram / 500 +1;
        else
            gram = gram / 500;
        price = price + gram * 4;
    }

    int fast;
    scanf("%d",&fast);
    if(fast == 1)
        price = price +5;
    else if(fast == 2)
        price = price + 10;

    printf("%d",price);
    return 0;
}
