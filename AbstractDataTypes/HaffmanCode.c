#include<stdio.h>
#include <string.h>
#include <limits.h>
#define N 4
#define M (2*N-1)
typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode;
typedef HTNode HaffmanTree[M];
typedef struct
{
	char data;
	int weight;
	char code[N];
}HTCode;
typedef HTCode HaffmanCode[N];

void initHaffmanCode(HaffmanCode hc)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("请输入第%d个字符和权值:", i + 1);
		fflush(stdin);
		scanf("%c%d", &hc[i].data, &hc[i].weight);
	}
}
void initHaffmanTree(HaffmanTree ht,HaffmanCode hc)
{
	int i;
	for (i = 0; i < N; i++)
		ht[i].weight = hc[i].weight;
	for (i = 0; i < M; i++)
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
}
void creatHaffmanTree(HaffmanTree ht)
{
	int i, j, min1, min2, index1, index2;
	for (i = N; i < M; i++)
	{
		min1 = min2 = INT_MAX;
		index1 = index2 = -1;
		for (j = 0; j < i; j++)
		{
			if (ht[j].parent == -1)
			{
				if (ht[j].weight < min1)
				{
					min2 = min1; index2 = index1;
					min1 = ht[j].weight; index1 = j;
				}
				else if (ht[j].weight < min2)
				{
					min2 = ht[j].weight; index2 = j;
				}
			}
		}
		ht[i].weight = min1 + min2;
		ht[i].lchild = index1; ht[i].rchild = index2;
		ht[index1].parent = ht[index2].parent = i;
	}
}
void creatHaffmanCode(HaffmanTree ht, HaffmanCode hc)
{
	char code[N];
	int i, start;
	code[N - 1] = '\0';
	for (i = 0; i < N; i++)
	{
		int j = i;
		start = N - 1;
		while(ht[j].parent != -1)
		{
			code[--start] = (ht[ht[j].parent].lchild == j)?'0':'1';
			j = ht[j].parent;
		}
		strcpy(hc[i].code, &code[start]);
	}
}
void printCode(HaffmanCode hc)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%c的编码是:%s\n", hc[i].data, hc[i].code);
}
int main()
{
	HaffmanCode hc;
	HaffmanTree ht;
	initHaffmanCode(hc);
	initHaffmanTree(ht, hc);
	creatHaffmanTree(ht);
	creatHaffmanCode(ht, hc);
	printCode(hc);
	return 0;
}
