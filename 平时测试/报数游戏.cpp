#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

bool isOk(int n)
{
   if(n % 7 == 0) return true;
   while(n)
   {
       if(n % 10 == 7) return true;
       n /= 10;
   }
   return false;
}

int main()
{
   int n, m, k;
   while(scanf("%d%d%d", &n, &m, &k), n + m + k)
   {
       int cnt = 0;
       while(k)
       {
           for(int i = 1; i <= n; i ++)
           {
               cnt ++;
               if(i == m && isOk(cnt))
               {
                   k --;
                   if(k == 0) break;
               }
           }
           if(k == 0) break;
           for(int i = n - 1; i >= 2; i --)
           {
               cnt ++;
               if(i == m && isOk(cnt))
               {
                   k --;
                   if(k == 0) break;
               }
           }
       }
       printf("%d\n", cnt);
   }
   return 0;
}
