#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>

#define STACK_SIZE 1000
#define LISTINCREMENT 10
#define TRUE 1
#define FLASE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int Status;
typedef int OperandType;
typedef char OperatorType;

typedef struct Operand
{
    int num[STACK_SIZE];
    int top;
} OPND;
typedef struct Operator
{
    char op[STACK_SIZE];
    int top;
} OPTR;
OPND Opnd;
OPTR Optr;
int value=0;
OperandType GetTop_Opnd(OPND Opnd)
{
    //if(Opnd.top==-1)return 0;
    return Opnd.num[Opnd.top];
}
Status Push_Opnd(OPND *Opnd,char ch)
{
    if(Opnd->top+1==STACK_SIZE)
        return ERROR;
    if(ch!='#')
        value=10*value+ch-'0';
    else
    {
        Opnd->num[++Opnd->top]=value;
        value=0;
    }
    return OK;
}
Status Pop_Opnd(OPND *Opnd,int *c)
{
    if(Opnd->top==-1)
        return ERROR;
    *c=Opnd->num[Opnd->top--];
    return OK;
}
int GetLevel(char op)
{
    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    return 0;
}
OperatorType Precede(char theta,char c)
{
    if(theta=='('&&c==')'||theta=='#'&&c=='#')
        return '=';
    if(GetLevel(theta)>=GetLevel(c))
        return '>';
    else
        return '<';
}
Status Operate(int a,char theta,int b,int *res)
{
    switch(theta)
    {
    case '+':
        *res=a+b;
        return OK;
    case '-':
        *res=a-b;
        return OK;
    case '*':
        *res=a*b;
        return OK;
    case '/':
        if(b==0)
        {
            printf("除数不能为零！！！\n");
            return ERROR;
        }
        *res=a/b;
        return OK;
    }
}
OperandType EvaluateExpression()
{
    Optr.top=-1;
    Optr.op[++Optr.top]='#';
    Opnd.top=-1;
    char ch;
    cin>>ch;
    char theta,x;
    int a,b,res;
    int isnum=0;
    while(ch!='#'||Optr.op[Optr.top]!='#')
    {
        if(ch>='0'&&ch<='9')
        {
            Push_Opnd(&Opnd,ch);
            cin>>ch;
            isnum=1;
            continue;
        }
        if(isnum)
        {
            isnum=0;
            Push_Opnd(&Opnd,'#');
        }
        switch(Precede(Optr.op[Optr.top],ch))
        {
        case '<':
            Optr.op[++Optr.top]=ch;
            cin>>ch;
            break;
        case '>':
            theta=Optr.op[Optr.top--];
            Pop_Opnd(&Opnd,&b);
            Pop_Opnd(&Opnd,&a);
            if(Operate(a,theta,b,&res))
                Push_Opnd(&Opnd,res);
            else
                return 0;
            break;
        case '=':
            x=Optr.op[Optr.top--];
            cin>>ch;
            break;
        }
    }
    return GetTop_Opnd(Opnd);
}
int main()
{
    printf("请输入表达式：\n");
    if(EvaluateExpression())
        printf("%d\n",EvaluateExpression());
    return 0;
}

//#include<iostream>
//#include<cstdio>
//#define MaxLen 100//存储空间
//
//using namespace std;
//
//int tran(char str[], char expr[])//将中缀表达式转换成后缀表达式
////str原来表达式，expr后缀表达式
//{
//    int st[100];   //转化过程使用的过度栈
//    char ch;
//    int i=0,exindex=0,stindex=-1;  //i是str下标，exindex是expr下标，stindex是st下标
//    //如果第一个是'-',将虚设的前置0先入操作栈
//    if(str[0]=='-')
//    {
//        expr[exindex++]='0';
//        expr[exindex++]='#';
//    }
//    while((ch=str[i++])!='\0')
//    {
//
//        if(ch>='0' && ch<='9')   //判断是数字
//        {
//            expr[exindex]=ch;   //压栈
//            exindex++;   //栈顶指针上移
//            while((ch=str[i++])!='\0' && ch>='0' && ch<='9')//其它位依次入栈
//            {
//                expr[exindex]=ch;
//                exindex++;
//            }
//            i--;//str原算术表达式栈向下遍历
//            expr[exindex]='#';//以特殊字符“#”表示结束
//            exindex++;
//        }
//        //如果是'(''-',先将虚设的前置0入操作栈
//        else if(ch=='('&&str[i]=='-')
//        {
//            st[++stindex]=ch;
//            expr[exindex++]='0';
//            expr[exindex++]='#';
//        }
//        else if(ch=='(')//判断为左括号
//        {
//            stindex++;
//            st[stindex]=ch;
//        }
//        else if(ch==')')    //判断为右括号
//        {
//            while (st[stindex]!='(')
//            {
//                expr[exindex]=st[stindex];
//                stindex--;   //依次弹出
//                exindex++;
//            }
//            stindex--;//'('出栈
//        }
//        else if(ch=='+' || ch=='-')//判断为加减号
//        {
//            while(stindex>=0 && st[stindex]!='(')
//            {
//                expr[exindex]=st[stindex];
//                stindex--;
//                exindex++;
//            }
//            stindex++;
//            st[stindex]=ch;
//        }
//        else if (ch=='*' || ch=='/')//判断为乘除号
//        {
//            while(st[stindex]=='*' || st[stindex]=='/')
//            {
//                expr[exindex]=st[stindex];
//                stindex--;
//                exindex++;
//            }
//            stindex++;
//            st[stindex]=ch;
//        }
//    }
//    while (stindex>=0)//将栈中所有运算符依次弹出存入expr栈中
//    {
//        expr[exindex]=st[stindex];
//        exindex++;
//        stindex--;
//    }
//    expr[exindex]='\0';
//    return 1;
//}
//int compvalue(char expr[],int *n)
//{
//    int st[100],d; //st为数栈
//    char ch;
//    int exindex=0,stindex=-1;  //exindex是expr下标，stindex是st的下标
//    while((ch=expr[exindex++])!='\0')
//    {
//        if(ch>='0'&&ch<='9')//将数字字符转换成数字
//        {
//            d=0;
//            do
//            {
//                d=10*d+ch-'0';
//            }
//            while((ch=expr[exindex++])!='#');
//            stindex++;
//            st[stindex]=d;//数字进栈
//        }
//        else   //运算符操作
//        {
//            switch(ch)
//            {
//            case'+':
//                st[stindex-1]=st[stindex-1]+st[stindex];
//                break;
//            case'-':
//                st[stindex-1]=st[stindex-1]-st[stindex];
//                break;
//            case'*':
//                st[stindex-1]=st[stindex-1]*st[stindex];
//                break;
//            case'/':
//                if(st[stindex]!=0)
//                {
//                    st[stindex-1]=st[stindex-1]/st[stindex];
//                }
//                else return 0;//除0错误!
//                break;
//            }
//            stindex--;
//        }
//    }
//    *n=st[stindex];
//    return 1;
//}
//int main()
//{
//    char str[100];   //存储原来算术表达式
//    char expr[100];   //存储转换成的后缀表达式
//    int n;
//    cout<<"输入算术表达式:"<<endl;
//    cin>>str;
//    if(tran(str,expr)==0)
//        cout<<"原算术表达式不正确!"<<endl;
//    else
//    {
//        cout<<"转换成后缀表达式输出:"<<endl<<expr<<endl;
//        if(compvalue(expr,&n)==1)
//            cout<<"表达式求值:"<<endl<<n<<endl;
//        else
//            cout<<"计算错误!"<<endl;
//    }
//    return 0;
//}
