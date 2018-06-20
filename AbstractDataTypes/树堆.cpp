//#include<stdio.h>
//#include<stdlib.h>
//#include<streaping.h>
//#include<algorithm>
//using namespace std;
//struct data
//{
//    int l,r,v,size,rnd,w;
//} treap[100005];
//int n,size,root,ans;
//void update(int k)//更新结点信息
//{
//    treap[k].size=treap[treap[k].l].size+treap[treap[k].r].size+treap[k].w;
//}
//void rturn(int &k)
//{
//    int t=treap[k].l;
//    treap[k].l=treap[t].r;
//    treap[t].r=k;
//    treap[t].size=treap[k].size;
//    update(k);
//    k=t;
//}
//void lturn(int &k)
//{
//    int t=treap[k].r;
//    treap[k].r=treap[t].l;
//    treap[t].l=k;
//    treap[t].size=treap[k].size;
//    update(k);
//    k=t;
//}
//void insert(int &k,int x)
//{
//    if(k==0)
//    {
//        size++;
//        k=size;
//        treap[k].size=treap[k].w=1;
//        treap[k].v=x;
//        treap[k].rnd=rand();
//        return;
//    }
//    treap[k].size++;
//    if(treap[k].v==x)treap[k].w++;
//    else if(x>treap[k].v)
//    {
//        insert(treap[k].r,x);
//        if(treap[treap[k].r].rnd<treap[k].rnd)lturn(k);
//    }
//    else
//    {
//        insert(treap[k].l,x);
//        if(treap[treap[k].l].rnd<treap[k].rnd)rturn(k);
//    }
//}
//void del(int &k,int x)
//{
//    if(k==0)return;
//    if(treap[k].v==x)
//    {
//        if(treap[k].w>1)
//        {
//            treap[k].w--;
//            treap[k].size--;
//            return;
//        }
//        if(treap[k].l*treap[k].r==0)k=treap[k].l+treap[k].r;
//        else if(treap[treap[k].l].rnd<treap[treap[k].r].rnd)
//            rturn(k),del(k,x);
//        else lturn(k),del(k,x);
//    }
//    else if(x>treap[k].v)
//        treap[k].size--,del(treap[k].r,x);
//    else treap[k].size--,del(treap[k].l,x);
//}
//int query_rank(int k,int x)
//{
//    if(k==0)return 0;
//    if(treap[k].v==x)return treap[treap[k].l].size+1;
//    else if(x>treap[k].v)
//        return treap[treap[k].l].size+treap[k].w+query_rank(treap[k].r,x);
//    else return query_rank(treap[k].l,x);
//}
//int query_num(int k,int x)
//{
//    if(k==0)return 0;
//    if(x<=treap[treap[k].l].size)
//        return query_num(treap[k].l,x);
//    else if(x>treap[treap[k].l].size+treap[k].w)
//        return query_num(treap[k].r,x-treap[treap[k].l].size-treap[k].w);
//    else return treap[k].v;
//}
//void query_pro(int k,int x)
//{
//    if(k==0)return;
//    if(treap[k].v<x)
//    {
//        ans=k;
//        query_pro(treap[k].r,x);
//    }
//    else query_pro(treap[k].l,x);
//}
//void query_sub(int k,int x)
//{
//    if(k==0)return;
//    if(treap[k].v>x)
//    {
//        ans=k;
//        query_sub(treap[k].l,x);
//    }
//    else query_sub(treap[k].r,x);
//}
//int main()
//{
//    scanf("%d",&n);
//    int opt,x;
//    for(int i=1; i<=n; i++)
//    {
//        scanf("%d%d",&opt,&x);
//        switch(opt)
//        {
//        case 1:
//            insert(root,x);
//            break;
//        case 2:
//            del(root,x);
//            break;
//        case 3:
//            printf("%d\n",query_rank(root,x));
//            break;
//        case 4:
//            printf("%d\n",query_num(root,x));
//            break;
//        case 5:
//            ans=0;
//            query_pro(root,x);
//            printf("%d\n",treap[ans].v);
//            break;
//        case 6:
//            ans=0;
//            query_sub(root,x);
//            printf("%d\n",treap[ans].v);
//            break;
//        }
//    }
//    return 0;
//}

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    struct node* left;// 左节点
    struct node* right;// 右节点
    int priority;// 优先级
    int key; // 存储的关键字
} *Node;

typedef struct treap
{
    Node root;
} *Treap;
// 左旋转
void rotate_left(Node* node)
{
    Node x = (*node) -> right;
    (*node) -> right = x -> left;
    x -> left = *node;
    *node = x;
}
// 右旋转
void rotate_right(Node* node)
{
    Node x = (*node) -> left;
    (*node) -> left = x -> right;
    x -> right = *node;
    *node = x;
}
// 插入操作
void treap_insert(Node* root, int key, int priority)
{
    // 根为 NULL, 则直接创建该节点为根节点
    if(*root == NULL)
    {
        *root = (Node) malloc(sizeof(struct node));
        (*root) -> left = NULL;
        (*root) -> right = NULL;
        (*root) -> priority = priority;
        (*root) -> key = key;
        return ;
    }
    // 向右插入节点
    else if(key < (*root) -> key)
    {
        treap_insert(&((*root) -> left), key, priority);
        if((*root) -> left -> priority < (*root) -> priority)
            rotate_right(root);
    }
    // 向左插入节点
    else
    {
        treap_insert(&((*root) -> right), key, priority);
        if((*root) -> right -> priority < (*root) -> priority)
            rotate_left(root);
    }
}
void treap_delete(Node* root, int key)
{
    if(*root != NULL)
    {
        if(key < (*root) -> key)
            treap_delete(&((*root) -> left), key);
        else if(key > (*root) -> key)
            treap_delete(&((*root) -> right), key);
        else
        {
            // 左右孩子都为空不用单独写出来
            if((*root) -> left ==  NULL)
                *root = (*root) -> right;
            else if((*root) -> right == NULL)
                *root = (*root) -> left;
            else
            {
                // 先旋转，然后再删除
                if((*root) -> left -> priority < (*root) -> right -> priority)
                {
                    rotate_right(root);
                    treap_delete(&((*root) -> right), key);
                }
                else
                {
                    rotate_left(root);
                    treap_delete(&((*root) -> left), key);
                }
            }
        }
    }
}
// 中序遍历
void in_order_traverse(Node root)
{
    if(root != NULL)
    {
        in_order_traverse(root -> left);
        printf("%d\t", root -> key);
        in_order_traverse(root -> right);
    }
}
// 计算树的深度
int depth(Node node)
{
    if(node == NULL)
        return -1;
    int l = depth(node -> left);
    int r = depth(node -> right);

    return (l < r) ? (r + 1) : (l + 1);
}
int main()
{
    Treap treap = (Treap)malloc(sizeof(struct treap));
    treap -> root = NULL;
    srand(time(0));

    for(int i = 0; i < 5; i ++)
        treap_insert(&(treap -> root),i, rand());
    in_order_traverse(treap -> root);
    printf("\n高度：%d\n", depth(treap -> root));

    puts("---分割线---");
    for(int i = 23; i < 59; i ++)
        treap_delete(&(treap -> root), i);
    in_order_traverse(treap -> root);
    printf("\n高度：%d\n", depth(treap -> root));

    return 0;
}


