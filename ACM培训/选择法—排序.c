#include <stdio.h>
int main()
{
    int a[10],i,j,k,t,n=10;
    printf("Please input 10 numbers:\n");
    for(i=0; i<10; i++)
        scanf("%d",&a[i]);
    for(i=0; i<9; i++)   	/*��ѭ������������n����ѡn-1��*/
    {
        k=i;            	/*���赱ǰ�˵ĵ�һ����Ϊ��ֵ,����k�� */
        for(j=i+1; j<n; j++) 	/*����һ���������һ����֮������ֵ*/
            if(a[k]<a[j])    	/*������б���ֵ�����*/
                k=j;        	/*�����±����k��*/
        if(k!=i)       		/*��k��Ϊ�����iֵ��˵��������ҵ�����������*/
        {
            t=a[k];     /*�򽻻���ֵ�͵�ǰ���еĵ�һ����*/
            a[k]=a[i];
            a[i]=t;
        }
    }
    printf("The sorted numbers: ");
    for(i=0; i<10; i++)
        printf("%d   ",a[i]);
    printf("\n");
    return 0;
}

