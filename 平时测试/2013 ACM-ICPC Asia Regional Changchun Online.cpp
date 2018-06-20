// hdu 4763 Theme Section : KMP
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 1e6 + 100;
//char pattern[maxn], text[maxn];
//int nextval[maxn];
//// 另类求next[]数组
//void get_next(int len)
//{
//    int i = 1, j;
//    nextval[0] = nextval[1] = 0;
//    while(i < len)
//    {
//        j = nextval[i];
//        while(j && pattern[i] != pattern[j]) j = nextval[j];
//        nextval[i + 1] = pattern[i] == pattern[j] ? j + 1 : 0;
//        i ++;
//    }
////    for(i = 1; i <= len; i ++)
////        printf("%d%c", next[i], i == len ? '\n' : ' ');
//}
//bool KMP(char *text, char *pattern, int len_S, int len_T)
//{
//    int i = 0, j = 0;
//    while(i < len_S)
//    {
//        while(j && pattern[j] != text[i])
//            j = nextval[j];
//        if(pattern[j] == text[i]) j ++;
//        if(j == len_T) return true;
//        i ++;
//    }
//    return false;
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    while(T--)
//    {
//        scanf("%s", pattern);
//        int len_T = strlen(pattern);
//        get_next(len_T);
//        int ans = 0;
//        int j = nextval[len_T];
//        while(j)
//        {
//            if(len_T >= 3 * j && KMP(pattern + j, pattern, len_T - 2 * j, j))
//            {
//                ans = j;// j 即为长度
//                break;
//            }
//            j = nextval[j];
//        }
//        printf("%d\n", ans);
//    }
//    return 0;
//}

// 扩展KMP
// 在一个位置i中，如果要满足要求，子串的最大长度不能超过 min(i,  nextval[i], (len - i) / 2);
// 所有的最大长度的最大值就是可能存在的最大长度
// 最后对后三分之一的位置，看nextval[i]是否不超过这个最大长度，如果没超过，则该nextval[i]即为所求，跳出循环即可
// 注意到我们枚举到后三分一的位置时，如果某个位置为i，
// 且nextval[i]+ i == len。
// 也就是子串的长度为nextval[i]了
// 由于对一个位置开始的子串的最大长度不能超过 (len - i)/2
// 那么很显然中间的那个串是不可能与后边的串有重叠的
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int maxn = 1e6 + 100;
char sa[maxn];
int nextval[maxn], extend[maxn];
void pre_ExtendKMP(char x[], int m)
{
    int ind = 0, k = 1;
    nextval[0] = m;
    while(ind + 1 < m && x[ind + 1] == x[ind]) ind ++;
    nextval[1] = ind;
    for(int i = 2; i < m; i ++)
    {
        if(i <= k + nextval[k] - 1 && nextval[i - k] + i < k + nextval[k])
            nextval[i] = nextval[i - k];
        else
        {
            ind = max(0, k + nextval[k] - i);
            while(ind + i < m && x[ind + i] == x[ind]) ind++;
            nextval[i] = ind, k = i;
        }
    }
}
//void ExtendKMP(char x[], int m, char y[], int n)
//{
//    // pre_ExtendKMP(x, m);
//    int ind = 0, k = 0;
//    while(ind < n && ind < m && x[ind] == y[ind]) ind ++;
//    extend[0] = ind;
//    for(int i = 1; i < n; i ++)
//    {
//        if(i < k + extend[k] - 1 && next[i - k] + i < k + extend[k])
//            extend[i] = next[i - k];
//        else
//        {
//            ind = max(0, k + extend[k] - i);
//            while(ind + i < n && ind < m && y[ind + i] == x[ind]) ind++;
//            extend[i] = ind;
//            k = i;
//        }
//    }
//}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", sa);
        int len = strlen(sa);
        pre_ExtendKMP(sa, len);
        int ans = 0;
        int lst = len - len / 3, maxlen;
        for(int i = 0; i < len; i ++)
        {
            maxlen = min(i, nextval[i]);
            maxlen = min(maxlen, (len - i) / 2);
            ans = max(ans, maxlen);
        }
        int res = 0;
        for(int i = lst; i < len; i ++)
        {
            if(nextval[i] + i != len) continue;
            if(ans >= nextval[i])
            {
                res = nextval[i];
                break;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
