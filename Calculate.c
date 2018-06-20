/**********************************************
算术表达式求值的算符优先级算法
利用栈来实现括号匹配和表达式求值
算法的详细说明，请查看清华大学出版社《数据结构》，
严蔚敏&吴伟民著，3.3节
 ***********************************************/
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

//存储空间初始分配量
#define STACK_INIT_SIZE 100//存储空间分配增量
#define STACKINCREMENT 10
#define OK 0
#define ERROR 127

//定义一个顺序栈
typedef struct
{
    int*base;//在栈构造之前和销毁之后，base的值为NULL
    int*top;//栈顶指针
    int stacksize;//当前已分配的存储空间,以元素为单位
} SqStack;
int InitStack(SqStack*S)//构造一个空栈
{
    S->base=(int*)malloc(STACK_INIT_SIZE*sizeof(SqStack));
    if(NULL==S->base)//内存分配失败
        return ERROR;
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE ;
    return OK ;
}
char GetTop(SqStack*S,char*element)//若栈不空，取栈顶元素,用element返回
{
    if(S->base==S->top)return ERROR ;
    *element=*(S->top-1);
    return*element;
}
int Push(SqStack*S,int element) //插入元素element为新的栈顶元素
{
    if((S->top-S->base)>S->stacksize)//栈满，追加空间
    {
        S->base=(int*)realloc(S->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SqStack));
        if(NULL==S->base)return ERROR ;
        S->top=S->base+S->stacksize ;
        S->stacksize+=STACKINCREMENT ;
    }
    *S->top++=element;
    return OK ;
}
int Pop(SqStack*S,int*element)//若栈不为空，则删除栈顶元素，用element返回其值
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
//判断字符c是否在集合OP中
int InOP(char c,char OP[7])
{
    int i;
    for(i=0; i<7; i++)
        if(c==OP[i])
            return OK ;//判断运算符的优先级
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
//简单计算
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
算术表达式求值的算符优先级算法，
设OPTR和OPND分别为运算符栈和运算数栈 OP为运算符集合
**********************************************/
int main()
{
    SqStack OPTR,OPND ;
    int element=0 ;
    char OPTR_element ;
    int leftNum,rightNum ;
    char input ;//获取输入
    char OP[7]= {'+','-','*','/','(',')','\n'};
    InitStack(&OPTR);
    Push(&OPTR,'\n');
    InitStack(&OPND);
    printf("请输入表达式\n");
    input=getchar();
    while('\n'!=input||'\n'!=GetTop(&OPTR,&OPTR_element))
    {
        int temp=0 ;
        if(isdigit(input))//如果是数字
        {
            ungetc(input,stdin);//返回给输入流
            scanf("%d",&temp);
            Push(&OPND,temp);//数字就进OPND栈
            input=getchar();
            continue ;
        }
        if(OK==InOP(input,OP))
        {
            GetTop(&OPTR,&OPTR_element);
            {
                switch(Compare(OPTR_element,input))
                {
                case '<' ://栈顶元素优先级低
                    Push(&OPTR,input);//运算符进OPTR栈
                    input=getchar();
                    break ;
                case '=' ://脱括号
                    PopOPTR(&OPTR,&OPTR_element);
                    input=getchar();
                    break ;
                case '>' ://退栈，并将运算结果入栈
                    PopOPTR(&OPTR,&OPTR_element);
                    Pop(&OPND,&rightNum);
                    Pop(&OPND,&leftNum);
                    Push(&OPND,Calculate(leftNum,OPTR_element,rightNum));
                    break ;
                default :
                    printf("表达式括号不匹配\n");

                }//switch
            }
        }//if
        else
        {
            printf("表达式内有未知字符,即将退出\n");
            return ERROR ;
        }
    }//while
    int value ;
    Pop(&OPND,&value);
    printf("结果 = %d\n",value);
    return OK ;
}//end
