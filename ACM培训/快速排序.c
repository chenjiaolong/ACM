#include<stdio.h>
#include<string.h>
//方法一
/*void QuickSort(int a[],int left,int right)
{
    int i=left,j=right,temp=a[left];
    if(left>=right)//>防止发生错误
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
//方法二
void QuickSort(int a[],int numsize)//a是整形数组，numsize是元素个数
{
    int i=0,j=numsize-1;
    int value=a[0];//指定参考值val大小
    if(numsize>1)//确保数组长度至少为2，否则无需排序　
    {
        while(i<j)//循环结束条件　
        {
            //从后向前搜索比val小的元素，找到后填到a[i]中并跳出循环
            for(; j>i; j--)
                if(a[j]<value)
                {
                    a[i++]=a[j];
                    break;
                }
            //从前往后搜索比val大的元素，找到后填到a[j]中并跳出循环
            for(; i<j; i++)
                if(a[i]>value)
                {
                    a[j--]=a[i];
                    break;
                }
        }
        a[i]=value;//将保存在val中的数放到a[i]中
        QuickSort(a,i);//递归，对前i个数排序
        QuickSort(a+i+1,numsize-i-1);//对i+2到numsize这numsize-1-i个数排序　
    }
}
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[1000]= {0}; //memset(a,sizeof(a),0);初始化数组a
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        //QuickSort(a,0,n-1);//方法一
        QuickSort(a,n);//方法二
        for(i=0; i<n; i++)
            printf("%d%c",a[i],i==n-1?'\n':' ');
    }
    return 0;
}
