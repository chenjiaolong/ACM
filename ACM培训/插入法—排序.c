#include <stdio.h>
int main()
{
    int a[10],i,j,t;
    printf("Please input 10 numbers: \n");
    for(i=0; i<10; i++)
        scanf("%d",&a[i]);
    for(i=1; i<10; i++)		/*外循环控制趟数，n个数从第2个数开始到最后共进行n-1次插入*/
    {
        t=a[i];    			/*将待插入数暂存于变量t中*/
        for( j=i-1 ; j>=0 && t>a[j] ; j-- ) 	/*在有序序列（下标0 ~ i-1）中寻找插入位置*/
            a[j+1]=a[j]; 		/*若未找到插入位置，则当前元素后移一个位置*/
        a[j+1]=t; /*找到插入位置，完成插入*/
    }
    printf("The sorted numbers: ",i);
    for(i=0; i<10; i++)
        printf("%d   ",a[i]);
    printf("\n");
    return 0;
}

