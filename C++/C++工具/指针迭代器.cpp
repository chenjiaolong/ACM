// ���ñ�׼ģ����find() ������������Ԫ��
#include<iostream>
#include<algorithm>

using namespace std;

const int size = 16;

int main()
{
    int a[size];
    for(int i = 0; i < size; i ++) a[i] = i;
    int key = 7;
    int *ip = find(a, a + size, key);
    if(ip == a + size) // ��Ҫʹ��NULL��ָ����ԣ�ָ��ʹ�ù�βֵ
        cout << key << " not found." << endl;
    else cout << key << " found." << endl;
	return 0;
}
