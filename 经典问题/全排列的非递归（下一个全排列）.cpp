// ��㣺�ֵ�����С��ȫ���У�����12345
// �յ㣺���� �ӵ�ǰ���������ֵ���պñ��������һ��ȫ����
// �磺21543����һ��������23145
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
// ��ת����
void Reverse(char *a, char *b)
{
    while(a < b)
        swap(a ++, b --);
}
// ��һ��ȫ����
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
        if(*p < *q) // �ӽ�������ڵ�2����ǰһ�������滻��
        {
            // �ӷ���ǰ�ұ��滻���ĵ�һ����
            pFind = pEnd;
            while(*pFind <= *p) --pFind;
            // �滻
            swap(pFind, p);
            // �滻������ȫ����ת
            Reverse(q, pEnd);
            return true;
        }
    }
    Reverse(p, pEnd);// û����һ��ȫ���� ��ȫ����ת�󷵻�true��
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
