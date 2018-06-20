// hdu 2609 How many
/*最小表示法
 *用最小表示法求字符串S的最小字典序
 返回字典序最小的串的首字母位置
 */
#include<set>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

// MinimumRepresentation
int MCP(string s, int len)
{
    int i = 0, j = 1, k = 0;
    while(i < len && j < len && k < len)
    {
        int x = (i + k) % len;
        int y = (j + k) % len;
        if(s[x] == s[y]) k ++;
        else
        {
            if(s[x] < s[y]) i += k + 1;
            else j += k + 1;
            k = 0;
        }
        if(i == j) j = i + 1;
    }
    return i;
}

int main()
{
    int n;
    int mini;
    string str, s;
    set<string>oz;
    while(cin >> n)
    {
        while(n --)
        {
            cin >> str;
            int len = str.length();
            mini = MCP(str, len);
            s = str.substr(mini, len - mini) + str.substr(0, mini);
            oz.insert(s);
        }
        printf("%d\n", oz.size());
        oz.clear();
    }
    return 0;
}

