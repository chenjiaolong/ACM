//s=��3������k=1��k
#include<stdio.h>
int main()
{
    int k = 1,s = 0;
loop:
    if(k <= 3)//loopΪ����ţ����ڶ�������е�ĳ��λ�ã��ñ�ʶ����ʾ������ֻ������
    {
        s = s + k;
        k++;
        printf("%d%c",k,k == 4?'\n':' ');
        goto loop;//goto+����ţ������ƻ�����ģ��ṹ�������ᳫ
    }
    printf("s = %d",s);
    return 0;
}

