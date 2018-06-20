#include<stdio.h>
void main()
{
	int count=0;
	float score, sum=0;
	printf("请输入该同学某门功课的分数：");
	scanf("%f",&score);
	while(score!=-1)
	{
		sum=sum+score;
		count=count+1;
		printf("请输入该同学某门功课的分数：");
	    scanf("%f",&score);
	}
    printf("该同学%d门功课的总分为%.2f\n",count,sum);
}
