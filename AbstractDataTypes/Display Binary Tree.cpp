//�Ѿ���������ǰ�������������� д����������㷨
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct node
//{
//    char data;
//    struct node *lchild, *rchild;
//}BiTNode, *BiTree;                  // ����ڵ�Ľṹ
//BiTree CreateTree(char *pre, char *in, int index) // ��������������������������
//{
//    if(index <= 0 ) return NULL;
//    BiTree rt = (BiTree) malloc(sizeof(BiTNode));
//    rt -> data = *pre;
//    char *p = in;
//    for(; p != NULL; p ++)
//        if(*p == *pre) break; // ����������������еõ���������ͬ�Ľڵ�
//    int k = p - in;
//    rt -> lchild = CreateTree(pre + 1, in, k);//�ݹ���õõ�������
//    rt -> rchild = CreateTree(pre + k + 1, p + 1, index - k - 1);//�õ�������
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
//    char pre[35], in[35]; // �洢������������������
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

//�Ѿ���������ǰ�������������� д����������㷨
//#include <stdio.h>
//#include<string.h>
//int Find(char ch, char *str, int s, int e)
//{
//     /* �ҳ������и���λ�á� */
//    for(int i = s; i <= e; i ++)
//        if(str[i] == ch) return i;
//}
///* ����pre[]��ʾ����pre_sΪ�������ʼλ�ã�pre_eΪ�������ֹλ�á� */
///* ����in[]��ʾ����in_sΪ�������ʼλ�ã�in_eΪ�������ֹλ�á� */
///* PostOrder()���pre[pre_s��pre_e]��in[in_s��in_e]���ɵĺ������С� */
//void PostOrder(char *pre, int pre_s, int pre_e, char *in, int in_s, int in_e)
//{
//    if(in_s > in_e) return ;/* �Ƿ���������ɡ� */
//    if(in_s == in_e)/* �����ӽ�Ϊһ���ڵ�ʱֱ���������ɡ� */
//    {
//        putchar(in[in_s]);
//        return ;
//    }
//    char ch = pre[pre_s];/* ch������ڵ㡣 */
//    /* ���������ҳ����ڵ��λ�á� */
//    int k = Find(ch, in, in_s, in_e);
//    PostOrder(pre, pre_s + 1, pre_s + k - in_s, in, in_s, k - 1);/* �ݹ����ָ���������� */
//    PostOrder(pre, pre_s + k - in_s + 1, pre_e, in, k + 1, in_e);/* �ݹ����ָ���������� */
//    putchar(ch);/* ���ڵ������ */
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

// �Ѿ���������ǰ�������������� д����������㷨
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

// ��֪����������������ͺ��������д������������㷨
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

//��֪����������������ͺ��������д������������㷨
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
