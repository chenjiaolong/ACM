// GCD Table
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 505;

int temp[maxn * maxn] = {0};
map<int, int>array;
vector<int>ans;
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        //array.clear();
        ans.clear();
        for(int i = 0; i < n * n; i ++)
        {
            cin >> temp[i];
            array[temp[i]]++;
        }
        sort(temp, temp + n * n);
        for(int i = n * n - 1; i >= 0; i --)
        {
            if(array[temp[i]] == 0) continue;
            array[temp[i]] --;
            for(int j = 0; j < ans.size(); j ++)
            {
                int t = __gcd(temp[i], ans[j]);
                array[t] -= 2;
            }
            ans.push_back(temp[i]);
        }
        cout << ans[0];
        for(int i = 1; i < n; i ++)
            cout << " " <<ans[i];
        cout << endl;
    }
    return 0;
}


