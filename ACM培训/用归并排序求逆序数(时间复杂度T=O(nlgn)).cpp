#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int array[500005];//ԭ����
int temp[500005];//��ʱ����
long long Merge(int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    long long cnt=0;
    while(i<=mid&&j<=high)
    {
        if(array[i]<=array[j])//�˴�Ϊ�ȶ�����Ĺؼ���������С��
            temp[k++]=array[i++];
        else
        {
            temp[k++]=array[j++];
            cnt+=j-k;//ÿ����ε�����Ԫ����ǰʱ����¼��ǰ�ľ���
        }
    }
    while(i<=mid)
        temp[k++]=array[i++];
    while(j<=high)
        temp[k++]=array[j++];
    for(i=low; i<=high; i++)//д��ԭ����
        array[i]=temp[i];
    return cnt;
}
long long MergeSort(int low,int high)
{
    long long cnt=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        cnt+=MergeSort(low,mid);
        cnt+=MergeSort(mid+1,high);
        cnt+=Merge(low,mid,high);
    }
    return cnt;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&array[i]);
        printf("%lld\n",MergeSort(0,n-1));
    }
    return 0;
}

