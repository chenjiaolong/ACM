#include<string.h>
#include<stdio.h>
int judge(char *n)
{
    int len=strlen(n);
    for(int i=0; i<len; i++)
        if(n[i]!='0')
            return 1;
    return 0;
}
//�ж����������ǲ��Ƕ��ǣ�����������ǣ��Ļ��ʹ����㴦�����˶԰ɡ���Ȼ�����Ϳ��Խ�����
void ff(char* n)
{
    if(judge(n))
    {
        int temp=0;//���¾��Ǹ߾��ȳ��Ե;��ȣ���һ���򵥵Ĺ���
        int len=strlen(n);
        int res=(n[len-1]-'0') % 2;//���ǿ��Է���һ�������Զ��������������һλ�������ġ���Ҳ���Ǹ�λ�������ġ������Ӧ��û�����
        for(int i=0; i<len; i++)//����ط��Ͳ�ת�������˹�����ֱ�������λ�����ĸ�λ
        {
            temp=temp*10+n[i]-'0';//����������ģ��һ�³�����ע���������ַ�������֮���ڽ��б任��������ʱ��Ҫ��������
            n[i]=temp/2+'0';
            temp=temp%2;
        }
        ff(n);//�����������ú����ݹ���Ϊջ�������ͻ��ر�����
        printf("%d",res);
    }
}
int main()
{
    char n[10000];
    while(gets(n)!= NULL)
    {
        int len=strlen(n);
        ff(n);
        printf("\n");
    }
    return 0;
}

