#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct node
{
    int value;
    struct node *lchild;
    struct node *rchild;
}*pnode;
#define LEN sizeof(node)
pnode insert(pnode &root, int x)
{
    if(root == NULL)
    {
        pnode p = (pnode )malloc(LEN);
        p -> value = x;
        p -> lchild = NULL;
        p -> rchild = NULL;
        root = p;
    }
    else if(x < root -> value)
        root -> lchild = insert(root -> lchild, x);
    else
        root -> rchild = insert(root -> rchild, x);
    return root;
}
bool delete_BST(pnode &root, int x)
{
    bool find = false;
    pnode p, q;
    p = root;
    while(p && !find)// Ѱ�ұ�ɾԪ��
    {
        if(x == p -> value)// �ҵ���ɾԪ��
            find = true;
        else if(x < p -> value)// ����������
        {
            q = p;
            p = p -> lchild;
        }
        else// ����������
        {
            q = p;
            p = p -> rchild;
        }
    }
    if(p == NULL)
        cout << "û���ҵ�" << x << endl;
    if(!find) return find;
    // puts("<<<<<<");
    if(p -> lchild == NULL && p -> rchild == NULL)
    {

        if(p == root)// p Ϊ���ڵ�
            root = NULL;
        else if(q -> lchild == p)
            q -> lchild = NULL;
        else
            q -> rchild = NULL;
        free(p);// �ͷŽڵ� p
    }
    else if(p -> lchild == NULL || p -> rchild == NULL)// p Ϊ��֧����
    {
        if(p == root)// pΪ���ڵ�
        {
            if(p -> lchild == NULL)
                root = p -> rchild;
            else
                root = p -> lchild;
        }
        else
        {
            if(q -> lchild == p && p -> lchild) // p �� q ���������� p ��������
                q -> lchild = p -> rchild;// �� p �����������ӵ� q ����ָ����
            else if(q -> lchild == p && p -> rchild)
                q -> lchild = p -> rchild;
            else if(q -> rchild == p && p -> lchild)
                q -> rchild = p -> lchild;
            else
                q -> rchild = p -> rchild;
        }
        free(p);
    }
    else// p ��������������Ϊ��
    {
        pnode t = p;
        pnode s = p -> lchild;// �� p �����ӽڵ㿪ʼ
        while(s -> rchild)// �ҵ� p ��ǰ������ p �������е�ֵ���Ľڵ�
        {
            t = s;
            s = s -> rchild;
        }
        p -> value = s -> value;// �ѽڵ� s ��ֵ���� p
        if(t == p)
            p -> lchild = s -> lchild;
        else
            t -> rchild = s -> lchild;
        free(s);
    }
    return find;
}
pnode search_BST(pnode p, int x)
{
    bool solve = false;
    while(p && !solve)
    {
        if(x == p -> value)
            solve = true;
        else if(x < p -> value)
            p = p -> lchild;
        else
            p = p -> rchild;
    }
    if(p == NULL)
    {
        cout << "û���ҵ�" << x << endl;
        return NULL;
    }
    cout << "�ҵ�" << x << endl;
    return p;
}
int main()
{
    int array[15] = {15, 5, 3, 12, 16, 20, 23, 13, 18, 10, 6, 7};
    pnode BT = NULL;
    for(int i = 0; i < 12; i ++)
        insert(BT,array[i]);
    pnode p = search_BST(BT,12);
    if(p)
        printf("��ַΪ %x\n", p);
    if(delete_BST(BT, 5))
        puts("5��Ԫ��ɾ���ɹ�");
    else
        puts("ɾ��ʧ��");
    p = search_BST(BT, 5);
    if(p)
        printf("��ַΪ %x\n", p);
    return 0;
}
