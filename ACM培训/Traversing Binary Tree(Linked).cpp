#include<cstdio>
#include<cstdlib>
struct BinaryTreeNode
{
    char data;
    struct BinaryTreeNode *Lchild,*Rchild;
};
typedef struct BinaryTreeNode BiTNode,*BiTree;
void CreateBinaryTree(BiTree &T)//���������˳�򴴽�������
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
    {
        T=NULL;
        return;
    }
    T=(BiTNode *)malloc(sizeof(BiTNode));
    T->data=ch;
    CreateBinaryTree(T->Lchild);
    CreateBinaryTree(T->Rchild);

}
void PreOrdertraverse(BiTree T)//�������
{
    if(T)
    {
        printf("%c",T->data);
        PreOrdertraverse(T->Lchild);
        PreOrdertraverse(T->Rchild);
    }
}
void InOrdertraverse(BiTree T)//�������
{
    if(T)
    {
        InOrdertraverse(T->Lchild);
        printf("%c",T->data);
        InOrdertraverse(T->Rchild);
    }
}
void TailOrdertraverse(BiTree T)//�������
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
    CreateBinaryTree(tree);
    PreOrdertraverse(tree);
    printf("\n");
    InOrdertraverse(tree);
    printf("\n");
    TailOrdertraverse(tree);
    printf("\n");
    printf("\n");
    return 0;
}
