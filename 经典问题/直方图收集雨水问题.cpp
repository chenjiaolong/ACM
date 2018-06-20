#include<stdio.h>
#include<iostream>
using namespace std;
int TrappingRianWater(int A[], int n)
{
    int secHeight = 0; // 当前找到的第二大的数
    int left = 0;
    int right = n - 1;
    int trap = 0; // 依次遍历每个方柱能装水的容量
    while(left < right)
    {
        if(A[left] < A[right])
        {
            secHeight = max(A[left], secHeight);
            trap += (secHeight - A[left]);
            left++;
        }
        else
        {
            secHeight = max(A[right], secHeight);
            trap += (secHeight - A[right]);
            right--;
        }
    }
    return trap;
}
int main()
{
    int array[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(array) / sizeof(int);
    // printf("%d\n", size);
    int trap = TrappingRianWater(array, size);
    printf("%d\n",trap);
    return 0;
}
// 样例
// 6, 3, 2, 0, 3, 2, 0, 1, 5, 6, 4, 3, 7, 5, 4, 0, 3, 2, 5, 8, 2, 4
// 62
