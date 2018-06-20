#include<stdio.h>
int hour,minute,second;
void update()
{
    second++;
    if(second==60)
    {
        second=0;
        minute++;
    }
    if(minute==60)
    {
        minute=0;
        hour++;
    }
    if(hour==24)
        hour=0;
}
void display()
{
    system("cls");
    printf("%02d:%02d:%02d\n",hour,minute,second);
}
void delay()
{
    int t;
    for(t=0; t<450000000; t++);
}
int main()
{
    int i;
    scanf("%d%d%d",&hour,&minute,&second);
    for(i=0; i<100000000; i++)
    {
        update();
        display();
        delay();
    }
    return 0;
}

//用更相减损术求两个数的最大公约数 T = O(N);N 为原先的两个数中的较大的一个
//#include<stdio.h>
//int Gcd(int a,int b)
//{
//    int temp;
//    if(a < b)
//    {
//        temp = a;
//        a = b;
//        b = temp;
//    }
//    if(a == b)
//        return a;
//    return Gcd(a - b, b);
//}
//int main()
//{
//    int x,y;
//    while(~scanf("%d%d",&x,&y))
//        printf("%d\n",Gcd(x,y));
//    return 0;
//}
