//ҫ���Ǯ����͵��
#include<bits/stdc++.h>
int main()
{
    int m;
    while(~scanf("%d",&m))
    {
        int ans = log2(m) + 1;
        printf("%d\n",ans);
    }
    return 0;
}

//Բ����Բ������
//#include<bits/stdc++.h>
//int main()
//{
//    long long n;
//    while(~scanf("%lld",&n))
//    {
//        long long ans = ((sqrt(5) - 1)/ 2) * (n + 1);
//        printf("%lld\n",ans);
//    }
//
//    return 0;
//}

// ҫ�������壬˭�����㣿
//#include<stdio.h>
//int main()
//{
//    int n,m;
//    while(~scanf("%d%d",&n,&m))
//    {
//        if(n % ( m + 1) != 0)
//            printf("first\n");
//        else
//            printf("second\n");
//    }
//    return 0;
//}
