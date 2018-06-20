#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int array[500005];
int temp[500005];
void Merge(int low,int mid,int high)
{
    //将有序表array[low..mid]和array[mid+1..high]归并为有序表array[low..high];
    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)//将array中记录由小到大地并入T中
    {
        if(array[i]<=array[j])
            temp[k++]=array[i++];
        else
            temp[k++]=array[j++];
    }
    while(i<=mid)//将剩余的array[low..mid]复制到temp中
        temp[k++]=array[i++];
    while(j<=high)//将剩余的array[mid+1..high]复制到temp中
        temp[k++]=array[j++];
    for(i=low; i<=high; i++)//写回原数组
        array[i]=temp[i];
}
void MergeSort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;//将当前序列一分为二，求出分裂点mid
        // mid = (low & high) + ((low ^ high) >> 1);
        MergeSort(low,mid);//对子序列array[low..mid]递归归并排序
        MergeSort(mid+1,high);//对子序列array[mid+1..high]递归归并排序
        Merge(low,mid,high);//将排序的子序列归并
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

