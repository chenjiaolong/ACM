// ֱ�ӵݹ鷨
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int a[] = {1, 2, 3, 4, 5};
//int size = sizeof(a) / sizeof(int);
//int sum = 10;// sumΪ����ĺ�
//
//void Print(bool *x)
//{
//    for(int i = 0; i < size; i ++)
//        if(x[i]) printf("%d ", a[i]);
//    puts("");
//}
//// x[] Ϊ���ս�, i Ϊ����ĵ�x[i]�Ƿ���룬 has��ʾ��ǰ�ĺ�
//void EnumNumber(bool *x, int i, int has)
//{
//    if(i >= size) return ;
//    if(has + a[i] == sum)
//    {
//        x[i] = true;
//        Print(x);
//        x[i] = false;
//    }
//    x[i] = true;
//    EnumNumber(x, i + 1, has + a[i]);
//    x[i] = false;
//    EnumNumber(x, i + 1, has);
//}
//
//int main()
//{
//    bool *x = new bool[size];
//    memset(x, 0, size);
//    EnumNumber(x, 0, 0);
//    delete[]x;
//    return 0;
//}

// ��֦��������
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//int size = sizeof(a) / sizeof(int);
//int sum = 40;// sumΪ����ĺ�
//int Case = 1;
//int Sum(int *a, int size)
//{
//    int s = 0;
//    for(int i = 0; i < size; i ++)
//        s = s + a[i];
//    return s;
//}
//void Print(bool *x)
//{
//    printf("%d: ", Case ++);
//    for(int i = 0; i < size; i ++)
//        if(x[i]) printf("%d ", a[i]);
//    puts("");
//}
//// x[] Ϊ���ս�, i Ϊ����ĵ�x[i]�Ƿ���룬 has��ʾ��ǰ�ĺ�
//// residue ��ʣ������ȫ����
//void FindNumber(bool *x, int i, int has, int residue)
//{
//    if(i >= size) return ;
//    if(has + a[i] == sum)
//    {
//        x[i] = true;
//        Print(x);
//        x[i] = false;
//    }
//    else if(has + residue >= sum && has + a[i] <= sum)
//    {
//        x[i] = true;
//        FindNumber(x, i + 1, has + a[i], residue - a[i]);
//    }
//    if(has + residue - a[i] >= sum)
//    {
//        x[i] = false;
//        FindNumber(x, i + 1, has, residue - a[i]);
//    }
//}
//
//int main()
//{
//    int residue = Sum(a, size);
//    bool *x = new bool[size];
//    memset(x, 0, size);
//    FindNumber(x, 0, 0, residue);
//    delete[]x;
//    return 0;
//}

// ���ڸ���������
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int a[] = {-3, -5, -2, 4, 2, 1, 3};
int size = sizeof(a) / sizeof(int);
int sum = 5;// sumΪ����ĺ�
int Case = 1;
void Sum(int *a, int size, int &negative, int &positive)
{
    for(int i = 0; i < size; i ++)
    {
        if(a[i] < 0) negative += a[i];
        else positive += a[i];
    }
}
void Print(bool *x)
{
    printf("%d: ", Case ++);
    for(int i = 0; i < size; i ++)
        if(x[i]) printf("%d ", a[i]);
    puts("");
}
// x[] Ϊ���ս�, i Ϊ����ĵ�x[i]�Ƿ���룬 has��ʾ��ǰ�ĺ�
// residue ��ʣ������������ĺ�
void FindNumber(bool *x, int i, int has, int negative, int positive)
{
    if(i >= size) return ;
    if(has + a[i] == sum)
    {
        x[i] = true;
        Print(x);
        x[i] = false;
    }
    if(a[i] >= 0)
    {
        if(has + positive >= sum && has + a[i] <= sum)
        {
            x[i] = true;
            FindNumber(x, i + 1, has + a[i], negative, positive - a[i]);
            x[i] = false;
        }
        if(has + positive - a[i] >= sum)
        {
            x[i] = false;
            FindNumber(x, i + 1, has, negative, positive - a[i]);
        }
    }
    else
    {
        if(has + x[i] + positive >= sum)
        {
            x[i] = true;
            FindNumber(x, i + 1, has + a[i], negative - a[i], positive);
            x[i] = false;
        }
        if(has + negative <= sum && has + positive >= sum)
        {
            x[i] = false;
            FindNumber(x, i + 1, has, negative - a[i], positive);
        }
    }
}

int main()
{
    int negative = 0, positive = 0;
    Sum(a, size, negative, positive);
    printf("%d %d\n", negative, positive);
    bool *x = new bool[size];
    memset(x, 0, size);
    FindNumber(x, 0, 0, negative, positive);
    delete[]x;
    return 0;
}

