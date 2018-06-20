// hdu 5007 Post Robot
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    char str[1000], ch;
//    int cnt = 0;
//    memset(str, '\0', sizeof(str));
//    while(! cin.eof())
//    {
//        ch = cin.get();
//        if(ch >= 32 && ch <= 127)
//        {
//            str[cnt ++] = ch;
//            continue;
//        }
//        // puts(str);
//        if(cnt == 0) continue;
//        str[cnt++] = '\0';
//        char ans[10];
//        for(int i = 0; i < cnt; i ++)
//        {
//            if(str[i] == 'A' && str[i + 4] == 'e')
//            {
//                memset(ans, '\0', sizeof(ans));
//                for(int j = i; j <= i + 4; j ++)
//                    ans[j - i] = str[j];
//                ans[5] = '\0';
//                if(strcmp(ans, "Apple") == 0)
//                    puts("MAI MAI MAI!");
//            }
//            if(str[i] == 'i' && str[i + 5] == 'e')
//            {
//                memset(ans, '\0', sizeof(ans));
//                for(int j = i; j <= i + 5; j ++)
//                    ans[j - i] = str[j];
//                if(strcmp(ans, "iPhone") == 0)
//                    puts("MAI MAI MAI!");
//            }
//            if(str[i] == 'i' && str[i + 3] == 'd')
//            {
//                memset(ans, '\0', sizeof(ans));
//                for(int j = i; j <= i + 3; j ++)
//                    ans[j - i] = str[j];
//                if(strcmp(ans, "iPod") == 0 || strcmp(ans, "iPad") == 0)
//                    puts("MAI MAI MAI!");
//            }
//            if(str[i] == 'S' && str[i + 3] == 'y')
//            {
//                memset(ans, '\0', sizeof(ans));
//                for(int j = i; j <= i + 3; j ++)
//                    ans[j - i] = str[j];
//                if(strcmp(ans, "Sony") == 0)
//                    puts("SONY DAFA IS GOOD!");
//            }
//        }
//        memset(str, '\0', sizeof(str));
//        cnt = 0;
//    }
//    return 0;
//}

// hdu 5011 Game
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        int temp, res = 0;
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%d", &temp);
//            res ^= temp;
//        }
//        if(res) puts("Win");
//        else puts("Lose");
//    }
//    return 0;
//}

// hdu5012 Dice
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
struct node
{
    int step;
    int status[10];
};
bool isOK(int *a, int *b)
{
    for(int i = 1; i <= 6; i ++)
        if(a[i] != b[i]) return false;
    return true;
}
int BFS(int *a, int *b)
{
    queue<node>q;
    node s;
    s.step = 0;
    for(int i = 1; i <= 6; i ++)
        s.status[i] = a[i];
    q.push(s);
    int temp;
    while(!q.empty())
    {
        node s = q.front();
        q.pop();
        if(s.step > 4) return -1;
        if(isOK(s.status, b)) return s.step;
        node e;
        for(int op = 1; op <= 4; op++)
        {
            if(op == 1)
            {
                e.status[1] = s.status[4];
                e.status[2] = s.status[3];
                e.status[3] = s.status[1];
                e.status[4] = s.status[2];
                e.status[5] = s.status[5];
                e.status[6] = s.status[6];
                e.step = s.step + 1;
                q.push(e);
            }
            else if(op == 2)
            {
                e.status[1] = s.status[3];
                e.status[2] = s.status[4];
                e.status[3] = s.status[2];
                e.status[4] = s.status[1];
                e.status[5] = s.status[5];
                e.status[6] = s.status[6];
                e.step = s.step + 1;
                q.push(e);
            }
            else if(op == 3)
            {
                e.status[1] = s.status[6];
                e.status[2] = s.status[5];
                e.status[3] = s.status[3];
                e.status[4] = s.status[4];
                e.status[5] = s.status[1];
                e.status[6] = s.status[2];
                e.step = s.step + 1;
                q.push(e);
            }
            else if(op == 4)
            {
                e.status[1] = s.status[5];
                e.status[2] = s.status[6];
                e.status[3] = s.status[3];
                e.status[4] = s.status[4];
                e.status[5] = s.status[2];
                e.status[6] = s.status[1];
                e.step = s.step + 1;
                q.push(e);
            }
        }
    }
    return -1;
}
int main()
{
    int a[10], b[10];
    while(scanf("%d", &a[1]) != EOF)
    {
        for(int i = 2; i <= 6; i ++) scanf("%d", &a[i]);
        for(int i = 1; i <= 6; i ++) scanf("%d", &b[i]);
        if(isOK(a, b)) puts("0");
        else
        {
            int res = BFS(a, b);
            printf("%d\n", res);
        }
    }
    return 0;
}

