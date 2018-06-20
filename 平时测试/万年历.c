#include<stdio.h>
#include<stdlib.h>

int IsLeapyear(int year)
{
    if ((year%4==0&&year%100!=0)||year%400==0)
        return 1;
    return 0;
}
void Blank(int day)
{
    switch(day%7)
    {
    case 0:printf("           ");break;
    case 1:printf("              ");break;
    case 2:printf("                 ");break;
    case 3:printf("");break;
    case 4:printf("  ");break;
    case 5:printf("     ");break;
    case 6:printf("        ");break;
    }
}
void Space(int day)
{
    switch(day%7)
    {
    case 0:printf("           ");break;
    case 1:printf("        ");break;
    case 2:printf("     ");break;
    case 3:printf("  ");break;
    case 4:printf("");break;
    case 5:printf("                 ");break;
    case 6:printf("              ");break;
    }
}
void Output1(int day)
{
    int i;
    for(i=1; i<=31; i++)
    {
            switch((day-i+1)%7)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 6:printf("%3d",i);break;
            case 4:printf("%2d",i);break;
            case 5:printf("%3d\n",i);break;
            }
            if((day-i+1)%7!=5&&i==31)
                printf("\n");

    }
}
void Output2(int year,int day)
{
    int i;
    if(IsLeapyear(year))
    {
        for(i=1; i<=29; i++)
        {
                switch((day-i+1)%7)
                {
                case 0:
                case 1:
                case 2:
                case 3:
                case 6:printf("%3d",i);break;
                case 4:printf("%2d",i);break;
                case 5:printf("%3d\n",i);break;
                }
           if((day-i+1)%7!=5&&i==29)
            printf("\n");
        }
    }
    else
    {
        for(i=1; i<=28; i++)
        {
                switch((day-i+1)%7)
                {
                case 0:
                case 1:
                case 2:
                case 3:
                case 6:printf("%3d",i);break;
                case 4:printf("%2d",i);break;
                case 5:printf("%3d\n",i);break;
                }
           if((day-i+1)%7!=5&&i==28)
            printf("\n");
        }
    }
}
void Output3(int day)
{
    int i;
    for(i=1; i<=30; i++)
    {
            switch((day-i+1)%7)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 6:printf("%3d",i);break;
            case 4:printf("%2d",i);break;
            case 5:printf("%3d\n",i);break;
            }
            if((day-i+1)%7!=5&&i==30)
                printf("\n");

    }
}
void Print1(int year,int month,int day)
{
    int i;
    printf("Su Mo Tu We Th Fr Sa\n");
    if(month>2&&IsLeapyear(year))
        day=day-1;
    if(IsLeapyear(year))
        day=day+1;
    switch(month)
    {
    case 1:
        day=day;
        Space(day);
        Output1(day);
        break;
    case 2:
        day=day-31;
        Space(day);
        Output2(year,day);
        break;
    case 3:
        day=day-59;
        Space(day);
        Output1(day);
        break;
    case 4:
        day=day-90;
        Space(day);
        Output3(day);
        break;
    case 5:
        day=day-120;
        Space(day);
        Output1(day);
        break;
    case 6:
        day=day-151;
        Space(day);
        Output3(day);
        break;
    case 7:
        day=day-181;
        Space(day);
        Output1(day);
        break;
    case 8:
        day=day-212;
        Space(day);
        Output1(day);
        break;
    case 9:
        day=day-243;
        Space(day);
        Output3(day);
        break;
    case 10:
        day=day-273;
        Space(day);
        Output1(day);
        break;
    case 11:
        day=day-304;
        Space(day);
        Output3(day);
        break;
    case 12 :
        day=day-334;
        Space(day);
        Output1(day);
        break;
    }
}
void Output4(int day)
{
    int i;
    for(i=1; i<=31; i++)
    {
            switch((day+i-1)%7)
            {
            case 0:
            case 1:
            case 4:
            case 5:
            case 6:printf("%3d",i);break;
            case 2:printf("%3d\n",i);break;
            case 3:printf("%2d",i);break;
            }
            if((day+i-1)%7!=2&&i==31)
                printf("\n");

    }


}
void Output5(int year,int day)
{
    int i;
    if(IsLeapyear(year))
    {
        for(i=1; i<=29; i++)
        {
                switch((day+i-1)%7)
                {
                case 0:
                case 1:
                case 4:
                case 5:
                case 6:printf("%3d",i);break;
                case 2:printf("%3d\n",i);break;
                case 3:printf("%2d",i);break;
                }
                if((day+i-1)%7!=2&&i==29)
                    printf("\n");
        }
    }
    else
    {
        for(i=1; i<=28; i++)
        {
                switch((day+i-1)%7)
                {
                case 0:
                case 1:
                case 4:
                case 5:
                case 6:printf("%3d",i);break;
                case 2:printf("%3d\n",i);break;
                case 3:printf("%2d",i);break;
                }
                if((day+i-1)%7!=2&&i==28)
                    printf("\n");
        }
    }
}
void Output6(int day)
{
    int i;
    for(i=1; i<=30; i++)
    {
            switch((day+i-1)%7)
            {
            case 0:
            case 1:
            case 4:
            case 5:
            case 6:printf("%3d",i);break;
            case 2:printf("%3d\n",i);break;
            case 3:printf("%2d",i);break;
            }
            if((day+i-1)%7!=2&&i==30)
                printf("\n");

    }
}
void Print2(int year,int month,int day)
{
    int i;
    printf("Su Mo Tu We Th Fr Sa\n");
    if(month>2&&IsLeapyear(year))
        day=day+1;
    switch(month)
    {
    case 1:
        day=day;
        Blank(day);
        Output4(day);
        break;
    case 2:
        day=day+31;
        Blank(day);
        Output5(year,day);
        break;
    case 3:
        day=day+59;
        Blank(day);
        Output4(day);
        break;
    case 4:
        day=day+90;
        Blank(day);
        Output6(day);
        break;
    case 5:
        day=day+120;
        Blank(day);
        Output4(day);
        break;
    case 6:
        day=day+151;
        Blank(day);
        Output6(day);
        break;
    case 7:
        day=day+181;
        Blank(day);
        Output4(day);
        break;
    case 8:
        day=day+212;
        Blank(day);
        Output4(day);
        break;
    case 9:
        day=day+243;
        Blank(day);
        Output6(day);
        break;
    case 10:
        day=day+273;
        Blank(day);
        Output4(day);
        break;
    case 11:
        day=day+304;
        Blank(day);
        Output6(day);
        break;
    case 12 :
        day=day+334;
        Blank(day);
        Output4(day);
        break;
    }
}
int main()
{
    int i,j,year,month,day;
    while(scanf("%d%d",&year,&month)!=EOF)
    {
            day=0;
            if(year<2015)
            {
                for(i=2015; i>year; i--)
                {
                    if(IsLeapyear(i))
                        day=day+366;
                    else
                        day=day+365;
                }
                Print1(year,month,day);
            }
            else
            {
                for(i=2015; i<year; i++)
                {
                    if(IsLeapyear(i))
                        day=day+366;
                    else
                        day=day+365;
                }
                Print2(year,month,day);
            }
    }
    return 0;
}
