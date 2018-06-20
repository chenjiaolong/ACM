#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    long long data;
    struct node *next;
} SNode,*LinkStack;
LinkStack InitStack()
{
    LinkStack top = (LinkStack )malloc(sizeof(SNode));
    top -> next = NULL;
    return top;
}
void DestoryStack(LinkStack top)
{
    SNode *p;
    while(top)
    {
        p = top -> next;
        free(top);
        top = p;
    }
}
void ClearStack(LinkStack top)
{
    LinkStack p,q;
    p = top -> next;
    while(p)
    {
        q = p -> next;
        free(p);
        p = q;
    }
    top -> next = NULL;
}
bool Push(LinkStack top,long long e)
{
    LinkStack tNew = (LinkStack )malloc(sizeof(SNode));
    if(!tNew)
        return false;
    tNew -> data = e;
    tNew -> next = top -> next;
    top -> next = tNew;
    return true;
}
bool Pop(LinkStack top)
{
    if(top -> next == NULL)
        return false;
    LinkStack p = top -> next;
    top -> next = p -> next;
    free(p);
    return true;
}
long long GetTop(LinkStack top)
{
    return top -> next -> data;
}
int StackLength(LinkStack top)
{
    int len = 0;
    top = top -> next;
    while(top)
    {
        len ++;
        top = top -> next;
    }
    return len;
}
int main(int argc, char *argv[])
{
    //freopen("f.out","w",stdout);
    LinkStack top = InitStack();
    int T;
    while(~scanf("%d",&T))
    {
        ClearStack(top);
        int L;
        long long HP;
        scanf("%d%lld",&L,&HP);
        while(T --)
        {
            char str[20];
            scanf("%s",str);
            if(strcmp(str, "add") == 0)
            {
                long long N;
                scanf("%lld",&N);
                //printf("%d\n", StackLength(top));
                if(StackLength(top)== L)
                    continue;
                Push(top,N);
            }
            else if(strcmp(str, "chungedapao") == 0)
            {
                if(StackLength(top) == 0)
                {
                    printf("%lld\n",HP);
                    continue;
                }
                long long damage = GetTop(top);
                //printf("%lld\n",damage);
                HP -= damage;
                if(HP <= 0)
                {
                    printf("chungeV5\n");
                    continue;
                }
                else
                    printf("%lld\n",HP);
                Pop(top);
            }
        }
    }
    DestoryStack(top);
    return 0;
}
