//Master-Mind Hints
//���������к��û��µ����У�ͳ���ж�������λ����ȷ��A��
//�ж����������������ж����ֹ���λ�ò��ԣ�B����
//��������������ݡ�ÿ�������һ��Ϊ���еĳ���n���ڶ����Ǵ����У������������ɲ²����С�
//�²�����ȫΪ0ʱ�������ݽ�����n = 0ʱ���������
#include<stdio.h>
#include<algorithm>
#define maxn 1010
using namespace std;
int main()
{
    //freopen("test.out","w",stdout);
    int n,answer[maxn],guess[maxn];
    int kase = 0;
    while(scanf("%d",&n) == 1 && n)
    {
        printf("Game %d:\n",++kase);
        for(int i = 0; i < n; i++)
            scanf("%d",&answer[i]);
        while(1)
        {
            int A = 0,B = 0;
            for(int i = 0; i < n; i++)
            {
                scanf("%d",&guess[i]);
                if(answer[i] == guess[i])
                    A++;
            }
            if(guess[0] == 0)
                break;
            for(int d = 1; d <= 9; d++)
            {
                int c1 = 0,c2 = 0;
                for(int i = 0; i < n; i++)
                {
                    if(answer[i] == d)
                        c1++;
                    if(guess[i] == d)
                        c2++;
                }
                B += min(c1,c2);
            }
            printf("    (%d,%d)\n",A,B-A);
        }
    }
    return 0;
}

//��������
//4
//1 3 5 5
//1 1 2 3
//4 3 3 5
//6 5 5 1
//6 1 3 5
//1 3 5 5
//0 0 0 0
//
//10
//1 2 2 2 4 5 6 6 6 9
//1 2 3 4 5 6 7 8 9 1
//1 1 2 2 3 3 4 4 5 5
//1 2 1 3 1 5 1 6 1 9
//1 2 2 5 5 5 6 6 6 7
//0 0 0 0 0 0 0 0 0 0
//0

//�������
//Game 1:
//    (1,1)
//    (2,0)
//    (1,2)
//    (1,2)
//    (4,0)
//Game 2:
//    (2,4)
//    (3,2)
//    (5,0)
//    (7,0)
