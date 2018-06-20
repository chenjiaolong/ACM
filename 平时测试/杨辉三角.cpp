//#include <cstdio>
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    int a[100][100];
//    while(scanf("%d",&n)!=EOF)
//    {
//        for(int i=0; i<n; i++)
//            for(int j=0; j<n; j++)
//                a[i][j]=0;
//        for(int i=0; i<n; i++)
//            for(int j=0; j<=i; j++)
//            {
//                a[i][j]=a[i-1][j]+a[i-1][j-1];
//                a[0][0]=1;
//                printf("%d%c",a[i][j],j==i?'\n':' ');
//            }
//    }
//    return 0;
//}

//#include<stdio.h>
//int main(void)
//{
//    int n;
//    while(scanf("%d",&n)!=EOF)
//    {
//        int a[n][n];
//        int i,j;
//        for(i=0; i<n; ++i)
//            for(j=0; j<=i; ++j)
//                a[i][j]=0;
//        for(i=0; i<n; ++i)
//            for(j=0; j<=i; ++j)
//                if(j==0 || i==j)
//                    a[i][j]=1;
//                else
//                    a[i][j]=a[i-1][j-1]+a[i-1][j];
//        for(i=0; i<n; ++i)
//            for(j=0; j<=i; ++j)
//                printf("%d%c",a[i][j],j==i?'\n':' ');
//    }
//    return 0;
//}

#include <stdio.h>
int main()
{
    int n,i,j,num[30][30]= {1,0};
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            num[i][0]=1;
        for(i=1; i<n; i++)
            for(j=1; j<=i; j++)
            {
                num[i][j]=num[i-1][j-1]+num[i-1][j];
                if(j==i)
                    num[i][j]=1;
            }
        for(i=0; i<n; i++)
            for(j=0; j<=i; j++)
                printf("%d%c",num[i][j],j==i?'\n':' ');
    }
    return 0;
}

//#include<stdio.h>
//int main()
//{
//    //freopen("test.out","w",stdout);
//    int array[1200];
//    int x;
//    while(scanf("%d",&x)!=EOF)
//    {
//        for(int i=1; i<=x; i++)
//            for(int j=1; j<=i; j++)
//                if(j==1||j==i)
//                    array[35*i+j]=1;
//                else
//                    array[35*i+j]=array[35*(i-1)+j]+array[35*(i-1)+(j-1)];
//        for(int i=1; i<=x; i++)
//            for(int j=1; j<=i; j++)
//                printf("%d%c",array[35*i+j],j==i?'\n':' ');
//        printf("\n");
//    }
//    return 0;
//}
