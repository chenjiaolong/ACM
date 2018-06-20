/**********************************************
�������ʽ��ֵ��������ȼ��㷨
����ջ��ʵ������ƥ��ͱ��ʽ��ֵ
�㷨����ϸ˵������鿴�廪��ѧ�����硶���ݽṹ����
��ε��&��ΰ������3.3��
 ***********************************************/
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

//�洢�ռ��ʼ������
#define STACK_INIT_SIZE 100//�洢�ռ��������
#define STACKINCREMENT 10
#define OK 0
#define ERROR 127

//����һ��˳��ջ
typedef struct
{
    int*base;//��ջ����֮ǰ������֮��base��ֵΪNULL
    int*top;//ջ��ָ��
    int stacksize;//��ǰ�ѷ���Ĵ洢�ռ�,��Ԫ��Ϊ��λ
} SqStack;
int InitStack(SqStack*S)//����һ����ջ
{
    S->base=(int*)malloc(STACK_INIT_SIZE*sizeof(SqStack));
    if(NULL==S->base)//�ڴ����ʧ��
        return ERROR;
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE ;
    return OK ;
}
char GetTop(SqStack*S,char*element)//��ջ���գ�ȡջ��Ԫ��,��element����
{
    if(S->base==S->top)return ERROR ;
    *element=*(S->top-1);
    return*element;
}
int Push(SqStack*S,int element) //����Ԫ��elementΪ�µ�ջ��Ԫ��
{
    if((S->top-S->base)>S->stacksize)//ջ����׷�ӿռ�
    {
        S->base=(int*)realloc(S->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SqStack));
        if(NULL==S->base)return ERROR ;
        S->top=S->base+S->stacksize ;
        S->stacksize+=STACKINCREMENT ;
    }
    *S->top++=element;
    return OK ;
}
int Pop(SqStack*S,int*element)//��ջ��Ϊ�գ���ɾ��ջ��Ԫ�أ���element������ֵ
{
    if(S->top==S->base)return ERROR ;
    *element=*(--S->top);
    return OK ;
}
int PopOPTR(SqStack*S,char*element)
{
    if(S->top==S->base)return ERROR ;
    *element=*(--S->top);
    return OK ;
}
//�ж��ַ�c�Ƿ��ڼ���OP��
int InOP(char c,char OP[7])
{
    int i;
    for(i=0; i<7; i++)
        if(c==OP[i])
            return OK ;//�ж�����������ȼ�
    return ERROR ;
}
int Compare(int a,int b)
{
    if('+'==a)
    {
        switch(b)
        {
        case '+' :
            return '>' ;
        case '-' :
            return '>' ;
        case '*' :
            return '<' ;
        case '/' :
            return '<' ;
        case '(' :
            return '<' ;
        case ')' :
            return '>' ;
        case '\n' :
            return '>' ;
        }
    }
    if('-'==a)
    {
        switch(b)
        {
        case '+' :
            return '>' ;
        case '-' :
            return '>' ;
        case '*' :
            return '<' ;
        case '/' :
            return '<' ;
        case '(' :
            return '<' ;
        case ')' :
            return '>' ;
        case '\n' :
            return '>' ;
        }
    }
    if('*'==a)
    {
        switch(b)
        {
        case '+' :
            return '>' ;
        case '-' :
            return '>' ;
        case '*' :
            return '>' ;
        case '/' :
            return '>' ;
        case '(' :
            return '<' ;
        case ')' :
            return '>' ;
        case '\n' :
            return '>' ;
        }
    }
    if('/'==a)
    {
        switch(b)
        {
        case '+' :
            return '>' ;
        case '-' :
            return '>' ;
        case '*' :
            return '>' ;
        case '/' :
            return '>' ;
        case '(' :
            return '<' ;
        case ')' :
            return '>' ;
        case '\n' :
            return '>' ;
        }
    }
    if('('==a)
    {
        switch(b)
        {
        case '+' :
            return '<' ;
        case '-' :
            return '<' ;
        case '*' :
            return '<' ;
        case '/' :
            return '<' ;
        case '(' :
            return '<' ;
        case ')' :
            return '=' ;
        }
    }
    if(')'==a)
    {
        switch(b)
        {
        case '+' :
            return '>' ;
        case '-' :
            return '>' ;
        case '*' :
            return '>' ;
        case '/' :
            return '>' ;
        case ')' :
            return '>' ;
        case '\n' :
            return '>' ;
        }
    }
    if('\n'==a)
    {
        switch(b)
        {
        case '+' :
            return '<' ;
        case '-' :
            return '<' ;
        case '*' :
            return '<' ;
        case '/' :
            return '<' ;
        case '(' :
            return '<' ;
        case '\n' :
            return '=' ;
        }
    }
    return ERROR ;
}
//�򵥼���
int Calculate(int left,char oper,int right)
{
    int result=0 ;
    switch(oper)
    {
    case '+' :
        result=left+right ;
        break ;
    case '-' :
        result=left-right ;
        break ;
    case '*' :
        result=left*right ;
        break ;
    case '/' :
        result=left/right ;
        break ;
    }
    return result ;
}
/**********************************************
�������ʽ��ֵ��������ȼ��㷨��
��OPTR��OPND�ֱ�Ϊ�����ջ��������ջ OPΪ���������
**********************************************/
int main()
{
    SqStack OPTR,OPND ;
    int element=0 ;
    char OPTR_element ;
    int leftNum,rightNum ;
    char input ;//��ȡ����
    char OP[7]= {'+','-','*','/','(',')','\n'};
    InitStack(&OPTR);
    Push(&OPTR,'\n');
    InitStack(&OPND);
    printf("��������ʽ\n");
    input=getchar();
    while('\n'!=input||'\n'!=GetTop(&OPTR,&OPTR_element))
    {
        int temp=0 ;
        if(isdigit(input))//���������
        {
            ungetc(input,stdin);//���ظ�������
            scanf("%d",&temp);
            Push(&OPND,temp);//���־ͽ�OPNDջ
            input=getchar();
            continue ;
        }
        if(OK==InOP(input,OP))
        {
            GetTop(&OPTR,&OPTR_element);
            {
                switch(Compare(OPTR_element,input))
                {
                case '<' ://ջ��Ԫ�����ȼ���
                    Push(&OPTR,input);//�������OPTRջ
                    input=getchar();
                    break ;
                case '=' ://������
                    PopOPTR(&OPTR,&OPTR_element);
                    input=getchar();
                    break ;
                case '>' ://��ջ��������������ջ
                    PopOPTR(&OPTR,&OPTR_element);
                    Pop(&OPND,&rightNum);
                    Pop(&OPND,&leftNum);
                    Push(&OPND,Calculate(leftNum,OPTR_element,rightNum));
                    break ;
                default :
                    printf("���ʽ���Ų�ƥ��\n");

                }//switch
            }
        }//if
        else
        {
            printf("���ʽ����δ֪�ַ�,�����˳�\n");
            return ERROR ;
        }
    }//while
    int value ;
    Pop(&OPND,&value);
    printf("��� = %d\n",value);
    return OK ;
}//end
