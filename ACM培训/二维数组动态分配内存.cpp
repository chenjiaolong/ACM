#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 3; // 行
const int maxm = 5; // 列

int main()
{
    // 指向数组的指针——已知第二维
    char (*p)[maxm] = (char (*)[maxm])malloc(sizeof(char *) * maxn);
    printf("sizeof(p) = %d, sizeof(p[0]) = %d\n", sizeof(p), sizeof(p[0]));
    printf("%d %d\n", &p[0][4], &p[1][0]);
    free(p);


    // 指针数组——已知第一维
    char *ps[maxn];
    for(int i = 0; i < maxn; i ++)
        ps[i] = (char *) malloc(sizeof(char) * maxm);
    printf("sizeof(ps) = %d, sizeof(ps[0]) = %d\n", sizeof(ps), sizeof(ps[0]));
    printf("%d %d\n", &ps[0][4], &ps[1][0]);
    for(int i = 0; i < maxn; i ++)
        free(ps[i]);


    // 指针数组——已知第一维，一次分配内存(保证内存的连续性)
    char *PS[maxn];
    PS[0] = (char *)malloc(sizeof(char) * maxn * maxm);
    for(int i = 1; i < maxn; i ++)
        PS[i] = PS[i - 1] + maxm;
    printf("sizeof(PS) = %d, sizeof(PS[0]) = %d\n", sizeof(PS), sizeof(PS[0]));
    printf("%d %d\n", &PS[0][4], &PS[1][0]);
    free(PS[0]);


    // 指针的指针——两维都未知
    char **pp = (char **)malloc(sizeof(char *) * maxn); // 分配指针数组
    for(int i = 0;i < maxn; i ++)
        pp[i] = (char *) malloc(sizeof(char) * maxm); // 分配每个指针所指向的数组
    printf("sizeof(pp) = %d, sizeof(pp[0]) = %d\n", sizeof(pp), sizeof(pp[0]));
    printf("%d %d\n", &pp[0][4], &pp[1][0]);
    for(int i = 0; i < maxn; i ++)
        free(pp[i]);
    free(pp);


    // 指针的指针——两维都未知，一次分配内存(保证内存的连续性)
    char **PP = (char **)malloc(sizeof(char *) * maxn);
    PP[0] = (char *)malloc(sizeof(char) * maxn * maxm);
    for(int i = 1; i < maxn; i ++)
        PP[i] = PP[i - 1] + maxm;
    printf("sizeof(PP) = %d, sizeof(PP[0]) = %d\n", sizeof(PP), sizeof(PP[0]));
    printf("%d %d\n", &PP[0][4], &PP[1][0]);
    free(PP[0]);
    free(PP);
    return 0;
}
