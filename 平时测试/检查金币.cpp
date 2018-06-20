#include<bits/stdc++.h>
int main()
{
    int W;
    while(~scanf("%d",&W))
    {
        int array[15];
        for(int i = 0; i < 10; i++)
            array[i] = 9;
        W -= 265716;
        for(int i = 0; i < 10; i++,W/=3)
          array[i] += W %3;
        for(int i = 0; i < 10; i++)
        printf("%d%c",array[i],i==9?'\n':' ');
    }
    return 0;
}
