// hdu 4300 Clairewd��s message
/**���⣺������һ����ĸ��ת������������ĵ�һ�е��ַ�����
  *����'a'ת�ɵ�һ����ĸ��'b'ת��ת����ĵڶ�����ĸ��������������
  *Ȼ������һ���ַ���������+���ĵ���ʽ���ַ�����
  *����˵ǰ���������ظ��ģ�ֻ����ͨ��ת����ת�����¡�
  *���Һ���һ�ο��ܲ�����,�����ǲ�������
  */
// ��ͨKMP��������ַ���Ϊs1����һ������s1ȫ������һ���ɣ�����+���ģ�
// ������ַ���Ϊs2���ڶ�����������s1�ĺ���Ϊ��������s2Ϊģʽ������kmp���ɡ�
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

// ��չKMP��������ַ���Ϊs1����һ������s1 �ĺ��η�����һ���ɣ�
// ������ַ���Ϊs2���ڶ�������s1Ϊ������s2Ϊģʽ������һ����չkmp���õ�extend���飻
// ����������extend�������һ��ɨ�裬�������ĳһλ�õĺ�׺��ģʽ����ǰ׺ȫ��ƥ�������ֹͣ��
// ��һλ�þ�����������Ž��ˡ�
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
//void get_extend(int len1, int len2)// S λ������ TΪģʽ��
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

// ��չKMP
// KMP�õ�����S[i-next[i]+1]..S[i]=T[0]..T[next[i]-1]��
// ����չKMP����˵S[i]..S[i+extend[i]-1]=T[0]..T[extend[i]-1]
// ��;: ��һ���ַ�����������Ӵ�����ظ��Ӵ���
/**�������� S ��ģʽ�� T ����S�ĳ���Ϊn��T �ĳ���Ϊm��
  *�� T �� S ��ÿһ����׺�������ǰ׺��
  *Ҳ����extend ���飬
  *extend[i] ��ʾ T �� S[i, n - 1]�������ǰ׺��Ҫ�������extend[i](0<=i<n)��S[k..po]==T[0..po-k]
  *��poΪĿǰS����ƥ�䵽����Զλ�ã�kΪ����ƥ�䵽��Զλ�õ�ֵ
  *k����0<=i0<i������i0ֵ�У�ʹi0+extend[i0]-1��ֵ����һ����poΪ������ֵ����k+extend[k]-1����
  *�����һ��λ��extend[i]=m,���ʾT��S�г��֣���������λ��i���֣�����Ǳ�׼��KMP����
  *�踨������next[i]��ʾT[i,m-1]��T�������ǰ׺���ȡ��Ե�iλ�ÿ�ʼ���Ӵ� �� T�Ĺ���ǰ׺, ����T[i..i+m-1]==T[0..m-1]������poֵ
  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

const int maxn = 100010; // �ַ������ȵ����ֵ
int next[maxn], extend[maxn];
char S[maxn], T[maxn];
// Ԥ��������next����
void get_next(int len)
{
    int i = 0,j;
    next[0] = len;// ��ʼ��next[0];
    while(T[i] == T[i + 1] && i + 1 < len)// ����next[1]
    i ++;
    next[1] = i;
    int po = 1; // ��ʼ�� po ��λ��
    for(i = 2; i < len; i ++)
    {
        // ��Զλ�� �� k = extend[po] + po - 1;po Ϊʹp��Զ��ֵ i(0 < i < x), L = next[i - po];
        if(next[i - po] + i < next[po] + po) // (i - 1) +  L < k, ֱ�ӿ��Եõ�next[i]��ֵ
            next[i] = next[i - po];
        else // (i - 1) + L >= k
        {
            j =  next[po] + po - i;
            if(j < 0) j = 0;// i > k,����Ҫ��ͷ��ʼƥ��
            while(i + j < len && T[j] == T[i + j])// ����next[i]
            j ++;
            next[i] = j;
            po = i;// ����po��λ��
        }
    }
}
// ����extend ����
void extend_KMP(int len_S, int len_T)
{
    int i = 0, j;
    // ����extend[0]
    while(T[i] == S[i] && i < len_S &&  i < len_T) i++;
    extend[0] = i;
    int po = 0; // ��ʼ��po��λ��
    // poλ�ã���ǰƥ������е������Զλ�ã� i + extend[i]�����ֵ
    for(i = 1; i < len_S; i ++)
    {
        // ��Զλ�� �� p = extend[po] + po - 1;po Ϊʹp��Զ��ֵ i(0 < i < x), L = next[i - po];
        if(next[i - po] + i < extend[po] + po) // (i - 1) + L < p, ֱ�ӿ��Եõ�extend[i]��ֵ
        extend[i] = next[i - po];
        else // (i - 1) + L >= p, Ҫ����ƥ����ܵõ�extend[i]��ֵ
        {
           j = extend[po] + po - i;// p - i + 1
           if(j < 0) j = 0; // ���i > p��Ҫ��ͷ��ʼƥ��
           while(i + j < len_S && j < len_T && S[i + j] == T[j]) // ����extend[i]
           j ++;
           extend[i] = j;
           po = i; // ����po ��λ��
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
