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
//判断数组里面是不是都是０　　如果都是０的话就代表你处理完了对吧　　然后程序就可以结束了
void ff(char* n)
{
    if(judge(n))
    {
        int temp=0;//以下就是高精度除以低精度２的一个简单的过程
        int len=strlen(n);
        int res=(n[len-1]-'0') % 2;//我们可以发现一个数除以二的余数是由最后一位数决定的　　也就是个位数决定的　　这个应该没问题吧
        for(int i=0; i<len; i++)//这个地方就不转置数组了哈　　直接数组低位存数的高位
        {
            temp=temp*10+n[i]-'0';//接下来就是模拟一下除法　注意这里是字符和整形之间在进行变换　所以有时候要＋‘０’
            n[i]=temp/2+'0';
            temp=temp%2;
        }
        ff(n);//这里我们利用函数递归作为栈　这样就会特别ｅａｓｙ
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

