#include<stdio.h>
#include<malloc.h>

#define OK 1
#define EORROR 0
#define OVERFLOW -2

typedef int QElemType;
typedef int Status;

typedef struct QNode//�ڵ�ṹ
{
    QElemType data;
    struct QNode *next;
} QNode,*QueuePtr;
typedef struct//���е�����ṹ
{
    QueuePtr front;//��ͷָ��
    QueuePtr rear;//��βָ��
} LinkQueue;
Status InitQueue(LinkQueue *Q)
{
    Q -> front = Q -> rear = (QueuePtr )malloc(sizeof(QNode));
    if(!Q -> front)exit(OVERFLOW);
    Q -> front -> next = NULL;
    return OK;
}
Status DestroyQueue(LinkQueue *Q)
{
    while(Q -> front)
    {
        Q -> rear = Q -> front -> next;
        free(Q -> front);
        Q -> front = Q -> rear;
    }
    return OK;
}
Status ClearQueue(LinkQueue *Q)
{
    Q -> rear = Q -> front;
    QueuePtr p,q;
    p = Q -> front -> next;
    Q -> front -> next = NULL;
    while(p != NULL)
    {
        q = p;
        p = p -> next;
        free(q);
    }
    return OK;
}
Status QueueEmpty(LinkQueue Q)
{
    return (Q.front == Q.rear);
}
int QueueLength(LinkQueue Q)
{
    int len = 0;
    QueuePtr p;
    p = Q.front;
    while(p != Q.rear)
    {
        len ++;
        p = p -> next;
    }
    return len;
}
Status GetHead(LinkQueue Q,QElemType *e)
{
    if(Q.front == Q.rear) return EORROR;
    *e = Q.front -> next -> data;
    return OK;
}
Status EnQueue(LinkQueue *Q,QElemType e)
{
    QueuePtr s = (QueuePtr )malloc(sizeof(QNode));
    if(!s) exit(OVERFLOW);
    s -> data = e;
    s -> next = NULL;
    Q -> rear -> next = s;
    Q -> rear = s;
    return OK;
}
Status DeQueue(LinkQueue *Q,QElemType *e)
{
    if(Q -> front == Q -> rear) return EORROR;
    QueuePtr p = Q -> front -> next;
    *e = p -> data;
    Q -> front -> next = p -> next;
    if(Q -> rear == p) Q -> rear = Q -> front;
    free(p);
    return OK;
}
void QueueTraverse(LinkQueue Q)
{
    if(Q.front == Q.rear) return;
    QueuePtr p = Q.front -> next;
    while(p -> next)
    {
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("%d\n",p -> data);
}
int main()
{
    QElemType e;
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q,-5);
    EnQueue(&Q,5);
    EnQueue(&Q,10);
    printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n",QueueLength(Q));
    printf("���е�Ԫ������Ϊ��");
    QueueTraverse(Q);
    GetHead(Q,&e);
    printf("��ͷԪ���ǣ�%d\n",e);
    DeQueue(&Q,&e);
    printf("ɾ���˶�ͷԪ��%d\n",e);
    GetHead(Q,&e);
    printf("�µĶ�ͷԪ���ǣ�%d\n",e);
    ClearQueue(&Q);
    printf("��ն��к�,Q.front=%p Q.rear=%p Q.front->next=%x\n",Q.front,Q.rear,Q.front->next);
    DestroyQueue(&Q);
    printf("���ٶ��к�,Q.front=%x Q.rear=%x\n",Q.front, Q.rear);

//    int rt;
//    int value;
//    InitQueue(&Q);
//
//    if(QueueEmpty(Q)) puts("The Queue is empty!!!");
//    else puts("The Queue is not empty!!!");
//
//    EnQueue(&Q,1);
//    EnQueue(&Q,2);
//    EnQueue(&Q,3);
//    EnQueue(&Q,4);
//
//    QueueTraverse(Q);
//
//    int len = QueueLength(Q);
//    printf("The Queue's length is %d\n", len);
//
//    rt = GetHead(Q, &value);
//    if(rt) printf("%d is the Head elem.\n", value);
//    else puts("The Queue is nothing.");
//
//    DeQueue(&Q, &value);
//    printf("%d is DeQueued\n", value);
//
//    DeQueue(&Q, &value);
//    printf("%d is DeQueued\n", value);
//
//    while(!QueueEmpty(Q))
//    {
//        GetHead(Q, &value);
//        printf("%d ", value);
//        DeQueue(&Q, &value);
//    }
//    puts("");
//    ClearQueue(&Q);
//
//    rt = GetHead(Q, &value);
//    if(rt) printf("%d is the Head elem.\n", value);
//    else puts("The Queue is nothing.");
//
//    QueueTraverse(Q);
//    DestroyQueue(&Q);


    return 0;
}
