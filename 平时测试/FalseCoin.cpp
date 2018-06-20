//#include<bits/stdc++.h>
//using namespace std;
//short Judge(int j,int *s,char c)
//{
//    //函数判断假设j号金币是假的与称量结果是否矛盾
//    //s是称量记录，其第一个元素是砝码的个数
//    //c 是称量记录
//    int m = s[0] << 1;
//    bool f = true;
//    for(int i = 1; i <= m && f; )
//        if(s[i] == j)
//            f = false;
//        else
//            ++i;
//    //判断本次称量有没有j号金币。
//    if(!f && c == '='|| f && c != '=')return 0;
//    //如果j号金币而天平失衡，或没有j号金币而天平不平衡，则与假设矛盾
//    return 1;
//}
//int main()
//{
//    int N,K;
//    while(scanf("%d%d",&N,&K) == 2)
//    {
//        int num[105][1010];
//        char s[105][5];//输入内容
//        for(int i = 0 ; i < K; ++i)
//        {
//            scanf("%d",&num[i][0]);
//            for(int j = 1; j <= 2 * num[i][0]; ++j)
//                scanf("%d",&num[i][j]);
//            scanf("%s",s[i]);
//        }
//        int no;
//        int t = 0,j;
//        for(int i = 1; i <= N; ++i)//暴力搜索所有可能
//        {
//            for(j = 0; j < K && Judge(i,num[j],s[j][0]); ++j);
//            printf("SSSSSS %d\n",Judge(i,num[j],s[j][0]));
//            //对所有的记录进行检测
//            if(j < K)
//                continue;
//            t++;
//            if(t > 1)
//                break;
//            no = i;
//        }//t保存嫌疑对象的个数
//        if(t - 1 )
//            printf("0\n");
//        else
//            printf("%d\n",no);
//    }
//    return 0;
//}

//#include<iostream>
//#include<memory.h>
//#include<vector>
//#include<set>
//using namespace std;
//struct formula
//{
//	set <int> left;
//	set <int> right;
//	char op;
//	int num;
//};
//int main()
//{
//	int n = 0, k = 0;
//	while (cin >> n >> k)
//	{
//		int answer = 0;
//		int coins[1001];
//		memset(coins, 0, sizeof(coins));
//		formula form[101];
//		for (int i = 0; i < k; i++)
//		{
//			int nn = 0, temp;
//			char op;
//			cin >> nn;
//			form[i].num = nn;
//			for (int j = 0; j < 2 * nn; j++)
//			{
//				cin >> temp;
//				if (j < nn)
//					form[i].left.insert(temp);
//				else
//					form[i].right.insert(temp);
//			}
//			cin >> op;
//			form[i].op = op;
//		}
//		for (int i = 0; i < k; i++)
//		{
//			if (form[i].op == '>')
//			{
//				for (int j = 1; j <= n; j++)
//				{
//					if (form[i].left.count(j) != 0 && coins[j] != 1)
//					{
//						if (coins[j] != 2)coins[j] = 3;
//						else coins[j] = 4;
//					}
//					else if (form[i].right.count(j) != 0 && coins[j] != 1)
//					{
//						if (coins[j] != 3)coins[j] = 2;
//						else coins[j] = 4;
//					}
//					else
//						coins[j] = 1;
//				}
//			}
//			else if (form[i].op == '<')
//			{
//				for (int j = 1; j <= n; j++)
//				{
//					if (form[i].left.count(j) != 0 && coins[j] != 1)
//					{
//						if (coins[j] != 3)coins[j] = 2;
//						else coins[j] = 4;
//					}
//					else if (form[i].right.count(j) != 0 && coins[j] != 1)
//					{
//						if (coins[j] != 2)coins[j] = 3;
//						else coins[j] = 4;
//					}
//					else
//						coins[j] = 1;
//				}
//			}
//			else
//			{
//				for (int j = 1; j <= n; j++)
//					if (form[i].left.count(j) != 0 || form[i].right.count(j) != 0)
//						coins[j] = 1;
//			}
//		}
//		bool flag = true;
//		for (int i = 1; flag && i <= n; i++)
//			if (coins[i] == 2 || coins[i] == 3 || coins[i] == 0)
//			{
//				if (answer == 0) answer = i;
//				else flag = false;
//			}
//		if (flag) cout << answer << endl;
//		else if (answer == 0)
//		{
//
//		}
//		else cout << "0" << endl;
//	}
//}

//???
#include<iostream>
#include<string.h>
using namespace std;
bool coin[100];
int Min[100];
int Max[100];
int N;
int K;
int main()
{
    while(cin>>N>>K)
    {
        memset(coin,false,sizeof(bool));
        memset(Min,0,sizeof(int));
        memset(Max,0,sizeof(int));

        int countNotEqual=0;
        for(int i=0; i<K; i++)
        {
            int count=0;
            cin>>count;
            int record[200];
            for(int j=0; j<count*2; j++)
                cin>>record[j];
            char oper;
            cin>>oper;
            if(oper=='=')
            {
                for(int j=0; j<count*2; j++)
                    coin[record[j]-1]=true;
            }
            else
            {
                countNotEqual++;
                if(oper=='<')
                {
                    for(int j=0; j<count; j++)
                        Min[record[j]-1]++;
                    for(int j=count; j<2*count; j++)
                        Max[record[j]-1]++;
                }
                else
                {

                    for(int j=0; j<count; j++)
                        Max[record[j]-1]++;
                    for(int j=count; j<2*count; j++)
                        Min[record[j]-1]++;
                }
            }
        }
        bool minexit=false;
        int minresult=0;
        int countOfMinResult=0;
        //找最小的
        for(int i=0; i<N; i++)
        {
            if(Min[i]==countNotEqual && !coin[i])
            {
                if(countOfMinResult==0)//第一个结果
                {
                    minresult=i+1;
                    countOfMinResult++;
                    minexit=true;
                }
                else
                {
                    minexit=false;
                    break;
                }

            }
        }
        bool maxexit=false;
        int maxresult=0;
        int countOfMaxResult=0;
        for(int i=0; i<N; i++)
        {
            if(Max[i]==countNotEqual && !coin[i])
            {
                if(countOfMaxResult==0)//第一个结果
                {
                    maxresult=i+1;
                    countOfMaxResult++;
                    maxexit=true;
                }
                else
                {
                    maxexit=false;
                    break;
                }

            }
        }
        int result=0;
        if((minexit && maxexit) || (!minexit && !maxexit))
            result=0;
        else
        {
            if(minexit)
                result=minresult;
            else
                result=maxresult;
        }

        if(result==0)
        {
            bool only=true;
            for(int i=0; i<N; i++)
            {
                if(!coin[i] )
                {
                    if(only)
                    {
                        result=i+1;
                        only=false;
                    }
                    else
                    {
                        result=0;
                        break;
                    }
                }
            }
        }
        cout<<result<<endl;
    }
}

//5 2
//1 1 4
//=
//1 2 5
//=
//---- 答案是 3 ----
//2 1
//1 1 2
//>
//---- 答案是 0 ----
//5 3
//2 1 3 2 4
//>
//2 3 5 2 4
//>
//1 1 4
//>
//---- 答案是 4 ----
//5 3
//1 2 3
//<
//1 1 2
//>
//1 3 4
//=
//---- 答案是 2 ----
//3 2
//1 1 2
//<
//1 1 3
//<
//---- 答案是 1 ----
//5 1
//2 1 2 3 4
//=
//---- 答案是 5 ----
//3 2
//1 1 2
//<
//1 2 3
//>
//---- 答案是 2 ----
//7 3
//2 1 2 3 4
//<
//2 1 5 3 4
//<
//3 3 4 1 7 6 5
//<
//
//正确输出 1
//4 3
//2 3 1 2 4
//<
//2 3 2 1 4
//<
//1 2 4
//=
//
//答案是 3
//6 4
//3 1 2 3 4 5 6
//<
//1 1 2
//=
//2 1 3 4 5
//<
//2 4 5 2 6
//>
//答案:0

//用三个数组
//bool normal[1024];
//bool light[1024];
//bool heavy[1204];
//来保存每一个硬币是 1 肯定没问题， 2 可能是轻的 3 可能是重的
//初始化都是false，代表我们什么都不知道
//
//对于每一次测验结果
//如果是平局，那么所有参与测验的硬币都肯定没问题
//如果是一边轻
//那么所有没参与测验的硬币都肯定没问题
//而轻的一边则可能是轻的，重的一边可能是重的
//这样从信息上没有漏掉任何信息
//
//最后遍历所有硬币
//if 他的normal[i]是true，他肯定没问题
//else if 他的light[i]和heavy[i]同时是true，他也肯定没问题，因为如果他是轻的或者重的，那么测验结果不可能暗示他既可能轻也可能重
//所以这样遍历之后，我们知道每个硬币是安全/不安全的
//如果不安全的硬币只有一个，输出之
//如果不安全的硬币大于1，输出0
//
//下面贴16MS代码，其实为了可读性麻烦了很多，完全应该0MS

//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//#include <iostream>
//#include <queue>
//#include <map>
//#include <vector>
//#include <math.h>
//#include <string>
//
//using namespace std;
//
//#define FOR(x,y) for(int x = 0;x < y;x++)
//#define MSET(x) memset(x,0,sizeof(x))
//
//class w// w类保存一次测验结果，提供两个接口验证一个硬币在不在这次测试的左边或者右边
//{
//public:
//    w()
//    {
//        MSET(l);
//        MSET(r);
//        n = 0;
//    }
//    int l[512];
//    int r[512];
//    bool InLeft(int i)
//    {
//        bool ret = false;
//        FOR(j,n)
//        {
//            if (l[j] == i)
//                return true;
//        }
//        return ret;
//    }
//    bool InRight(int i)
//    {
//        bool ret = false;
//        FOR(j,n)
//        {
//            if (r[j] == i)
//                return true;
//        }
//        return ret;
//    }
//    int n;
//    string res;
//};
//bool normal[1024];
//bool light[1024];
//bool heavy[1204];
//int main()
//{
//    int n,k;
//    while(cin>>n>>k)
//    {
//        MSET(normal);
//        MSET(light);
//        MSET(heavy);
//
//        w * tests = new w[k];
//        FOR(i,k)
//        {
//            cin>>tests[i].n;
//            FOR(j,tests[i].n)
//                cin>>tests[i].l[j];
//            FOR(j,tests[i].n)
//                cin>>tests[i].r[j];
//            cin>>tests[i].res;
//        }
//        FOR(i,k)
//        {
//            if (tests[i].res == "=")
//            {
//                for(int j = 1; j <= n; j++)
//                    if (tests[i].InLeft(j)||tests[i].InRight(j))
//                        normal[j] = true;
//            }
//            else if (tests[i].res == "<" || tests[i].res == ">")
//            {
//                for (int j = 1; j <= n; j++)
//                {
//                    if (tests[i].InLeft(j) == false && tests[i].InRight(j) == false)
//                        normal[j] = true;
//                    else if (tests[i].InLeft(j) && tests[i].res == "<")
//                        light[j] = true;
//                    else if (tests[i].InLeft(j) && tests[i].res == ">")
//                        heavy[j] = true;
//                    else if (tests[i].InRight(j) && tests[i].res == "<")
//                        heavy[j] = true;
//                    else if (tests[i].InRight(j) && tests[i].res == ">")
//                        light[j] = true;
//                }
//            }
//        }
//        int ret = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            if (!(normal[i] || (light[i] && heavy[i])))
//            {
//                if (ret == 0)
//                    ret = i;
//                else
//                {
//                    ret = 0;
//                    break;
//                }
//            }
//        }
//        printf("%d\n",ret);
//    }
//    return 0;
//}
