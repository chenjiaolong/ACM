#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int array[500005];
int temp[500005];
void Merge(int low,int mid,int high)
{
    //�������array[low..mid]��array[mid+1..high]�鲢Ϊ�����array[low..high];
    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)//��array�м�¼��С����ز���T��
    {
        if(array[i]<=array[j])
            temp[k++]=array[i++];
        else
            temp[k++]=array[j++];
    }
    while(i<=mid)//��ʣ���array[low..mid]���Ƶ�temp��
        temp[k++]=array[i++];
    while(j<=high)//��ʣ���array[mid+1..high]���Ƶ�temp��
        temp[k++]=array[j++];
    for(i=low; i<=high; i++)//д��ԭ����
        array[i]=temp[i];
}
void MergeSort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;//����ǰ����һ��Ϊ����������ѵ�mid
        // mid = (low & high) + ((low ^ high) >> 1);
        MergeSort(low,mid);//��������array[low..mid]�ݹ�鲢����
        MergeSort(mid+1,high);//��������array[mid+1..high]�ݹ�鲢����
        Merge(low,mid,high);//������������й鲢
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&array[i]);
        MergeSort(0,n-1);
        for(int i=0;i<n;i++)
            printf("%d%c",array[i],i==n-1?'\n':' ');
    }
    return 0;
}

