/** ����һ���ַ���S[0...N - 1], Ҫ���S��ǰK���ַ��ƶ���S��β����
 * ����ַ���"abcdef"ǰ��� 2 ���ַ�'a', 'b'�ƶ����ַ���β��
 * �õ����ַ���"cdefab":���ַ���ѭ������k
 */
 // �㷨Ҫ��T(o) = O(n), S(o) = O(1)
 // (X'Y')' = YX (X'��ʾ��X��תһ��)
 // �磺abcdef
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
