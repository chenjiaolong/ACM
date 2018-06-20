#include<bits/stdc++.h>
using namespace std;
int n;
int matrix[10][10];
void IntToSeries(int i, int *s)
{
    //��������Ż�Ϊ�ƶ������У�Ҳ���ǽ��·��
    for(int k = 0, j = i; k < n; ++k)
    {
        s[k] = j % n;//i�����i��·��
        j %= n;
    }
}
int MaxColumn(int *s)
{
    //����������ָ���ƶ�����µ����ֵ
    int max = matrix[0][0];
    for(int i = 1; i < n; i++)//��һ�еĺ�
    max += matrix[i][s[i - 1]];
    // printf("%d\n",max);
    for(int i = 1; i < n; ++i)
    {
        int temp = matrix[0][i];
        for(int j = 1; j < n; ++j)//��i�еĺ�
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
        for(int i = 1; i < n; ++i)//ѭ�������������춯���
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
