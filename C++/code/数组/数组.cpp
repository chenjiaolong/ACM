#include <iostream>

using namespace std;

// CPP ���飬for(auto i : a) begin, end
// ����ͨ��begin��end��ȡ��ʼ��ַ��������ַ
int main()
{
    int arr[3][4];
    // CPP ֻ����һά���飬vector<vector<int>>;
    const char str[100] = "hello, world!";
    const char *p1 = begin(str); // ��Ԫ�ص�ַ
    const char *p2 = end(str); // ĩβ������ַ
    for(auto ib = begin(str), ie = end(str); ib != ie; ib ++)
        cout << *ib;
    puts("SSS");

    int a[5]{1, 2, 3, 4, 5};
    int *p3 = begin(a);
    int *p4 = end(a);
    for(int i = 0; i < 5; i ++)
        cout << a + i << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;

    return 0;
}
