//已经二叉树的前序遍历和中序遍历 写出后序遍历算法
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct node
//{
//    char data;
//    struct node *lchild, *rchild;
//}BiTNode, *BiTree;                  // 定义节点的结构
//BiTree CreateTree(char *pre, char *in, int index) // 根据先序和中序遍历创建二叉树
//{
//    if(index <= 0 ) return NULL;
//    BiTree rt = (BiTree) malloc(sizeof(BiTNode));
//    rt -> data = *pre;
//    char *p = in;
//    for(; p != NULL; p ++)
//        if(*p == *pre) break; // 在中序遍历的序列中得到与先序相同的节点
//    int k = p - in;
//    rt -> lchild = CreateTree(pre + 1, in, k);//递归调用得到左子树
//    rt -> rchild = CreateTree(pre + k + 1, p + 1, index - k - 1);//得到右子树
//    return rt;
//}
//void PostOrder(BiTree rt)
//{
//    if(rt == NULL) return ;
//    PostOrder(rt -> lchild);
//    PostOrder(rt -> rchild);
//    putchar(rt -> data);
//}
//int main()
//{
//    char pre[35], in[35]; // 存储先序和中序遍历的序列
//    BiTree tree;
//    while(scanf("%s%s",pre, in) != EOF)
//    {
//        int len = strlen(pre);
//        tree = CreateTree(pre, in, len);
//        PostOrder(tree);
//        puts("");
//    }
//    return 0;
//}

//已经二叉树的前序遍历和中序遍历 写出后序遍历算法
//#include <stdio.h>
//#include<string.h>
//int Find(char ch, char *str, int s, int e)
//{
//     /* 找出中序中根的位置。 */
//    for(int i = s; i <= e; i ++)
//        if(str[i] == ch) return i;
//}
///* 其中pre[]表示先序，pre_s为先序的起始位置，pre_e为先序的终止位置。 */
///* 其中in[]表示中序，in_s为中序的起始位置，in_e为中序的终止位置。 */
///* PostOrder()求出pre[pre_s～pre_e]、in[in_s～in_e]构成的后序序列。 */
//void PostOrder(char *pre, int pre_s, int pre_e, char *in, int in_s, int in_e)
//{
//    if(in_s > in_e) return ;/* 非法子树，完成。 */
//    if(in_s == in_e)/* 子树子仅为一个节点时直接输出并完成。 */
//    {
//        putchar(in[in_s]);
//        return ;
//    }
//    char ch = pre[pre_s];/* ch储存根节点。 */
//    /* 在中序中找出根节点的位置。 */
//    int k = Find(ch, in, in_s, in_e);
//    PostOrder(pre, pre_s + 1, pre_s + k - in_s, in, in_s, k - 1);/* 递归求解分割的左子树。 */
//    PostOrder(pre, pre_s + k - in_s + 1, pre_e, in, k + 1, in_e);/* 递归求解分割的右子树。 */
//    putchar(ch);/* 根节点输出。 */
//}
//
//int main()
//{
//    char pre[]="abdc";
//    char in[]="bdac";
//    printf("The result:");
//    PostOrder(pre,0,strlen(in)-1,in,0,strlen(pre)-1);
//    return 0;
//}

// 已经二叉树的前序遍历和中序遍历 写出后序遍历算法
//#include<stdio.h>
//#include<stdfix.h>
//#include<string.h>
//void PostOrder(char *in, char *pre, int len, char *post, int &index)
//{
//    if(len <= 0) return ;
//    if(len == 1)
//    {
//        post[index ++] = *pre;
//        return;
//    }
//    char root = *pre;
//    int k = 0;
//    for(; k < len; k ++)
//        if(in[k] == root) break;
//    PostOrder(in, pre + 1, k, post, index);
//    PostOrder(in + k + 1, pre + k + 1, len - k - 1, post, index);
//    post[index ++] = root;
//}
//int main(int argc, char* argv[])
//{
//    char pPreOrder[] = "GDAFEMHZ";
//    char pInOrder[] = "ADEFGHMZ";
//    int size = sizeof(pInOrder) / sizeof(char);
//    // int size = strlen(pInOrder);
//    // printf("%d\n",size);
//    char *pPostOrder = new char[size];
//    int nIndex = 0;
//    PostOrder(pInOrder, pPreOrder, size - 1, pPostOrder, nIndex);
//    pPostOrder[size - 1] = 0;
//    puts(pPostOrder);
//    return 0;
//}

// 已知二叉树的中序遍历和后序遍历，写出先序遍历的算法
//#include<stdio.h>
//#include<stdfix.h>
//#include<string.h>
//void PreOrder(char *in, char *post, int len, char *pre, int &index)
//{
//    if(len <= 0) return ;
//    if(len == 1)
//    {
//        pre[index ++] = *post;
//        return;
//    }
//    char root = post[len - 1];
//    pre[index ++] = root;
//    int k = 0;
//    for(; k < len; k ++)
//        if(in[k] == root) break;
//    PreOrder(in, post, k, pre, index);
//    PreOrder(in + k + 1, post + k, len - k - 1, pre, index);
//}
//int main(int argc, char* argv[])
//{
//    char pInOrder[] = "ADEFGHMZ";
//    char pPostOrder[] = "AEFDHZMG";
//    int size = sizeof(pInOrder) / sizeof(char);
//    // int size = strlen(pInOrder);
//    // printf("%d\n",size);
//    char *pPreOrder = new char[size];
//    int nIndex = 0;
//    PreOrder(pInOrder, pPostOrder, size - 1, pPreOrder, nIndex);
//    pPreOrder[size - 1] = 0;
//    puts(pPreOrder);
//    return 0;
//}

//已知二叉树的中序遍历和后序遍历，写出先序遍历的算法
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

string pre;

void PreOrder(string in, string post)
{
    if(post.length() == 1)
    {
        pre += post;
        return ;
    }
    int k = in.find(post.substr(post.length() - 1, 1));
    pre += in[k];
    if(k > 0) PreOrder(in.substr(0, k), post.substr(0, k));
    if(k < in.length() - 1) PreOrder(in.substr(k + 1, in.length() - k - 1), post.substr(k, post.length() - k - 1));
}

int main()
{
    string in, post;
    while(cin >> in >> post)
    {
        PreOrder(in, post);
        cout << pre << endl;
        pre.clear();
    }
    return 0;
}
