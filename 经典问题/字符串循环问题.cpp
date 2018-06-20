/** 给定一个字符串S[0...N - 1], 要求把S的前K个字符移动到S的尾部，
 * 如把字符串"abcdef"前面的 2 个字符'a', 'b'移动到字符的尾部
 * 得到新字符串"cdefab":即字符串循环左移k
 */
 // 算法要求：T(o) = O(n), S(o) = O(1)
 // (X'Y')' = YX (X'表示将X反转一次)
 // 如：abcdef
 // X = ab X' = ba
 // Y = cdef Y' = fedc
 // (X'Y')' = (bafedc)' = cdefab
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>

 using namespace std;

 char str[] = "abcdef";

 void ReverseString(char *s, int from, int to)
 {
     while(from < to)
     {
         char temp = s[from];
         s[from ++] = s[to];
         s[to --] = temp;
     }
 }

 void LeftRotateString(char *s, int n, int m)
 {
     m %= n;
     ReverseString(s, 0, m - 1);
     ReverseString(s, m, n - 1);
     ReverseString(s, 0, n - 1);
 }

 int main()
 {
     int size = sizeof(str) / sizeof(str[0]) - 1;
     int k = 2;
     puts(str);
     LeftRotateString(str, size, 2);
     puts(str);
     return 0;
 }
