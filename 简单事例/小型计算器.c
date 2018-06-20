#include<stdio.h>
#include<conio.h>
void main()
{
    int m,n,option;
    printf("  *--------------------*\n");
    printf("  |   请选择运算类型   |\n");
    printf("  |--------------------|\n");
    printf("  |      1.加法        |\n");
    printf("  |      2.减法        |\n");
    printf("  |      3.乘法        |\n");
    printf("  |      4.除法        |\n");
    printf("  |      5.求余        |\n");
    printf("  |      0.退出        |\n");
    printf("  *--------------------*\n");
    while(1)
    {
        printf("  请输入选择（0~5）：   \n");
        scanf("%d",&option);
        while(option<0||option>5)
        {
            printf("对不起不存在这个选项！！！请重新输入：\n");
            printf("  请输入选择（0~5）：   \n");
            scanf("%d",&option);
        }
        switch(option)
        {
        case 1:
            printf("请输入两个整数：\n");
            scanf("%d%d",&m,&n);
            printf("%d+%d=%d\n",m,n,m+n);
            break;
        case 2:
            printf("请输入两个整数：\n");
            scanf("%d%d",&m,&n);
            printf("%d-%d=%d\n",m,n,m-n);
            break;
        case 3:
            printf("请输入两个整数：\n");
            scanf("%d%d",&m,&n);
            printf("%d*%d=%d\n",m,n,m*n);
            break;
        case 4:
            printf("请输入两个整数：\n");
            scanf("%d%d",&m,&n);
            printf("%d/%d=%.2f\n",m,n,(float)m/n);
            break;
        case 5:
            printf("请输入两个整数：\n");
            scanf("%d%d",&m,&n);
            printf("这两个数的余数为%d\n",m,n,m % n);
            break;
        case 0:
            return ;
        }
    }

}


