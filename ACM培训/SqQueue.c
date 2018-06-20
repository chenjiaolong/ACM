#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define QUEUE_SIZE 1000
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef  int QElemType; //polymorphic date type
typedef int Status;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
Status InitQueue(SqQueue *Q)
{

    Q -> base = (QElemType *)malloc(sizeof(QElemType) * QUEUE_SIZE);

    if(!Q -> base)exit(OVERFLOW);
    Q -> front = Q -> rear = 0;
    return OK;
}
void DestroyQueue(SqQueue *Q)
{
    free(Q -> base);
    Q -> base = NULL;
    Q -> front = Q -> rear = 0;
}
void ClearQueue(SqQueue *Q)
{
    Q -> front = Q -> rear = 0;
}
bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + QUEUE_SIZE) % QUEUE_SIZE;
}
bool GetHead(SqQueue Q, int *e)
{
    if(Q.rear == Q.front) return false;
    *e = Q.base[Q.front];
    return true;
}
Status EnQueue(SqQueue *Q,QElemType e)
{
    if( ( Q -> rear + 1 ) % QUEUE_SIZE == Q -> front)return ERROR;
    Q -> base[Q -> rear] = e;
    Q -> rear = ( Q -> rear + 1 ) % QUEUE_SIZE;
    return OK;
}
Status DeQueue(SqQueue *Q,QElemType *e)
{
    if(Q -> rear == Q -> front)//if(QueueEmpty(*Q))
        return ERROR;
    *e = Q -> base[Q -> front];
    Q -> front = ( Q -> front + 1) % QUEUE_SIZE;
    return OK;
}
void QueueTraverse(SqQueue Q)
{
    while(Q.front != Q.rear)
	{
        printf("%d%c",Q.base[Q.front],Q.front == Q.rear - 1? '\n' : ' ');
		Q.front = (Q.front + 1) % QUEUE_SIZE;
	}
}
int main()
{
    SqQueue Q;
    int rt;
    int value;
    InitQueue(&Q);

    if(QueueEmpty(Q)) puts("The Queue is empty!!!");
    else puts("The Queue is not empty!!!");

    EnQueue(&Q,1);
    EnQueue(&Q,2);
    EnQueue(&Q,3);
    EnQueue(&Q,4);

    QueueTraverse(Q);

    int len = QueueLength(Q);
    printf("The Queue's length is %d\n", len);

    rt = GetHead(Q, &value);
    if(rt) printf("%d is the Head elem.\n", value);
    else puts("The Queue is nothing.");

    DeQueue(&Q, &value);
    printf("%d is DeQueued\n", value);

    DeQueue(&Q, &value);
    printf("%d is DeQueued\n", value);

    while(!QueueEmpty(Q))
    {
        GetHead(Q, &value);
        printf("%d ", value);
        DeQueue(&Q, &value);
    }
    puts("");
    ClearQueue(&Q);

    rt = GetHead(Q, &value);
    if(rt) printf("%d is the Head elem.\n", value);
    else puts("The Queue is nothing.");

    QueueTraverse(Q);
    DestroyQueue(&Q);

    return 0;
}
