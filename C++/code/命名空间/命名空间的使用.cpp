#include <cstdlib>
#include <iostream>

using namespace std;

namespace string1
{
    char str[10]{"calc"};
}
namespace string2
{
    char str[10]{"notepad"};
}
// �����ռ���չ��������ͬ��ζ��ͬһ�������ռ�
// �ٲ�ʽ����
namespace string2
{
    char cmd[10]{"mspaint"};
    void show()
    {
        cout << cmd << endl;
    }
}

// �����ռ䣬��������Ƕ��
namespace run
{
    namespace runit
    {
        namespace runitout
        {
            int num = 100;
            void show()
            {
                cout << num << endl;
            }
        }
    }
}

int main()
{
    system(string1 :: str);
    system(string2 :: str);
    system(string2 :: cmd);
    string2 :: show(); // �����ռ��ĺ��������

    run :: runit :: runitout :: num = 199;
    run :: runit :: runitout :: show();

    return 0;
}
