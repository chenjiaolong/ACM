// nsu2302
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 1e6;

char Parentheses[maxn];
char Stack[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%s", Parentheses);
        int len = strlen(Parentheses);
        int cur  = 0;
        bool flag = true;
        for(int i = 0; i < len; i ++)
        {
            if(Parentheses[i] == '(' || Parentheses[i] == '[') Stack[cur ++] = Parentheses[i];
            else if(Parentheses[i] == ')')
            {
                if(cur == 0 || Stack[--cur] != '(')
                {
                    flag = false;
                    break;
                }

            }
            else
            {
                if(cur == 0 || Stack[--cur] != '[')
                {
                    flag = false;
                    break;
                }
            }
        }
        if(!flag || cur) puts("No");
        else puts("Yes");
    }
    return 0;
}
