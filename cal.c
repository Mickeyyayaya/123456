#include <stdio.h>

#include <stdlib.h>

int monthDay(int,int);//獲取某個月的天數

int isLeapYear(int);//判斷某一年是否是閏年

int main()

{

    int days,weekDay,year,month=1,d,i;

    scanf("%d",&year);

    int a = isLeapYear(year);
//計算某一年某個月第一天星期幾


    while(month<=12)

    {

        printf("%d月\n",month);
        int b = monthDay(month,year);
        for(int i  = 1 ;i<=b;i++)
        {
            if(i % 7 == 0)
            {
                printf("%d",i);
                printf("\n");
            }
            else
                printf("%d\t",i);
        }
        if(b != 28)
            printf("\n");
        month++;

    }

    return 0;

    }

int monthDay(int month, int year)

{

    switch(month)

    {

        case 1:case 3:case 5:case 7:case 8:case 10:case 12:

            return 31;

            break;

        case 4:case 6:case 9:case 11:

            return 30;

            break;

        case 2:

            if((isLeapYear(year))==1)

                return 29;

            else

                return 28;

            break;

        }
}

int isLeapYear(int year)

{

    if((year%4==0)&&(year%100!=0))

        return 1;

    if(year%400==0)

        return 1;

    return 0;

}
