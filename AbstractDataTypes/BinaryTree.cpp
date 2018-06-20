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
    while(p && !find)// 寻找被删元素
    {
        if(x == p -> value)// 找到被删元素
            find = true;
        else if(x < p -> value)// 沿左子树找
        {
            q = p;
            p = p -> lchild;
        }
        else// 沿右子树找
        {
            q = p;
            p = p -> rchild;
        }
    }
    if(p == NULL)
        cout << "没有找到" << x << endl;
    if(!find) return find;
    // puts("<<<<<<");
    if(p -> lchild == NULL && p -> rchild == NULL)
    {

        if(p == root)// p 为根节点
            root = NULL;
        else if(q -> lchild == p)
            q -> lchild = NULL;
        else
            q -> rchild = NULL;
        free(p);// 释放节点 p
    }
    else if(p -> lchild == NULL || p -> rchild == NULL)// p 为单支子树
    {
        if(p == root)// p为根节点
        {
            if(p -> lchild == NULL)
                root = p -> rchild;
            else
                root = p -> lchild;
        }
        else
        {
            if(q -> lchild == p && p -> lchild) // p 是 q 的左子树且 p 有左子树
                q -> lchild = p -> rchild;// 将 p 的左子树链接到 q 的左指针上
            else if(q -> lchild == p && p -> rchild)
                q -> lchild = p -> rchild;
            else if(q -> rchild == p && p -> lchild)
                q -> rchild = p -> lchild;
            else
                q -> rchild = p -> rchild;
        }
        free(p);
    }
    else// p 的左右子树均不为空
    {
        pnode t = p;
        pnode s = p -> lchild;// 从 p 的左子节点开始
        while(s -> rchild)// 找到 p 的前驱，即 p 左子树中的值最大的节点
        {
            t = s;
            s = s -> rchild;
        }
        p -> value = s -> value;// 把节点 s 的值赋给 p
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
        cout << "没有找到" << x << endl;
        return NULL;
    }
    cout << "找到" << x << endl;
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
        printf("地址为 %x\n", p);
    if(delete_BST(BT, 5))
        puts("5号元素删除成功");
    else
        puts("删除失败");
    p = search_BST(BT, 5);
    if(p)
        printf("地址为 %x\n", p);
    return 0;
}
