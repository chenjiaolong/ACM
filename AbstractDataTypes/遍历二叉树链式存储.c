#include<stdio.h>
#include<stdlib.h>
typedef struct BinaryTreeNode
{
    char data;
    struct BinaryTreeNode *Lchild,*Rchild;
} BiTNode,*BiTree;
void CreateBinaryTree(BiTree *T)//CreateBinaryTree(BiTree *T)等价于CreateBinaryTree(BiTNode **T)
//按照先序的顺序创建二叉树
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
    {
        *T=NULL;
        return;
    }
    *T=(BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data=ch;
    CreateBinaryTree(&(*T)->Lchild);
    CreateBinaryTree(&(*T)->Rchild);

}
void PreOrdertraverse(BiTree T)//先序遍历
{
    if(T)
    {
        printf("%c",T->data);
        PreOrdertraverse(T->Lchild);
        PreOrdertraverse(T->Rchild);
    }
}
void InOrdertraverse(BiTree T)//中序遍历
{
    if(T)
    {
        InOrdertraverse(T->Lchild);
        printf("%c",T->data);
        InOrdertraverse(T->Rchild);
    }
}
void TailOrdertraverse(BiTree T)//后序遍历
{
    if(T)
    {
        TailOrdertraverse(T->Lchild);
        TailOrdertraverse(T->Rchild);
        printf("%c",T->data);
    }
}
int main()
{
    BiTree tree;
    CreateBinaryTree(&tree);
    PreOrdertraverse(tree);
    printf("\n");
    InOrdertraverse(tree);
    printf("\n");
    TailOrdertraverse(tree);
    printf("\n");
    printf("\n");
    return 0;
}

