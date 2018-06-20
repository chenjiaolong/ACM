#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;//动态分配数组存储赫夫曼树
typedef char **HuffmanCode;//动态分配数组存储赫夫曼编码
int Min(HuffmanTree HT, int i)
{
    int j, flag;
    unsigned int k = UINT_MAX;// 取k为不小于可能的值(即unsigned int类型的最大值)
    for(j = 1; j <= i; j++)
        if(HT[j].weight < k && HT[j].parent == 0)
            k = HT[j].weight, flag = j;
    HT[flag].parent = 1;
    return flag;
}// s1为最小的两个值中序号小的那个
void select(HuffmanTree HT, int i, int *s1, int *s2)
{
    int temp;
    *s1 = Min(HT, i);
    *s2 = Min(HT, i);
    if(*s1 > *s2)
    {
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
    }
}
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n)
{
    //w存放n个字符的权值（均>0）构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC。
    int m, i, s1, s2, start;
    unsigned c, f;
    HuffmanTree p;
    char *cd;
    if(n <= 1) return;
    m = 2 * n - 1;
    *HT = (HuffmanTree )malloc((m + 1) * sizeof(HTNode));//0号单元未用，申请m+1个赫夫曼结点
    for(p = *HT + 1,i = 1; i <= n; ++i, ++p, ++w)//初始化四元组，让待编码的数据成为叶结点
    {
        (*p).weight = *w;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    for(; i <= m; ++i, ++p)(*p).parent = 0;//将剩余的m-n个四元组初始化
    for(i = n + 1; i <= m; ++i)//建赫夫曼树
    {
        //在HT[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2。
        select(*HT, i - 1, &s1, &s2);
        (*HT)[s1].parent = (*HT)[s2].parent=i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
    //---从叶子到根逆向求每个字符的赫夫曼编码---
    *HC = (HuffmanCode )malloc((n + 1) * sizeof(char*));//分配n个字符编码的头指针向量
    cd = (char* )malloc(n * sizeof(char));//分配求编码的工作区间
    cd[n - 1] = '\0';//编码结束符
    for(i = 1; i <= n; i++)//逐个字符求赫夫曼编码
    {
        start = n - 1;//编码结束的位置
        for(c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)//从叶子到跟逆向求编码
            if((*HT)[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        (*HC)[i] = (char* )malloc((n - start) * sizeof(char));//为第i个字符编码分配空间
        strcpy((*HC)[i], &cd[start]);//从cd复制编码(串)到HC
    }
    free(cd);//释放工作区间
}
int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int *w, n, i;
    printf("请输入权值的个数(>1)：\n");
    scanf("%d", &n);
    w = (int* )malloc(n * sizeof(int));
    printf("请依次输入 %d 个权值(整型)：\n",n);
    for(i = 0; i <= n - 1; i++)
        scanf("%d", w + i);
    HuffmanCoding(&HT, &HC, w, n);
    for(i = 1; i <= n; i++)
        puts(HC[i]);
    return 0;
}
