#include<stdio.h>
void main()
{
	int count=0;
	float score, sum=0;
	printf("�������ͬѧĳ�Ź��εķ�����");
	scanf("%f",&score);
	while(score!=-1)
	{
		sum=sum+score;
		count=count+1;
		printf("�������ͬѧĳ�Ź��εķ�����");
	    scanf("%f",&score);
	}
    printf("��ͬѧ%d�Ź��ε��ܷ�Ϊ%.2f\n",count,sum);
}
