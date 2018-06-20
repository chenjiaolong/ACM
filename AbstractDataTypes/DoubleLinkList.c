#include<stdio.h>
#include<stdlib.h>
typedef struct DNode
{
	int data;
	struct DNode *prior,*next;
}DLNode;
DLNode *dCreate()
{
	DLNode *pnew,*head,*pend;
	int n,i;
	head = (DLNode *)malloc(sizeof(DLNode));
	head -> next = head -> prior = head;
	pend = head;
	scanf("%d",&n);
	for (i = 0; i < n; i ++)
	{
		pnew = (DLNode *)malloc(sizeof(DLNode));
		scanf("%d",&pnew -> data);
		pnew -> prior = pend;
		pend -> next = pnew;
		pend = pnew;
	}
	pend -> next = head;
	head -> prior = pend;
	return head;
}
void print(DLNode *head)
{
	DLNode *p;

	if (head -> next == head)
		return;
	p = head -> prior;
	while(p != head)
	{
		printf("%-4d",p -> data);
		p = p -> prior;
	}
	printf("\n");
}
void Ddelete(DLNode *head, int x)
{
	DLNode *p = head -> next,*q;
	while (p != head)
	{
		if (p -> data == x)
		{
			q = p;
			p = p -> next;
			q -> prior -> next = q -> next;
			q -> next -> prior = q -> prior;
			free(q);
		}
		else
			p = p -> next;
	}
}
void main()
{
	DLNode *head;
	head = dCreate();
	print(head);
	Ddelete(head, 5);
	print(head);
}
