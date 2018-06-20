#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
#define N 10000000
int main(int argc, const char *argv[])
{
    int *phi;
    char *prime;
    prime = (char *)malloc((N + 1) * sizeof(char));
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= N; i ++)
        prime[i] = 1;
    for(int i = 2; i * i <= N; i ++)
        if(prime[i])
        for(int j = i * i; j <= N; j += i)
        prime[j] = 0;
    // �������� N �ڵ���������

    phi = (int *)malloc((N + 1) * sizeof(int));
    for(int i = 1; i <= N; i ++)
        phi[i] = i;
    for(int i = 2; i <= N; i ++)
        if(prime[i])
        for(int j = i; j <= N; j += i)
        phi[j] = phi[j] / i * (i - 1);// �˴�ע���� / i �� * (i - 1), ����Χ�ϴ�ʱ�����
    // �������� N ����������ŷ������ֵ

    for(int i = 1; i <= 100; i ++)
        cout << i << " " << phi[i] << endl;

    return 0;
}
