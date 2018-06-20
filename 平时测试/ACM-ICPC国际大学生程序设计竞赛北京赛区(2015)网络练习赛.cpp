// hihocoder 1090 Highways
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//struct node
//{
//    double X, Y, L;
//    int id;
//    bool operator <(const node &S) const
//    {
//        return X < S.X;
//    }
//}car[1010];
//
//double ans[1010];
//int N;
//
//double Solve(int cur, double term)
//{
//    if(cur >= N + 1 || term <= car[cur].X) return 0;
//    double s = car[cur].X, tt = 0;
//    int i;
//    for(i = cur + 1; i <= N; i ++)
//    {
//        if(car[cur].L > car[i].L)
//        {
//            if(term > car[i].Y)
//            {
//                tt = max(ans[car[i].id], tt + (car[i].Y - s) / car[cur].L);
//                s = car[i].Y;
//            }
//            else break;
//        }
//    }
//    double T = Solve(i, term);
//    tt = max(T, tt + (term - s) / car[cur].L);
//    return tt;
//}
//
//int main()
//{
//    while(scanf("%d", &N) != EOF)
//    {
//        for(int i = 1; i <= N; i ++)
//            scanf("%lf%lf%lf", &car[i].X, &car[i].Y, &car[i].L), car[i].id = i;
//        sort(car + 1, car + N + 1);
////        for(int i = 1; i <= N; i ++)
////            printf("%d %f %f %f\n", car[i].id, car[i].X, car[i].Y, car[i].L);
//        for(int i = N; i >= 1; i --)
//            ans[car[i].id] = Solve(i, car[i].Y);
//        for(int i = 1; i <= N; i ++)
//            printf("%.2f\n", ans[i]);
//
//    }
//    return 0;
//}

// hihocoder 1061 Beautiful String
#include<iostream>
#include <vector>
#include <string>

using namespace std;

bool isBeautifulString(string &str)
{
    if (str.empty()) return false;
    vector<int> count;
    string singleNum;
    char pre = str[0];
    int currCount = 1;
    for (int i = 1; i <= str.size(); i++)
    {
        if (i == str.size() || str[i] != pre)
        {
            singleNum.push_back(pre);
            count.push_back(currCount);
            currCount = 1;
            pre = str[i];
        }
        else currCount++;
    }
    int continusCount = 1;
    //char preChar = str[0];
    int preIndex = 0;
    for (int i = 1; i<singleNum.size(); i++)
    {
        if (singleNum[i] == singleNum[preIndex] + 1 && (count[i] == count[preIndex] || (continusCount == 2 && count[i] >= count[preIndex])||(continusCount == 1 && count[i] <= count[preIndex])))
        {
            continusCount++;
            if (continusCount >= 3) return true;
        }
        else
        {
            i -= continusCount-1;
            continusCount = 1;

        }
        preIndex = i;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        string str;
        cin>>str;
        if (isBeautifulString(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

