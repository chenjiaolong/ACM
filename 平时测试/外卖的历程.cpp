#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERROR 0
#define OK 1
#define OVERFLOW -2

typedef struct node
{
    int data;
    struct node *next;
}QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
int InitQueue(LinkQueue *Q)
{
    Q -> front = Q -> rear = (QueuePtr )malloc(sizeof(QNode));
    if(!Q -> front) exit(OVERFLOW);
    Q -> front -> next = NULL;
    return OK;
}
void DestroyQueue(LinkQueue *Q)
{
    while(Q -> front)
    {
        Q -> rear = Q -> front -> next;
        free(Q -> front);
        Q -> front = Q -> rear;
    }
}
void ClearQueue(LinkQueue *Q)
{
    Q -> rear = Q -> front;
    QueuePtr p,q;
    p = Q -> front -> next;
    Q -> front -> next = NULL;
    while(p)
    {
        q = p -> next;
        free(p);
        p = q;
    }

}
int QueueLength(LinkQueue Q)
{
    int len = 0;
    QueuePtr p = Q.front;
    while(p != Q.rear)
    {
        len ++;
        p = p -> next;
    }
    return len;
}
bool EnQueue(LinkQueue *Q, int e)
{
    QueuePtr s = (QueuePtr )malloc(sizeof(QNode));
    if(!s) exit(OVERFLOW);
    s -> data = e;
    s -> next = NULL;
    Q -> rear -> next = s;
    Q -> rear = s;
    return OK;
}
bool DeQueue(LinkQueue *Q, int *e)
{
    if(Q -> front == Q -> rear) return ERROR;
    QueuePtr p = Q -> front -> next;
    *e = p -> data;
    Q ->  front -> next = p -> next;
    if(Q -> rear == p) Q -> rear = Q -> front;
    free(p);
    return OK;
}
int main(int argc, char *argv[])
{
    LinkQueue Q;
    InitQueue(&Q);
    int N,M;
    while(~scanf("%d%d",&N,&M))
    {
        ClearQueue(&Q);
        int volume = 0;
        while(N--)
        {
            int y, t;
            scanf("%d%d",&y, &t);
            EnQueue(&Q, t - 2 * y);
            if(QueueLength(Q) < M)
                printf("hungry\n");
            else if(QueueLength(Q) == M)
                printf("hehe\n");
            else
            {
                int e;
                DeQueue(&Q, &e);
                volume += e;
                printf("%d\n",volume);

            }
        }
    }
    DestroyQueue(&Q);
    return 0;
}
