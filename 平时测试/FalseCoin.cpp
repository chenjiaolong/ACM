//#include<bits/stdc++.h>
//using namespace std;
//short Judge(int j,int *s,char c)
//{
//    //�����жϼ���j�Ž���Ǽٵ����������Ƿ�ì��
//    //s�ǳ�����¼�����һ��Ԫ��������ĸ���
//    //c �ǳ�����¼
//    int m = s[0] << 1;
//    bool f = true;
//    for(int i = 1; i <= m && f; )
//        if(s[i] == j)
//            f = false;
//        else
//            ++i;
//    //�жϱ��γ�����û��j�Ž�ҡ�
//    if(!f && c == '='|| f && c != '=')return 0;
//    //���j�Ž�Ҷ���ƽʧ�⣬��û��j�Ž�Ҷ���ƽ��ƽ�⣬�������ì��
//    return 1;
//}
//int main()
//{
//    int N,K;
//    while(scanf("%d%d",&N,&K) == 2)
//    {
//        int num[105][1010];
//        char s[105][5];//��������
//        for(int i = 0 ; i < K; ++i)
//        {
//            scanf("%d",&num[i][0]);
//            for(int j = 1; j <= 2 * num[i][0]; ++j)
//                scanf("%d",&num[i][j]);
//            scanf("%s",s[i]);
//        }
//        int no;
//        int t = 0,j;
//        for(int i = 1; i <= N; ++i)//�����������п���
//        {
//            for(j = 0; j < K && Judge(i,num[j],s[j][0]); ++j);
//            printf("SSSSSS %d\n",Judge(i,num[j],s[j][0]));
//            //�����еļ�¼���м��
//            if(j < K)
//                continue;
//            t++;
//            if(t > 1)
//                break;
//            no = i;
//        }//t�������ɶ���ĸ���
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
        //����С��
        for(int i=0; i<N; i++)
        {
            if(Min[i]==countNotEqual && !coin[i])
            {
                if(countOfMinResult==0)//��һ�����
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
                if(countOfMaxResult==0)//��һ�����
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
//---- ���� 3 ----
//2 1
//1 1 2
//>
//---- ���� 0 ----
//5 3
//2 1 3 2 4
//>
//2 3 5 2 4
//>
//1 1 4
//>
//---- ���� 4 ----
//5 3
//1 2 3
//<
//1 1 2
//>
//1 3 4
//=
//---- ���� 2 ----
//3 2
//1 1 2
//<
//1 1 3
//<
//---- ���� 1 ----
//5 1
//2 1 2 3 4
//=
//---- ���� 5 ----
//3 2
//1 1 2
//<
//1 2 3
//>
//---- ���� 2 ----
//7 3
//2 1 2 3 4
//<
//2 1 5 3 4
//<
//3 3 4 1 7 6 5
//<
//
//��ȷ��� 1
//4 3
//2 3 1 2 4
//<
//2 3 2 1 4
//<
//1 2 4
//=
//
//���� 3
//6 4
//3 1 2 3 4 5 6
//<
//1 1 2
//=
//2 1 3 4 5
//<
//2 4 5 2 6
//>
//��:0

//����������
//bool normal[1024];
//bool light[1024];
//bool heavy[1204];
//������ÿһ��Ӳ���� 1 �϶�û���⣬ 2 ��������� 3 �������ص�
//��ʼ������false����������ʲô����֪��
//
//����ÿһ�β�����
//�����ƽ�֣���ô���в�������Ӳ�Ҷ��϶�û����
//�����һ����
//��ô����û��������Ӳ�Ҷ��϶�û����
//�����һ�����������ģ��ص�һ�߿������ص�
//��������Ϣ��û��©���κ���Ϣ
//
//����������Ӳ��
//if ����normal[i]��true�����϶�û����
//else if ����light[i]��heavy[i]ͬʱ��true����Ҳ�϶�û���⣬��Ϊ���������Ļ����صģ���ô�����������ܰ�ʾ���ȿ�����Ҳ������
//������������֮������֪��ÿ��Ӳ���ǰ�ȫ/����ȫ��
//�������ȫ��Ӳ��ֻ��һ�������֮
//�������ȫ��Ӳ�Ҵ���1�����0
//
//������16MS���룬��ʵΪ�˿ɶ����鷳�˺ܶ࣬��ȫӦ��0MS

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
//class w// w�ౣ��һ�β��������ṩ�����ӿ���֤һ��Ӳ���ڲ�����β��Ե���߻����ұ�
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
