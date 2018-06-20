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
//} HTNode, *HuffmanTree; //��̬��������洢�շ�����
//typedef char **HuffmanCode;//��̬��������洢�շ��������
//int Min(HuffmanTree HT,int i)
//{
//    int j, flag;
//    unsigned int k = UINT_MAX;// ȡkΪ��С�ڿ��ܵ�ֵ(��unsigned int���͵����ֵ)
//    for(j = 1; j <= i; j++)
//        if(HT[j].weight < k && HT[j].parent == 0)
//            k = HT[j].weight,flag = j;
//    HT[flag].parent = 1;
//    return flag;
//}// s1Ϊ��С������ֵ�����С���Ǹ�
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
////w���n���ַ���Ȩֵ����>0������շ�����HT�������n���ַ��ĺշ�������HC��
//{
//    int m, i, s1, s2, start;
//    unsigned c, f;
//    HuffmanTree p;
//    char *cd;
//    if(n <= 1) return;
//    m=2 * n - 1;
//    HT = (HuffmanTree )malloc((m + 1)* sizeof(HTNode));//0�ŵ�Ԫδ�ã�����m+1���շ������
//    for(p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
//        *p = {*w,0,0,0};//��ʼ����Ԫ�飬�ô���������ݳ�ΪҶ���
//    for(; i <= m; ++i,++p)
//        *p = {0,0,0,0};//��ʣ���m-n����Ԫ���ʼ��
//    for(i = n + 1; i <= m; ++i)//���շ�����
//    {
//        //��HT[1..i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2��
//        Select(HT, i - 1, &s1, &s2);
//        HT[s1].parent = HT[s2].parent = i;
//        HT[i].lchild = s1;
//        HT[i].rchild = s2;
//        HT[i].weight = HT[s1].weight + HT[s2].weight;
//    }
////---��Ҷ�ӵ���������ÿ���ַ��ĺշ�������---
//    HC = (HuffmanCode )malloc((n + 1) * sizeof(char *));//����n���ַ������ͷָ������
//
//    cd=(char *)malloc(n * sizeof(char));//���������Ĺ�������
//    cd[n - 1] = '\0';//���������
//    for(i = 1; i <= n; ++i) //����ַ���շ�������
//    {
//        start = n - 1;//���������λ��
//        for(c = i, f = HT[i].parent; f != 0; c = f, f=HT[f].parent)//��Ҷ�ӵ������������
//            if(HT[f].lchild == c)
//                cd[--start] = '0';
//            else
//                cd[--start] = '1';
//        HC[i] = (char *)malloc((n - start) * sizeof(char));//λ��i���ַ��������ռ�
//        strcpy(HC[i], &cd[start]);//��cd���Ʊ���(��)��HC
//    }
//    free(cd);//�ͷŹ�������
//}
//int main()
//{
//    HuffmanTree HT;
//    HuffmanCode HC;
//    int *w,n,i;
//    printf("������Ȩֵ�ĸ���(>1)��\n");
//    scanf("%d", &n);
//    w=(int*)malloc(n * sizeof(int));
//    printf("����������%d��Ȩֵ(����)��\n",n);
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
} HTNode; //��������������
typedef struct QHcode
{
    char *code;
    int start;
} Hcode; //���������������
int p1,p2;
void CreateHuffmanCode(HTNode HT[],Hcode HC[],int n)//����������������
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
void twomin(HTNode HT[],int num);//�Ƚ����н���ҵ�����Ȩֵ��С�Ľ��
void CreatHuffmanTree(HTNode HT[],int n)//������������
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
        cout<<"�����"<<i<<"���ַ���Ȩֵ"<<endl;
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
    while(HT[i].parent!=0)//�ҵ�ɭ���еĵ�һ�����
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
    HT[p1].parent=1;//�����ҵ��ĵ�һ������˫��Ϊ1���Ա���ڶ������ҵ��ý��
    i=0;
    while(HT[i].parent!=0)//�ҵ�ɭ���еĵڶ������
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
void DisplayTree(HTNode tree[],Hcode HC[],int Number)//��������Ĺ�������
{
    for(int i=0; i<2*Number-1; i++)
    {
        printf("%5d",tree[i].weight);
    }
    printf("\n");
    for(int i=0; i<Number; i++)
    {
        printf("%2d %3c:",i,tree[i].data);//�����ǰԪ�ص�parentֵ
        printf("%s\n",HC[i].code);//�����ǰԪ�ص�weightֵ
    }
}
int main()
{
    int InputNumber;//����ɭ�ֽ��ĸ���
    HTNode mytree[30];//����һ���ù�������
    Hcode code[30];
    printf("�������������\n");
    scanf("%d",&InputNumber);
    CreatHuffmanTree( mytree,InputNumber);//�����������
    CreateHuffmanCode(mytree,code,InputNumber );
    DisplayTree(mytree,code,InputNumber);//�����������
}

