#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 10000
struct StackOp//存取运算符的栈
{
    char op[MaxSize];
    int top;
} stackop;
struct StackNum//存取的操作数的栈
{
    double num[MaxSize];
    int top;
} stacknum;
int GetLevel(char op)//得到运算符的优先等级
{
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op == '^') return 3;
    return 0;
}
double Add(double a,double b)//加法运算
{
    return a+b;
}
double Sub(double a,double b)//减法运算
{
    return a-b;
}
double Multi(double a,double b)//乘法运算
{
    return a*b;
}
int Div(double a,double b,double *result)//除法运算
{
    if(b==0)
        return 0;
    *result=a/b;
    return 1;
}
double Pow(double a, double b)//乘法运算
{
    return powf(a, b);
}
int Calculate(double a,double b,char op,double *result)
//用于对两个数进行运算
{
    switch(op)
    {
    case '+':
        *result=Add(a,b);
        return 1;
    case '-':
        *result=Sub(a,b);
        return 1;
    case '*':
        *result=Multi(a,b);
        return 1;
    case '/':
        return Div(a,b,result);
    case '^':
        *result = Pow(a, b);
        return 1;
    default:
        return 0;
    }
}
void GetRpn(char *str,char *rpn)//得到逆波兰表达式（后缀表达式）
{
    int len=strlen(str),cnt=0,i;
    int isnum=0;//标记是否是一个数
    stackop.top=-1;
    //如果末尾有'='先将'='去掉
    if(str[len-1]=='=') len--;
    //如果第一个是'-',将虚设的前置0先入操作栈
    if(str[0]=='-')
    {
        rpn[cnt++]='0';
        rpn[cnt++]='#';
    }
    for(i=0; i<len; i++)
    {
        if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
        {
            rpn[cnt++]=str[i];
            isnum=1;
            continue;
        }
        if(isnum)
        {
            rpn[cnt++]='#';
            isnum=0;
        }
        //如果是'(''-',先将虚设的前置0入操作栈
        if(str[i]=='('&&str[i+1]=='-')
        {
            rpn[cnt++]='0';
            rpn[cnt++]='#';
        }

        //'('直接入运算符的栈
        if(str[i]=='(')
            stackop.op[++stackop.top]=str[i];
        //遇到')'运算符依次出栈，直到遇到与之匹配的'('
        else if(str[i]==')')
        {
            while(stackop.op[stackop.top]!='(')
            {
                rpn[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
            //'('出栈
            stackop.top--;
        }
        //运算符的栈不为空，且现有运算符的优先级<=栈顶运算符打的优先级，栈顶运算符出栈
        else if(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
        {
            while(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
            {
                rpn[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
            //将当前运算符入运算符的栈
            stackop.op[++stackop.top]=str[i];
        }
        //如果当前运算符的优先级>栈顶运算符打的优先级,直接入运算符的栈
        else
            stackop.op[++stackop.top]=str[i];
    }
    //最后一个如果是数，也应该做分割做标记
    if(isnum) rpn[cnt++]='#';
    //操作数已经取完，如果运算符的栈不为空，运算符应该依次出栈
    while(stackop.top!=-1)
    {
        rpn[cnt++]=stackop.op[stackop.top];
        stackop.top--;
    }
    rpn[cnt]='\0';
}
int GetAns(char *rpn,double *result)
{
    int len=strlen(rpn),i;
    double fnum;
    int num,cnt;
    stacknum.top=-1;
    for(i=0; i<len; i++)
    {
        if(rpn[i]>='0'&&rpn[i]<='9')
        {
            num=cnt=0;
            fnum=0;
            //整数部分
            while(rpn[i]!='#'&&rpn[i]!='.')
            {
                num=num*10+rpn[i]-'0';
                i++;
            }
            //小数部分
            if(rpn[i]=='.')
            {
                i++;
                while(rpn[i]!='#')
                {
                    fnum=fnum+(rpn[i]-'0')*1.0/powl(10,++cnt);
                    i++;
                }
            }
            fnum+=num;
            stacknum.num[++stacknum.top]=fnum;
        }
        //如果是运算符，取出两个数进行运算
        else
        {
            double a,b,c;
            b=stacknum.num[stacknum.top];
            stacknum.top--;
            a=stacknum.num[stacknum.top];
            stacknum.top--;
            if(Calculate(a,b,rpn[i],&c)==0)
            {
                //计算失败
                printf("除数不能为零！！！\n");
                return 0;
            }
            else
                stacknum.num[++stacknum.top]=c;
        }
    }
    *result=stacknum.num[stacknum.top];
    return 1;
}
int main()
{
    char str[MaxSize],rpn[MaxSize];
    double result;
    while(gets(str)!=NULL)
    {

        GetRpn(str,rpn);
        printf("逆波兰表达式为：");
        printf("%s\n",rpn);
        if(GetAns(rpn,&result))
            printf("%.2f\n",result);
    }
    return 0;
}
