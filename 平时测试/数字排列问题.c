//��1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
#include<stdio.h>
int main()
{
    int a, b, c;
    int count=0;
    for(a=1; a<5; a++) //��λ
        for(b=1; b<5; b++) //ʮλ
            for(c=1; c<5; c++) //��λ
                if(a!=b&&a!=c&&b!=c)
                {
                    printf("%d%d%d\n",a,b,c);
                    count++;
                }
    printf("�������Ϊ%d��\n",count);
	return 0;
}
