#include<bits/stdc++.h>
using namespace std;
int n;
int matrix[10][10];
void IntToSeries(int i, int *s)
{
    //函数将序号化为移动的序列，也就是解的路径
    for(int k = 0, j = i; k < n; ++k)
    {
        s[k] = j % n;//i代表第i条路径
        j %= n;
    }
}
int MaxColumn(int *s)
{
    //函数返回在指定移动情况下的最大值
    int max = matrix[0][0];
    for(int i = 1; i < n; i++)//第一列的和
    max += matrix[i][s[i - 1]];
    // printf("%d\n",max);
    for(int i = 1; i < n; ++i)
    {
        int temp = matrix[0][i];
        for(int j = 1; j < n; ++j)//第i列的和
                temp += matrix[j][(s[j - 1] + i) % n];
        if(temp > max)
            max = temp;
        // printf("%d\n",temp);
    }
    return max;
}
int main()
{
    while(scanf("%d",&n),n + 1)
    {
        int s[1000];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d",&matrix[i][j]);
        IntToSeries(0,s);
        int ColMin = MaxColumn(s);
        // printf("%d\n",ColMin);
        for(int i = 1; i < n; ++i)//循环将遍历所有异动情况
        {
            IntToSeries(i,s);
            int temp = MaxColumn(s);

            if(temp < ColMin)
                ColMin = temp;
        }
        printf("%d\n",ColMin);
    }
    return 0;
}
