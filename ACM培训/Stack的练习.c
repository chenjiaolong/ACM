#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 1000
typedef struct
{
    int *data;
    int top;
} SqStack;
int InitStack(SqStack *S)
{
    S->data=(int*)malloc(sizeof(int)*MaxSize);
    if(!S->data)
        return 0;
    S->top=-1;
    return 1;
}
void DestroyStack(SqStack *S)
{
    free(S->data);
    S->data=NULL;
    S->top=-1;
}
void ClearStack(SqStack *S)
{
    S->top=-1;
}
int StackEmpty(SqStack S)
{
    // return S.top==-1;
    if(S.top==-1)
        return 1;
    return 0;
}
int StackLength(SqStack S)
{
    return S.top+1;
}
int GetTop(SqStack S)
{
    return S.data[S.top];
}
int Push(SqStack *S,int value)
{
    if(S->top+1==MaxSize)
        return 0;
    S->data[++S->top]=value;
    return 1;
}
int Pop(SqStack *S)
{
    if(StackEmpty(*S))
        return 0;
    S->top--;
    return 1;
}
void StackTraverse(SqStack S)
{
    int i;
    for(i=S.top; i>=0; i--)
        printf("%d",S.data[i]);
    printf("\n");
}
/*int main()
{
    SqStack S;
    int n;
    InitStack(&S);
    while(scanf("%d",&n)!=EOF)
    {
        ClearStack(&S);
        if(n==0)
           break;
        while(n)
        {
            Push(&S,n%2);
            n=n/2;
        }
        StackTraverse(S);
        while(StackEmpty(S)==0)//while(!StackEmpty(S))
        {
            printf("%d",GetTop(S));
            Pop(&S);
        }
        printf("\n");

    }
    return 0;
}*/
int main()
{
    char str[MaxSize],num[MaxSize];
    int i,len,res,high;
    SqStack S;
    InitStack(&S);
    while(scanf("%s",str)!=EOF)//while(gets(str)!=NULL)
    {
        ClearStack(&S);
        len=strlen(str);
        for(i=0; i<len; i++)
            num[i]=str[len-1-i];
        num[len]='\0';
        // printf("num %s\n",num);
        //res=0;
        high=len-1;
        while(1)
        {
            res=0;
            for(i=high; i>=0; i--)
            {
                res=res*10+num[i]-'0';
                num[i]=res/2+'0';
                res=res%2;
            }
            Push(&S,res);
            if(num[high]=='0')
                high--;
            if(high==-1)
                break;
        }
        StackTraverse(S);
        while(StackEmpty(S)==0)//while(!StackEmpty(S))
        {
            printf("%d",GetTop(S));
            Pop(&S);
        }
        printf("\n");
    }
    DestroyStack(&S);
    return 0;
}
