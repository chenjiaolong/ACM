//��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
//�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
#include<stdio.h>
int main()
{
    int i,j,k,n,m[1001],sum;
    for(n=2; n<=1000; n++)
    {
        sum=0,j=0;
        for(i=1; i<=n/2; i++)
            if(n%i==0)
            {
                m[j]=i;
                sum=sum+m[j];
                j++;
            }
        if(sum==n)
        {
            printf("%d=",n);
            for(k=0; k<j; k++)
                printf("%d%c",m[k],k==j-1?'\n':'+');
        }
    }
    return 0;
}
