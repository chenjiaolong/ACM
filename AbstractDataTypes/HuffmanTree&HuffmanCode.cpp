//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//#include<stdlib.h>
//#include <limits.h>
//
//using namespace std;
//
//typedef struct
//{
//    unsigned int weight;
//    unsigned int parent, lchild, rchild;
//} HTNode, *HuffmanTree; //动态分配数组存储赫夫曼树
//typedef char **HuffmanCode;//动态分配数组存储赫夫曼编码表
//int Min(HuffmanTree HT,int i)
//{
//    int j, flag;
//    unsigned int k = UINT_MAX;// 取k为不小于可能的值(即unsigned int类型的最大值)
//    for(j = 1; j <= i; j++)
//        if(HT[j].weight < k && HT[j].parent == 0)
//            k = HT[j].weight,flag = j;
//    HT[flag].parent = 1;
//    return flag;
//}// s1为最小的两个值中序号小的那个
//void Select(HuffmanTree HT, int i, int *s1, int*s2)
//{
//    int temp;
//    *s1 = Min(HT, i);
//    *s2 = Min(HT, i);
//    if(*s1 > *s2)
//    {
//        temp = *s1;
//        *s1 = *s2;
//        *s2 = temp;
//    }
//}
//void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
////w存放n个字符的权值（均>0）构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC。
//{
//    int m, i, s1, s2, start;
//    unsigned c, f;
//    HuffmanTree p;
//    char *cd;
//    if(n <= 1) return;
//    m=2 * n - 1;
//    HT = (HuffmanTree )malloc((m + 1)* sizeof(HTNode));//0号单元未用，申请m+1个赫夫曼结点
//    for(p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
//        *p = {*w,0,0,0};//初始化四元组，让待编码的数据成为叶结点
//    for(; i <= m; ++i,++p)
//        *p = {0,0,0,0};//将剩余的m-n个四元组初始化
//    for(i = n + 1; i <= m; ++i)//建赫夫曼树
//    {
//        //在HT[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2。
//        Select(HT, i - 1, &s1, &s2);
//        HT[s1].parent = HT[s2].parent = i;
//        HT[i].lchild = s1;
//        HT[i].rchild = s2;
//        HT[i].weight = HT[s1].weight + HT[s2].weight;
//    }
////---从叶子到根逆向求每个字符的赫夫曼编码---
//    HC = (HuffmanCode )malloc((n + 1) * sizeof(char *));//分配n个字符编码的头指针向量
//
//    cd=(char *)malloc(n * sizeof(char));//分配求编码的工作区间
//    cd[n - 1] = '\0';//编码结束符
//    for(i = 1; i <= n; ++i) //逐个字符求赫夫曼编码
//    {
//        start = n - 1;//编码结束的位置
//        for(c = i, f = HT[i].parent; f != 0; c = f, f=HT[f].parent)//从叶子到跟逆向求编码
//            if(HT[f].lchild == c)
//                cd[--start] = '0';
//            else
//                cd[--start] = '1';
//        HC[i] = (char *)malloc((n - start) * sizeof(char));//位第i个字符编码分配空间
//        strcpy(HC[i], &cd[start]);//从cd复制编码(串)到HC
//    }
//    free(cd);//释放工作区间
//}
//int main()
//{
//    HuffmanTree HT;
//    HuffmanCode HC;
//    int *w,n,i;
//    printf("请输入权值的个数(>1)：\n");
//    scanf("%d", &n);
//    w=(int*)malloc(n * sizeof(int));
//    printf("请依次输入%d个权值(整型)：\n",n);
//    for(i = 0; i <= n - 1; i++)
//        scanf("%d",w + i);
//    HuffmanCoding(HT, HC, w, n);
//    for(i = 1; i <= n; i++)
//        puts(HC[i]);
//    return 0;
//}

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct
{
    char data;
    int weight;
    int parent,lchild,rchild;
} HTNode; //定义哈夫曼树结点
typedef struct QHcode
{
    char *code;
    int start;
} Hcode; //定义哈夫曼结点编码
int p1,p2;
void CreateHuffmanCode(HTNode HT[],Hcode HC[],int n)//建立哈夫曼树编码
{
    int i,f,c,start;
    char *cd;
    cd=(char *)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=0; i<n; ++i)
    {
        start=n-1;
        c=i;
        while((f=HT[c].parent)!=0)
        {
            if(HT[f].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
            c=f;
        }
        HC[i].code=(char *)malloc((n-start)*sizeof(char));
        strcpy(HC[i].code,&cd[start]);
    }
    free(cd);
}
void twomin(HTNode HT[],int num);//比较所有结点找到两个权值最小的结点
void CreatHuffmanTree(HTNode HT[],int n)//建立哈夫曼树
{
    int i;
    for(i=0; i<2*n; i++)
    {
        HT[i].data=0;
        HT[i].weight=0;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    cout<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"输入第"<<i<<"个字符和权值"<<endl;
        cin>>HT[i].data;
        cin>>HT[i].weight;
    }
    for(i=n; i<2*n-1; i++)
    {
        twomin(HT,i);
        HT[p1].parent=i;
        HT[p2].parent=i;
        HT[i].lchild=p1;
        HT[i].rchild=p2;
        HT[i].weight=HT[p1].weight+HT[p2].weight;
    }
}
void twomin(HTNode HT[],int num)
{
    int min1,min2;
    int i=0,j;
    while(HT[i].parent!=0)//找到森林中的第一个结点
        i++;
    p1=i;
    min1=HT[i].weight;
    for(j=i+1; j<num; j++)
    {
        if((HT[j].parent==0)&&min1>HT[j].weight)
        {
            min1=HT[j].weight;
            p1=j;
        }
    }
    i++;
    HT[p1].parent=1;//假设找到的第一个结点的双亲为1，以避免第二次再找到该结点
    i=0;
    while(HT[i].parent!=0)//找到森林中的第二个结点
        i++;
    p2=i;
    min2=HT[i].weight;
    for(j=i+1; j<num; j++)
    {
        if((HT[j].parent==0)&&min2>HT[j].weight)
        {
            min2=HT[j].weight;
            p2=j;
        }
    }
}
void DisplayTree(HTNode tree[],Hcode HC[],int Number)//输出建立的哈夫曼树
{
    for(int i=0; i<2*Number-1; i++)
    {
        printf("%5d",tree[i].weight);
    }
    printf("\n");
    for(int i=0; i<Number; i++)
    {
        printf("%2d %3c:",i,tree[i].data);//输出当前元素的parent值
        printf("%s\n",HC[i].code);//输出当前元素的weight值
    }
}
int main()
{
    int InputNumber;//输入森林结点的个数
    HTNode mytree[30];//申明一个棵哈夫曼树
    Hcode code[30];
    printf("请输入结点个数：\n");
    scanf("%d",&InputNumber);
    CreatHuffmanTree( mytree,InputNumber);//构造哈夫曼树
    CreateHuffmanCode(mytree,code,InputNumber );
    DisplayTree(mytree,code,InputNumber);//输出哈夫曼树
}

