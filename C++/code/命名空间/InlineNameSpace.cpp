#include <iostream>

using namespace std;
// ������̵��ٲ�ģ�ͺ͵���ʽ����
namespace all
{
    namespace V2014
    {
        void fun(int num)
        {
            cout << "int " << " V2014" << endl;
        }
    }
}
namespace all
{
    // inline չ����all��Ĭ�ϵİ汾
    inline namespace V2015
    {
        void fun(int num)
        {
            cout << "int " << " V2015" << endl;
        }
        void fun(double num)
        {
            cout << "double " << " V2015" << endl;
        }
    }
}
int main()
{
    all :: V2014 :: fun(1); // ��ȷ����һ���汾
    all :: V2015 :: fun(1);
    all :: fun(1.0); // ָ��Ĭ�ϰ汾
    return 0;
}
