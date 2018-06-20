#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	void DiceAndPrint();
	DiceAndPrint();
	void Print();
	unsigned Two_Dice();
	Print();
}

unsigned Two_Dice()
{
	//printf("%d\n",rand()%31+1);
	return (rand()%31+1);
}
void Print()
{
	printf("%d\n",Two_Dice());
}
void DiceAndPrint()
{
	int i=0;
	int sum[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	srand((unsigned)time(NULL));
	for(i=0;i<36;i++)
	{
		switch(Two_Dice())
		{
			case 2:
				sum[2]=sum[2]+1;
				//printf("2:%d\n",sum[2]);
				break;
			case 3:
				sum[3]=sum[3]+1;
				//printf("3:%d\n",sum[3]);
				break;
			case 4:
				sum[4]=sum[4]+1;
				//printf("4:%d\n",sum[4]);
				break;
			case 5:
				sum[5]=sum[5]+1;
				//printf("5:%d\n",sum[5]);
				break;
			case 6:
				sum[6]=sum[6]+1;
				//printf("6:%d\n",sum[6]);
				break;
			case 7:
				sum[7]=sum[7]+1;
				//printf("7:%d\n",sum[7]);
				break;
			case 8:
				sum[8]=sum[8]+1;
				//printf("8:%d\n",sum[8]);
				break;
			case 9:
				sum[9]=sum[9]+1;
				//printf("9:%d\n",sum[9]);
				break;
			case 10:
				sum[10]=sum[10]+1;
				//printf("10:%d\n",sum[10]);
				break;
			case 11:
				sum[11]=sum[11]+1;
				//printf("11:%d\n",sum[11]);
				break;
			case 12:
				sum[12]=sum[12]+1;
				//printf("12:%d\n",sum[12]);
				break;
		}
	}
	for(i=2;i<=12;i++)
		printf("点%d出现的次数：%d\n",i,sum[i]);
}

