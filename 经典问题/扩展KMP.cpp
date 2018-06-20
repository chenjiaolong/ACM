// hdu 4300 Clairewd’s message
/**题意：首先有一个字母的转换表，就是输入的第一行的字符串，
  *就是'a'转成第一个字母，'b'转成转换表的第二个字母·······
  *然后下面一个字符串是密文+明文的形式的字符串。
  *就是说前后两段是重复的，只不过通过转换表转换了下。
  *而且后面一段可能不完整,让我们补完整。
  */
// 普通KMP：假设该字符串为s1，第一步：把s1全部翻译一遍变成：明文+密文，
// 假设该字符串为s2；第二步：我们以s1的后半段为主串，以s2为模式串进行kmp即可。
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//char S[maxn], T[maxn];
//char CT[30]; // Conversion Table
//int next[maxn];
//void get_next(int len)
//{
//    int i = 0, j = -1;
//    next[0] = -1;
//    while(i < len)
//    {
//        if(j == -1 || T[i] == T[j])
//        {
//            i ++;
//            j ++;
//            next[i] = j;
//        }
//        else
//            j = next[j];
//    }
//}
//int index_KMP(int len_T, int len_S)
//{
//    int i = 0, j = 0;
//    while(i < len_S && j < len_T)
//    {
//        if(j == - 1 || S[i] == T[j])
//        {
//            i ++;
//            j ++;
//            if(i == len_S) return j;
//        }
//        else j = next[j];
//    }
//    return 0;
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while(t--)
//    {
//        scanf("%s%s", CT, T);
//        int len_T = strlen(T);
//        strcpy(S, T + (len_T + 1) / 2);
//        //printf("%s",T);
//        for(int i = 0; i < len_T; i ++)
//            for(int j = 0; j < 26; j ++)
//                if(T[i] == CT[j])
//                {
//                    T[i] = j + 'a';
//                    break;
//                }
//        // puts(T);
//        get_next(len_T);
//        int len_S = strlen(S);
//        int index = index_KMP(len_T, len_S);
//        for(int i = index; i < len_T - index; i ++)
//            printf("%c", T[i]);
//        puts("");
//
//    }
//    return 0;
//}

// 扩展KMP：假设该字符串为s1，第一步：把s1 的后半段翻译译一遍变成：
// 假设该字符串为s2；第二步：以s1为主串，s2为模式串进行一次扩展kmp，得到extend数组；
// 第三步：对extend数组进行一次扫描，如果主串某一位置的后缀与模式串的前缀全部匹配就立即停止，
// 这一位置就是满足的最优解了。
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//char S[maxn], T[maxn];
//char CT[30]; // Conversion Table
//char MT[30]; // Message Table
//int next[maxn], extend[maxn];
//void get_next(int len)
//{
//    int i = 0;
//    next[0] = len;
//    while(i < len - 1 && T[i] == T[i - 1])
//        i ++;
//    next[1] = i;
//    int po = 1;
//    for(i = 2; i < len; i ++)
//    {
//        int p = po + next[po] - 1;
//        int L = next[i - po];
//        if(i + L - 1 >= p)
//        {
//            int j = p - i + 1 > 0 ? p - i + 1 : 0;
//            while(i + j < len && T[i + j] == T[j]) j ++;
//            next[i] = j;
//            po = i;
//        }
//        else next[i] = L;
//    }
//    // for(int i = 0; i < len; i ++)
//    // printf("%d ", next[i]);
//    // puts("");
//}
//void get_extend(int len1, int len2)// S 位主串， T为模式串
//{
//    get_next(len2);
//    int len = len1 > len2 ? len2 : len1;
//    int i = 0;
//    while(i < len && S[i] == T[i]) i ++;
//    extend[0] = i;
//    // printf("SSSSSS %d\n", i);
//    int po = 0;
//    for(i = 1; i < len1; i ++)
//    {
//        int p = po + extend[po] - 1;
//        int L = next[i - po];
//        if(i + L - 1 >= p)
//        {
//            int j = p - i + 1 > 0 ? p - i + 1 : 0;
//            while(i + j < len1 && j < len2 && S[i + j] == T[j]) j ++;
//            extend[i] = j;
//            po = i;
//        }
//        else
//            extend[i] = L;
//    }
//    // for(int i = 0; i < len1; i ++)
//    // printf("%d ", extend[i]);
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while(t--)
//    {
//        scanf("%s%s", CT, T);
//        for(int i = 0; i < 26; i ++)
//            MT[CT[i] - 'a'] = i + 'a';
//        int len_T = strlen(T);
//        int mid = (len_T + 1) / 2;
//        for(int i = mid; i < len_T; i ++)
//            S[i - mid] = CT[T[i] - 'a'];
//        S[len_T - mid] = '\0';
//        int len_S = strlen(S);
//        get_extend(len_S, len_T);
//        int max = -1;
//        for(int i=0; i < len_S; i++)
//            if(i + mid + extend[i] == len_T)
//            {
//                max = extend[i];
//                break;
//            }
//        printf("%s",T);
//        if(max == -1) max = 0;
//        for(int i = max; i<len_T - max; i++)
//            printf("%c",MT[T[i]-'a']);
//        printf("\n");
//    }
//    return 0;
//}

// 扩展KMP
// KMP得到的是S[i-next[i]+1]..S[i]=T[0]..T[next[i]-1]，
// 而扩展KMP则是说S[i]..S[i+extend[i]-1]=T[0]..T[extend[i]-1]
// 用途: 求一个字符串的最长回文子串和最长重复子串。
/**定义主串 S 和模式串 T ，设S的长度为n，T 的长度为m，
  *求 T 与 S 的每一个后缀的最长公共前缀，
  *也就是extend 数组，
  *extend[i] 表示 T 与 S[i, n - 1]的最长公共前缀，要求出所有extend[i](0<=i<n)。S[k..po]==T[0..po-k]
  *设po为目前S串中匹配到的最远位置，k为让其匹配到最远位置的值
  *k是在0<=i0<i的所有i0值中，使i0+extend[i0]-1的值最大的一个，po为这个最大值，即k+extend[k]-1），
  *如果有一个位置extend[i]=m,则表示T在S中出现，而且是在位置i出现，这就是标准的KMP问题
  *设辅助数组next[i]表示T[i,m-1]和T的最长公共前缀长度。以第i位置开始的子串 与 T的公共前缀, 满足T[i..i+m-1]==T[0..m-1]的最大的po值
  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

const int maxn = 100010; // 字符串长度的最大值
int next[maxn], extend[maxn];
char S[maxn], T[maxn];
// 预处理计算的next数组
void get_next(int len)
{
    int i = 0,j;
    next[0] = len;// 初始化next[0];
    while(T[i] == T[i + 1] && i + 1 < len)// 计算next[1]
    i ++;
    next[1] = i;
    int po = 1; // 初始化 po 的位置
    for(i = 2; i < len; i ++)
    {
        // 最远位置 ： k = extend[po] + po - 1;po 为使p最远的值 i(0 < i < x), L = next[i - po];
        if(next[i - po] + i < next[po] + po) // (i - 1) +  L < k, 直接可以得到next[i]的值
            next[i] = next[i - po];
        else // (i - 1) + L >= k
        {
            j =  next[po] + po - i;
            if(j < 0) j = 0;// i > k,则需要从头开始匹配
            while(i + j < len && T[j] == T[i + j])// 计算next[i]
            j ++;
            next[i] = j;
            po = i;// 更新po的位置
        }
    }
}
// 计算extend 数组
void extend_KMP(int len_S, int len_T)
{
    int i = 0, j;
    // 计算extend[0]
    while(T[i] == S[i] && i < len_S &&  i < len_T) i++;
    extend[0] = i;
    int po = 0; // 初始化po的位置
    // po位置：以前匹配过程中到达的最远位置， i + extend[i]的最大值
    for(i = 1; i < len_S; i ++)
    {
        // 最远位置 ： p = extend[po] + po - 1;po 为使p最远的值 i(0 < i < x), L = next[i - po];
        if(next[i - po] + i < extend[po] + po) // (i - 1) + L < p, 直接可以得到extend[i]的值
        extend[i] = next[i - po];
        else // (i - 1) + L >= p, 要继续匹配才能得到extend[i]的值
        {
           j = extend[po] + po - i;// p - i + 1
           if(j < 0) j = 0; // 如果i > p则要从头开始匹配
           while(i + j < len_S && j < len_T && S[i + j] == T[j]) // 计算extend[i]
           j ++;
           extend[i] = j;
           po = i; // 更新po 的位置
        }
    }
}
int main()
{
    while(scanf("%s%s", S, T) != EOF)
    {
        int len_S = strlen(S);
        int len_T = strlen(T);
        get_next(len_T);
        for(int i = 0; i < len_T; i ++)
            printf("%d%c", next[i], i == len_T - 1 ? '\n' : ' ');
        extend_KMP(len_S, len_T);
        for(int i = 0; i < len_S; i ++)
            printf("%d%c", extend[i], i == len_S - 1 ? '\n' : ' ');
    }
    return 0;
}
//abcabcabc
//abc
//aaaabaa
//aaaaa
//aaaaaaaab
//aaaaaaaac
//aaaaaaaaaabaaa
//aaaaaaaaaaa

// hdu 4333 Revolving Digits
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//const int maxn = 5e5 + 100;
//char S[maxn], T[maxn];
//int next[maxn], extend[maxn], nextval[maxn];
//
//void get_next(int len)
//{
//    int i = 0;
//    next[0] = len;
//    while(i + 1 < len && T[i] == T[i + 1]) i ++;
//    next[1] = i;
//    int po = 1;
//    for(int i = 2; i < len; i ++)
//    {
//        int p = po + next[po] - 1, L = next[i - po];
//        if((i - 1) + L >= p)
//        {
//            int j = (p - i + 1) > 0 ? p - i + 1 : 0;
//            while(i + j < len && T[j] == T[i + j]) j ++;
//            next[i] = j;
//            po = i;
//        }
//        else next[i] = L;
//    }
//}
//void get_extend(int len_T, int len_S)
//{
//    int i = 0;
//    int mini = len_T < len_S ? len_T : len_S;
//    while(i < mini && S[i] == T[i]) i++;
//    extend[0] = i;
//    int po = 0;
//    for(int i = 1; i < len_S; i ++)
//    {
//        int p = po + extend[po] - 1, L = next[i - po];
//        if((i - 1) + L >= p)
//        {
//            int j = (p - i + 1) > 0 ? p - i + 1 : 0;
//            while(i + j < len_S && j < len_T && S[i + j] == T[j]) j ++;
//            extend[i] = j;
//            po = i;
//        }
//        else extend[i] = L;
//    }
//}
//void get_nextval(int len)
//{
//    int i = 0;
//    int j = -1;
//    nextval[0] = -1;
//    while(i < len)
//    {
//        if(j == -1 || T[i] == T[j])
//        {
//            i ++;
//            j ++;
//            if(T[i] != T[j]) nextval[i] = j;
//            else nextval[i] = nextval[j];
//        }
//        else j = nextval[j];
//    }
//}
//int main()
//{
//    int tt;
//    scanf("%d", &tt);
//    for(int t = 1; t <= tt; t ++)
//    {
//        scanf("%s", S);
//        strcpy(T, S);
//        strcat(S, T);
//        int len_S = strlen(S);
//        int len_T = strlen(T);
//        get_next(len_T);
//        get_extend(len_T, len_S);
//        get_nextval(len_T);
//        int MOD = len_T - nextval[len_T];
//        int temp = 1;
//        if(len_T % MOD == 0) temp = len_T / MOD;
//        int less = 0, equal = 0, more = 0;
//        for(int i = 0; i < len_T; i ++)
//        {
//            if(extend[i] >= len_T) equal ++;
//            else if(S[i + extend[i]] < T[extend[i]]) less ++;
//            else more ++;
//        }
//        printf("Case %d: %d %d %d\n",t,less/temp,equal/temp,more/temp);
//    }
//    return 0;
//}
