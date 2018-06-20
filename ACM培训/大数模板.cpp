#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//两个大数相加
string sum(string s1,string s2)
{
	if(s1.length()<s2.length())
	{
		string temp=s1;
		s1=s2;
		s2=temp;
	}
	int i,j;
	for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
	{
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}
//大数乘以整形数
string Multiply(string s,int x)  //大数乘以整形数
{
    reverse(s.begin(),s.end());
    int cmp=0;
    for(int i=0;i<s.size();i++)
    {
        cmp=(s[i]-'0')*x+cmp;
        s[i]=(cmp%10+'0');
        cmp/=10;
    }
    while(cmp)
    {
        s+=(cmp%10+'0');
        cmp/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
//大数除以整形数
string Except(string s,int x)  //大数除以整形数
{
    int cmp=0,ok=0;
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        cmp=(cmp*10+s[i]-'0');
        if(cmp>=x)
        {
            ok=1;
            ans+=(cmp/x+'0');
            cmp%=x;
        }
        else{
            if(ok==1)
                ans+='0';  //注意这里啊。才找出错误
        }
    }
    return ans;
}
//两个大数相乘
//思想就是模拟才乘法运算，一个大数乘以另一个大数的每一位然后相加就是结果了


string Mult(string s,int x)  //大数乘以整形数
{
    reverse(s.begin(),s.end());
    int cmp=0;
    for(int i=0;i<s.size();i++)
    {
        cmp=(s[i]-'0')*x+cmp;
        s[i]=(cmp%10+'0');
        cmp/=10;
    }
    while(cmp)
    {
        s+=(cmp%10+'0');
        cmp/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string Multfa(string x,string y)  //大数乘法
{
    string ans;
    for(int i=y.size()-1,j=0;i>=0;i--,j++)
    {
        string tmp=Mult(x,y[i]-'0');
        for(int k=0;k<j;k++)
            tmp+='0';
        ans=sum(ans,tmp);
    }
    return ans;
}
//浮点数的n次方
string Multiply(string s,long x)  //大数乘以整形数
{
    reverse(s.begin(),s.end());
    long cmp=0;
    for(int i=0; i<s.size(); i++)
    {
        cmp=(s[i]-'0')*x+cmp;
        s[i]=(cmp%10+'0');
        cmp/=10;
    }
    while(cmp)
    {
        s+=(cmp%10+'0');
        cmp/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string Remove_later(string s)   //删除一个字符串的后倒0
{
    int ok=1;
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]=='0'){
            s.erase(i);
        }
        else if(s[i]=='.')
        {
            s.erase(i);
            ok=0;
        }
        else
            ok=0;
        if(ok==0)
            break;
    }
    return s;
}
string factorial(string s,int n)   //浮点数的n次方
{
    if(n==0)
        return "1";
    string cmp="",count="";
    long x=0,point=0;
    for(int i=0; i<s.size(); i++)
        if(s[i]!='.')
        {
            cmp+=s[i];
            x=x*10+(s[i]-'0');
        }
        else
            point=s.size()-1-i;
    for(int i=1; i<n; i++)
    {
        cmp=Multiply(cmp,x);
    }
    int ans_point=cmp.size()-n*point;
    if(ans_point<0)
    {
        count+='.';
        for(int i=ans_point; i!=0; i++)
            count+='0';
    }
    string::iterator it=cmp.begin();
    if(ans_point>=0&&ans_point<cmp.size())
        cmp.insert(it+ans_point,'.');
    count+=(Remove_later(cmp));
    return count;
}
//字符串去除后导0函数，前导0可以先反转取后导

int main()
{

}
