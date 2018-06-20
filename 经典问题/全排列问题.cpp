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
//    //kΪ�м������m��ʼ��Ϊ��������Ԫ�ص���ʼ��������ֹ����
//    //pk,pm�ֱ��ʾ��������Ԫ�ص���ʼ��������ֹ���꣬�������̱��ֲ���
//    if(k==m)//�ݹ���ڵ���ʼ���������ֹ�������������
//    {
//        for(int i=pk;i<=pm;i++)
//            printf("%d%c",array[i],i==pm?'\n':' ');
//    }
//    for(int i=k;i<=m;i++)
//    {
//        swap(array,k,i);
//        perm(array,k+1,m,pk,pm);//�ݹ����
//        swap(array,k,i);//ע�⻹ԭarray[k]��array[i]
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


// ���ظ����ַ�����ȫ��������
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

// ���ظ����ַ�����ȫ�������� ʱ�临�Ӷȣ�T(O((n + 1)!))
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

// �ÿռ任ȡʱ��,���ظ����ַ�����ȫ�������� ʱ�临�Ӷȣ�T(O(n!))
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
