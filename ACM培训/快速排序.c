#include<stdio.h>
#include<string.h>
//����һ
/*void QuickSort(int a[],int left,int right)
{
    int i=left,j=right,temp=a[left];
    if(left>=right)//>��ֹ��������
        return;
    while(i!=j)
    {
        while(i<j&&a[j]>=temp)
            j--;
        if(i<j)
            a[i]=a[j];
        while(i<j&&a[i]<=temp)
            i++;
        if(i<j)
            a[j]=a[i];
    }
    a[i]=temp;
    QuickSort(a,left,i-1);
    QuickSort(a,i+1,right);
}*/
//������
void QuickSort(int a[],int numsize)//a���������飬numsize��Ԫ�ظ���
{
    int i=0,j=numsize-1;
    int value=a[0];//ָ���ο�ֵval��С
    if(numsize>1)//ȷ�����鳤������Ϊ2��������������
    {
        while(i<j)//ѭ������������
        {
            //�Ӻ���ǰ������valС��Ԫ�أ��ҵ����a[i]�в�����ѭ��
            for(; j>i; j--)
                if(a[j]<value)
                {
                    a[i++]=a[j];
                    break;
                }
            //��ǰ����������val���Ԫ�أ��ҵ����a[j]�в�����ѭ��
            for(; i<j; i++)
                if(a[i]>value)
                {
                    a[j--]=a[i];
                    break;
                }
        }
        a[i]=value;//��������val�е����ŵ�a[i]��
        QuickSort(a,i);//�ݹ飬��ǰi��������
        QuickSort(a+i+1,numsize-i-1);//��i+2��numsize��numsize-1-i��������
    }
}
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[1000]= {0}; //memset(a,sizeof(a),0);��ʼ������a
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        //QuickSort(a,0,n-1);//����һ
        QuickSort(a,n);//������
        for(i=0; i<n; i++)
            printf("%d%c",a[i],i==n-1?'\n':' ');
    }
    return 0;
}
