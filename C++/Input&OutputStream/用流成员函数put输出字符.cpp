#include<iostream>
using namespace std;
int main()
{
    cout.put(71).put(79).put(79).put(68).put('\n');

    char * p = "BASIC";//�ַ�ָ��ָ�� 'B'
    for(int i = 4; i >= 0; i--)
        cout.put(*(p + i));//�����һ���ַ����
    cout.put('\n');
    return 0;
}
