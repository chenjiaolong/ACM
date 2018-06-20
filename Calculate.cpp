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
            printf("��������Ϊ�㣡����\n");
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
    printf("��������ʽ��\n");
    if(EvaluateExpression())
        printf("%d\n",EvaluateExpression());
    return 0;
}

//#include<iostream>
//#include<cstdio>
//#define MaxLen 100//�洢�ռ�
//
//using namespace std;
//
//int tran(char str[], char expr[])//����׺���ʽת���ɺ�׺���ʽ
////strԭ�����ʽ��expr��׺���ʽ
//{
//    int st[100];   //ת������ʹ�õĹ���ջ
//    char ch;
//    int i=0,exindex=0,stindex=-1;  //i��str�±꣬exindex��expr�±꣬stindex��st�±�
//    //�����һ����'-',�������ǰ��0�������ջ
//    if(str[0]=='-')
//    {
//        expr[exindex++]='0';
//        expr[exindex++]='#';
//    }
//    while((ch=str[i++])!='\0')
//    {
//
//        if(ch>='0' && ch<='9')   //�ж�������
//        {
//            expr[exindex]=ch;   //ѹջ
//            exindex++;   //ջ��ָ������
//            while((ch=str[i++])!='\0' && ch>='0' && ch<='9')//����λ������ջ
//            {
//                expr[exindex]=ch;
//                exindex++;
//            }
//            i--;//strԭ�������ʽջ���±���
//            expr[exindex]='#';//�������ַ���#����ʾ����
//            exindex++;
//        }
//        //�����'(''-',�Ƚ������ǰ��0�����ջ
//        else if(ch=='('&&str[i]=='-')
//        {
//            st[++stindex]=ch;
//            expr[exindex++]='0';
//            expr[exindex++]='#';
//        }
//        else if(ch=='(')//�ж�Ϊ������
//        {
//            stindex++;
//            st[stindex]=ch;
//        }
//        else if(ch==')')    //�ж�Ϊ������
//        {
//            while (st[stindex]!='(')
//            {
//                expr[exindex]=st[stindex];
//                stindex--;   //���ε���
//                exindex++;
//            }
//            stindex--;//'('��ջ
//        }
//        else if(ch=='+' || ch=='-')//�ж�Ϊ�Ӽ���
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
//        else if (ch=='*' || ch=='/')//�ж�Ϊ�˳���
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
//    while (stindex>=0)//��ջ��������������ε�������exprջ��
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
//    int st[100],d; //stΪ��ջ
//    char ch;
//    int exindex=0,stindex=-1;  //exindex��expr�±꣬stindex��st���±�
//    while((ch=expr[exindex++])!='\0')
//    {
//        if(ch>='0'&&ch<='9')//�������ַ�ת��������
//        {
//            d=0;
//            do
//            {
//                d=10*d+ch-'0';
//            }
//            while((ch=expr[exindex++])!='#');
//            stindex++;
//            st[stindex]=d;//���ֽ�ջ
//        }
//        else   //���������
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
//                else return 0;//��0����!
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
//    char str[100];   //�洢ԭ���������ʽ
//    char expr[100];   //�洢ת���ɵĺ�׺���ʽ
//    int n;
//    cout<<"�����������ʽ:"<<endl;
//    cin>>str;
//    if(tran(str,expr)==0)
//        cout<<"ԭ�������ʽ����ȷ!"<<endl;
//    else
//    {
//        cout<<"ת���ɺ�׺���ʽ���:"<<endl<<expr<<endl;
//        if(compvalue(expr,&n)==1)
//            cout<<"���ʽ��ֵ:"<<endl<<n<<endl;
//        else
//            cout<<"�������!"<<endl;
//    }
//    return 0;
//}
