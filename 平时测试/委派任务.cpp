#include<bits/stdc++.h>
#include<stdio.h>
int main()
{
    int i,j,k,l,m,n;
    for(i = 0; i <= 1; i ++)//穷举每个人是否去的所有情况
        for(j = 0; j <= 1; j ++)//1:去 0:不去
            for(k = 0; k <= 1; k ++)
                for(l = 0; l <= 1; l ++)
                    for(m = 0; m <= 1; m ++)
                        for(n = 0; n <= 1; n ++)
                            if((i + j >= 1) && (i + l <= 1)&&(i + m + n == 2) && (j + k == 0||j + k ==2) && (k + l == 1) && (l + m == 0||l ==1))
                            {
                                if( i == 1)
                                    printf("A,");
                                if( j == 1)
                                    printf("B,");
                                if( k == 1)
                                    printf("C,");
                                if( l == 1)
                                    printf("D,");
                                if( m == 1)
                                    printf("E,");
                                if( n == 1)
                                    printf("F,");
                            }
    return 0;
}
