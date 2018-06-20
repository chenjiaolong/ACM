#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int Binary_search(int array[],int left,int right,int key)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(array[mid]==key)
            return mid;
        else if(array[mid]>key)
            right=mid-1;
        else
            left=mid+1;
    }
    return -1;
}
int main()
{
    int N,array[100],key;
    cout<<"请输入N："<<endl;
    cin>>N;
    cout<<"请输入N个整数："<<endl;
    for(int i=0; i<N; i++)
        cin>>array[i];
    sort(array,array+N);
    cout<<"从小到大排序后："<<endl;
    for(int i=0; i<N-1; i++)
        cout<<array[i]<<" ";
    cout<<array[N-1]<<endl;
    cout<<"请输入要查找的数：";
    cin>>key;
    int m=Binary_search(array,0,N-1,key);
    if(m!=-1)
        cout<<key<<" 在第"<<m+1<<" 个位置"<<endl;
    else
        cout<<"没有找到"<<endl;
}

