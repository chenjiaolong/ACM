//栈
#include<stdio.h>
int a[100];
int main()
{
    int m,n,i;
    scanf("%d%d",&m,&n);
    int top=1,bottom=1;
    int cnt=0;
    for(i=1; i<=m; i++)
    {
        scanf("%d",&a[bottom++]);
        if(++cnt>n)
            top++;
    }
    for(i=top; i<bottom; i++)
        printf("%d%c",a[i],i == bottom - 1 ? '\n' : ' ');
    return 0;
}

//队列
//#include<stdio.h>
//int a[100];
//int main()
//{
//    int m,i,k;
//    scanf("%d",&m);
//    int bottom=1;
//    for(i=1; i<=m; i++)
//    {
//        scanf("%d",&k);
//        if(k!=0)
//            a[bottom++]=k;
//        else
//            bottom--;
//    }
//    for(i=1; i<bottom; i++)
//        printf("%d%c",a[i],i == bottom - 1 ? '\n' : ' ');
//    return 0;
//}
