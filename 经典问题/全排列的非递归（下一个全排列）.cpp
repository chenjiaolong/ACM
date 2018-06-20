// 起点：字典序最小的全排列，例如12345
// 终点：过程 从当前排列生成字典序刚好比它大的下一个全排列
// 如：21543的下一个排列是23145
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

char str[] = "926520";

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
// 反转区间
void Reverse(char *a, char *b)
{
    while(a < b)
        swap(a ++, b --);
}
// 下一个全排列
bool Next_permutation(char a[])
{
    char *pEnd = a + strlen(a);
    if(a == pEnd) return false;
    char *p, *q, *pFind;
    pEnd --;
    p = pEnd;
    while(p != a)
    {
        q = p;
        --p;
        if(*p < *q) // 从降序的相邻的2数，前一个数即替换数
        {
            // 从反向前找比替换点大的第一个数
            pFind = pEnd;
            while(*pFind <= *p) --pFind;
            // 替换
            swap(pFind, p);
            // 替换点后的数全部反转
            Reverse(q, pEnd);
            return true;
        }
    }
    Reverse(p, pEnd);// 没有下一个全排列 ，全部反转后返回true；
    return false;

}
int main()
{
    puts(str);
    if(Next_permutation(str))// if(next_permutation(str, str + 6))
    puts(str);
    else puts("Oh, no!");
    return 0;
}
