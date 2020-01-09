#include <stdio.h>

#include <stdlib.h>

int monthDay(int,int);//獲取某個月的天數

int isLeapYear(int);//判斷某一年是否是閏年

int main()

{

    int days,weekDay,year,month=1,d,i;

    scanf("%d",&year);

//計算某一年某個月第一天星期幾

    days=year-1+(year-1)/400+(year-1)/4-(year-1)/100;

    while(month<=12)

    {

        printf("%d月\n",month);


        d=1,i=1;

        weekDay=(days+1)%7;//求星期幾

        while(i<=weekDay)

        {

            printf("\t");

            i++;

        }

        while(d<=monthDay(month,year))

        {

            weekDay=(days+1)%7;

            if(weekDay==6)

                printf("%d\n",d);

            else

                printf("%d\t",d);

            if(d==monthDay(month,year))

                printf("\n");

            d++;

            days++;

        }

        month++;

        printf("\n");

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

            if((IsLeapYear(year))==1)

                return 29;

            else

                return 28;

            break;

        }
}

int IsLeapYear(int year)

{

    if((year%4==0)&&(year%100!=0))

        return 1;

    if(year%400==0)

        return 1;

    return 0;

}
