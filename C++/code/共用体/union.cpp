#include <iostream>

using namespace std;
// CPP�����壬���Գ�ʼ�����ڲ������к������������ʱ����Ҫunion�ؼ���
// �����壬�����ڴ棬���������ȥ��С
union u
{
    int num = 10;
    double db;
    void go()
    {
        cout << "SSS" << endl;
    }
};

int main()
{
    cout << sizeof(u) << endl;
    u *ptr(nullptr);
    ptr -> go();
    return 0;
}
