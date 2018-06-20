#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char data;
    struct node *LChild, *RChild;
} BiTNode, *BiTree;
char str[1005];
int index = 0;
void CreateBinaryTree(BiTree *T)
{
    char ch;
    ch = str[index++];
    if(ch == '#')
    {
        *T = NULL;
        return;
    }
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T) -> data = ch;
    CreateBinaryTree(&(*T) -> LChild);
    CreateBinaryTree(&(*T) -> RChild);
}
void PreOrdertraverse(BiTree T, int depth)
{
    if(T)
    {
        for(int i = 0; i < 3 * depth; i++)
            printf(" ");
        printf("%c\n",T->data);
        PreOrdertraverse(T->LChild, depth + 1);
        PreOrdertraverse(T->RChild, depth + 1);
    }
}
void DestroyBinaryTree(BiTree *T)
{
    if(*T)
    {
        if((*T) -> LChild)
            DestroyBinaryTree(&(*T) -> LChild);
        if((*T) -> RChild)
            DestroyBinaryTree(&(*T) -> RChild);
        free(*T);
        *T = NULL;
    }
}
int main()
{
    BiTree tree;
    while(scanf("%s", str) != EOF && str[0] != '#')
    {
        index = 0;
        CreateBinaryTree(&tree);
        PreOrdertraverse(tree, 0);
        printf("\n");
        DestroyBinaryTree(&tree);
    }
    return 0;
}
