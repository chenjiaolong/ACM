//鞍点在该行上最大在该列上最小
/*#include<stdio.h>
#define N 4
#define M 5
void main()
{
    int i,j,k,a[N][M],max,maxj,flag;
    printf("输入数组：\n");
    for(i=0; i<N; i++) //输入数组
        for(j=0; j<M; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<N; i++)
    {
        max=a[i][0];//开始时假设a[i][0]最大
        maxj=0;//将列号0赋值给maxj保存
        for(j=0; j<M; j++) //找出第i行中的最大数
            if(a[i][j]>max)
            {
                max=a[i][j];//将本行的最大数保存在max中
                maxj=j;//将最大数所在的列号保存在maxj中
            }
        flag=1;//先假设是鞍点，用flag为1代表
        for(k=0; k<N; k++)
            if(max>a[k][maxj])//将最大数和其同列元素相比
            {
                flag=0;//如果max不是同列最小，表示不是鞍点，令flag=0
                continue;
            }
        if(flag)//如果flag为1表示是鞍点
        {
            printf("a[%d][%d]=%d\n",i,maxj,max);//输出鞍点值和所在行号列号
            break;
        }
    }
    if(!flag)//如果flag为0表示鞍点不存在
        printf("鞍数不存在！");
}*/
#include<stdio.h>
void main()
{
    int i,j,a[4][5];
    int m=0,n=0,k,min,max;
    for(i=0; i<4; i++)
        for(j=0; j<5; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<4; i++)
    {
        max=a[i][0];
        for(j=1; j<5; j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                m=j;
            }
        for(k=1; k<4; k++)
        {
            min=a[0][m];
            if(a[k][m]<min)
                {
                    min=a[k][m];
                    n=k;
                }
        }
        if(max==min)
            {
                printf("该数组的鞍点是第%d行第%d列的%d\n",n+1,m+1,max);
                break;
            }
    }
    if(i==4)
        printf("该数组没有找到鞍点\n");
}

