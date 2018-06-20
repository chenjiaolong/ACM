#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 3; // ��
const int maxm = 5; // ��

int main()
{
    // ָ�������ָ�롪����֪�ڶ�ά
    char (*p)[maxm] = (char (*)[maxm])malloc(sizeof(char *) * maxn);
    printf("sizeof(p) = %d, sizeof(p[0]) = %d\n", sizeof(p), sizeof(p[0]));
    printf("%d %d\n", &p[0][4], &p[1][0]);
    free(p);


    // ָ�����顪����֪��һά
    char *ps[maxn];
    for(int i = 0; i < maxn; i ++)
        ps[i] = (char *) malloc(sizeof(char) * maxm);
    printf("sizeof(ps) = %d, sizeof(ps[0]) = %d\n", sizeof(ps), sizeof(ps[0]));
    printf("%d %d\n", &ps[0][4], &ps[1][0]);
    for(int i = 0; i < maxn; i ++)
        free(ps[i]);


    // ָ�����顪����֪��һά��һ�η����ڴ�(��֤�ڴ��������)
    char *PS[maxn];
    PS[0] = (char *)malloc(sizeof(char) * maxn * maxm);
    for(int i = 1; i < maxn; i ++)
        PS[i] = PS[i - 1] + maxm;
    printf("sizeof(PS) = %d, sizeof(PS[0]) = %d\n", sizeof(PS), sizeof(PS[0]));
    printf("%d %d\n", &PS[0][4], &PS[1][0]);
    free(PS[0]);


    // ָ���ָ�롪����ά��δ֪
    char **pp = (char **)malloc(sizeof(char *) * maxn); // ����ָ������
    for(int i = 0;i < maxn; i ++)
        pp[i] = (char *) malloc(sizeof(char) * maxm); // ����ÿ��ָ����ָ�������
    printf("sizeof(pp) = %d, sizeof(pp[0]) = %d\n", sizeof(pp), sizeof(pp[0]));
    printf("%d %d\n", &pp[0][4], &pp[1][0]);
    for(int i = 0; i < maxn; i ++)
        free(pp[i]);
    free(pp);


    // ָ���ָ�롪����ά��δ֪��һ�η����ڴ�(��֤�ڴ��������)
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
