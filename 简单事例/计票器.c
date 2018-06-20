#include<stdio.h>
#include<conio.h>
void main()
{
    int i=0,j=0,k=0,count=0,option;
    while(i+j+k!=20-count)
    {
        printf("请输入1~3的任意一个数：");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            i++;
            break;
        case 2:
            j++;
            break;
        case 3:
            k++;
            break;
        default:
            count++;
        }
    }
    printf("1号选手最后得票%d\n",i);
    printf("2号选手最后得票%d\n",j);
    printf("3号选手最后得票%d\n",k);
}



