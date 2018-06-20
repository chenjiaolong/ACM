#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

void Holland(int *a, int length)
{
    int begin = 0;
    int cur= 0;
    int end = length - 1;
    while(cur <= end)
    {
        if(a[cur] == 2)
        {
            swap(a[end], a[cur]);
            end--;
        }
        else if(a[cur] == 1) cur ++;
        else
        {
            // 1. 或者用更直接的判断if(a[cur] != a[begin]);
            // 2. 因为不等的次数远远大于相等的次数，可以直接删除去该判断
            if(cur != begin) swap(a[cur], a[begin]);
            begin ++;
            cur ++;
        }
    }
}

int main()
{
    int a[] = {1, 0, 2, 2, 0, 1, 0, 1, 2};
    int size = sizeof(a) / sizeof(int);
    Holland(a, size);
    for(int i = 0; i < size; i ++)
        printf("%d%c", a[i], i == size - 1? '\n' : ' ');
    return 0;
}
