#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 10000
struct StackOp//��ȡ�������ջ
{
    char op[MaxSize];
    int top;
} stackop;
struct StackNum//��ȡ�Ĳ�������ջ
{
    double num[MaxSize];
    int top;
} stacknum;
int GetLevel(char op)//�õ�����������ȵȼ�
{
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op == '^') return 3;
    return 0;
}
double Add(double a,double b)//�ӷ�����
{
    return a+b;
}
double Sub(double a,double b)//��������
{
    return a-b;
}
double Multi(double a,double b)//�˷�����
{
    return a*b;
}
int Div(double a,double b,double *result)//��������
{
    if(b==0)
        return 0;
    *result=a/b;
    return 1;
}
double Pow(double a, double b)//�˷�����
{
    return powf(a, b);
}
int Calculate(double a,double b,char op,double *result)
//���ڶ���������������
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
void GetRpn(char *str,char *rpn)//�õ��沨�����ʽ����׺���ʽ��
{
    int len=strlen(str),cnt=0,i;
    int isnum=0;//����Ƿ���һ����
    stackop.top=-1;
    //���ĩβ��'='�Ƚ�'='ȥ��
    if(str[len-1]=='=') len--;
    //�����һ����'-',�������ǰ��0�������ջ
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
        //�����'(''-',�Ƚ������ǰ��0�����ջ
        if(str[i]=='('&&str[i+1]=='-')
        {
            rpn[cnt++]='0';
            rpn[cnt++]='#';
        }

        //'('ֱ�����������ջ
        if(str[i]=='(')
            stackop.op[++stackop.top]=str[i];
        //����')'��������γ�ջ��ֱ��������֮ƥ���'('
        else if(str[i]==')')
        {
            while(stackop.op[stackop.top]!='(')
            {
                rpn[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
            //'('��ջ
            stackop.top--;
        }
        //�������ջ��Ϊ�գ�����������������ȼ�<=ջ�������������ȼ���ջ���������ջ
        else if(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
        {
            while(stackop.top!=-1&&GetLevel(str[i])<=GetLevel(stackop.op[stackop.top]))
            {
                rpn[cnt++]=stackop.op[stackop.top];
                stackop.top--;
            }
            //����ǰ��������������ջ
            stackop.op[++stackop.top]=str[i];
        }
        //�����ǰ����������ȼ�>ջ�������������ȼ�,ֱ�����������ջ
        else
            stackop.op[++stackop.top]=str[i];
    }
    //���һ�����������ҲӦ�����ָ������
    if(isnum) rpn[cnt++]='#';
    //�������Ѿ�ȡ�꣬����������ջ��Ϊ�գ������Ӧ�����γ�ջ
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
            //��������
            while(rpn[i]!='#'&&rpn[i]!='.')
            {
                num=num*10+rpn[i]-'0';
                i++;
            }
            //С������
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
        //������������ȡ����������������
        else
        {
            double a,b,c;
            b=stacknum.num[stacknum.top];
            stacknum.top--;
            a=stacknum.num[stacknum.top];
            stacknum.top--;
            if(Calculate(a,b,rpn[i],&c)==0)
            {
                //����ʧ��
                printf("��������Ϊ�㣡����\n");
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
        printf("�沨�����ʽΪ��");
        printf("%s\n",rpn);
        if(GetAns(rpn,&result))
            printf("%.2f\n",result);
    }
    return 0;
}
