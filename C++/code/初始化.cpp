#include <cstdlib>
#include <iostream>


using namespace std;

int main()
{
    int num(5);
    cout << num << endl;
    // char *p("calc");
    // system(p);
    // char str[10] {"calc"};
    // system(str);

    // L "ABCDEF": �������ĳ���
    wchar_t *wp(L "ABCDEF"); // ���ַ�

    int a[5]{1, 2, 3, 4, 5}; // �ַ�����������{}��ʼ������������()
    for (auto i : a) // �������еı���
        cout << i << endl;

    return 0;
}
