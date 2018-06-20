//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//void swap(int array[],int i,int j)
//{
//    int temp=array[i];
//    array[i]=array[j];
//    array[j]=temp;
//}
//void perm(int array[],int k,int m,int pk,int pm)
//{
//    //k为中间变量，m初始化为参与排列元素的起始坐标与终止坐标
//    //pk,pm分别表示参与排列元素的起始坐标与终止坐标，整个过程保持不变
//    if(k==m)//递归出口当起始坐标等于终止坐标是输出数列
//    {
//        for(int i=pk;i<=pm;i++)
//            printf("%d%c",array[i],i==pm?'\n':' ');
//    }
//    for(int i=k;i<=m;i++)
//    {
//        swap(array,k,i);
//        perm(array,k+1,m,pk,pm);//递归过程
//        swap(array,k,i);//注意还原array[k]和array[i]
//    }
//}
//int main()
//{
//    int array[10];
//    int n;
//    while(~scanf("%d",&n))
//    {
//        for(int i=0;i<n;i++)
//            scanf("%d",&array[i]);
//        // sort(array,array+n);
//        perm(array,0,n-1,0,n-1);
//    }
//    return 0;
//}


// 无重复的字符串的全排列问题
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//char str[] = "1234";
//int size = sizeof(str) / sizeof(char);
//void Permutation(int from, int to)
//{
//    if(from == to)
//    {
//        puts(str);
//        return;
//    }
//    for(int i = from; i <= to; i++)
//    {
//        swap(str[i], str[from]);
//        Permutation(from + 1, to);
//        swap(str[i], str[from]);
//    }
//}
//int main()
//{
//    Permutation(0, size - 2);
//    return 0;
//}

// 有重复的字符串的全排列问题 时间复杂度：T(O((n + 1)!))
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//char str[] = "1223";
//int size = sizeof(str) / sizeof(char);
//bool IsSwap(int from, int to)
//{
//    bool bCan = true;
//    for(int i = from; i < to; i++)
//    {
//        if(str[to] == str[i])
//        {
//            bCan = false;
//            break;
//        }
//    }
//    return bCan;
//}
//void Permutation(int from, int to)
//{
//    if(from == to)
//    {
//        puts(str);
//        return;
//    }
//    for(int i = from; i <= to; i++)
//    {
//        if(!IsSwap(from, i))
//            continue;
//        swap(str[i], str[from]);
//        Permutation(from + 1, to);
//        swap(str[i], str[from]);
//    }
//}
//int main()
//{
//    Permutation(0, size - 2);
//    return 0;
//}

// 用空间换取时间,有重复的字符串的全排列问题 时间复杂度：T(O(n!))
#include<stdio.h>
#include<iostream>
using namespace std;
char str[] = "1223";
int size = sizeof(str) / sizeof(char);
void Permutation(int from, int to)
{
    if(from == to)
    {
        puts(str);
        return;
    }
    bool mark[256];
    for(int i = 0; i < 256; i++)
        mark[i] = false;
    for(int i = from; i <= to; i++)
    {
        if(mark[str[i]])
            continue;
        mark[str[i]] = true;
        swap(str[i], str[from]);
        Permutation(from + 1, to);
        swap(str[i], str[from]);

    }
}
int main()
{
    Permutation(0, size - 2);
    return 0;
}
